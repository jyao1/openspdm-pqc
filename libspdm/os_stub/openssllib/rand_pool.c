/** @file
  OpenSSL_1_1_1b doesn't implement rand_pool_* functions for UEFI.
  The file implement these functions.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "crypto/rand.h"
#include <openssl/aes.h>

#include <base.h>
#include <library/rnglib.h>

/**
  Calls RandomNumber64 to fill
  a buffer of arbitrary size with random bytes.
  This is a shim layer to rnglib.

  @param[in]   length        size of the buffer, in bytes,  to fill with.
  @param[out]  RandBuffer    Pointer to the buffer to store the random result.

  @retval TRUE        Random bytes generation succeeded.
  @retval FALSE       Failed to request random bytes.

**/
static
boolean
RandGetBytes (
  IN uintn         length,
  OUT uint8       *RandBuffer
  )
{
  boolean     ret;
  uint64      temp_rand;

  ret = FALSE;

  if (RandBuffer == NULL) {
    DEBUG((DEBUG_ERROR, "[OPENSSL_RAND_POOL] NULL RandBuffer. No random numbers are generated and your system is not secure\n"));
    ASSERT (RandBuffer != NULL); // Since we can't generate random numbers, we should assert. Otherwise we will just blow up later.
    return ret;
  }


  while (length > 0) {
    // Use rnglib to get random number
    ret = get_random_number_64 (&temp_rand);

    if (!ret) {
      return ret;
    }
    if (length >= sizeof (temp_rand)) {
      *((uint64*) RandBuffer) = temp_rand;
      RandBuffer += sizeof (uint64);
      length -= sizeof (temp_rand);
    }
    else {
      copy_mem (RandBuffer, &temp_rand, length);
      length = 0;
    }
  }

  return ret;
}

/*
 * Add random bytes to the pool to acquire requested amount of entropy
 *
 * This function is platform specific and tries to acquire the requested
 * amount of entropy by polling platform specific entropy sources.
 *
 * This is OpenSSL required interface.
 */
size_t
rand_pool_acquire_entropy (
  RAND_POOL *pool
  )
{
  boolean        ret;
  size_t         Bytes_needed;
  unsigned char *buffer;

  Bytes_needed = rand_pool_bytes_needed (pool, 1 /*entropy_factor*/);
  if (Bytes_needed > 0) {
    buffer = rand_pool_add_begin (pool, Bytes_needed);

    if (buffer != NULL) {
      ret = RandGetBytes (Bytes_needed, buffer);
      if (FALSE == ret) {
        rand_pool_add_end (pool, 0, 0);
      }
      else {
        rand_pool_add_end (pool, Bytes_needed, 8 * Bytes_needed);
      }
    }
  }

  return rand_pool_entropy_available (pool);
}

/*
 * Implementation for UEFI
 *
 * This is OpenSSL required interface.
 */
int
rand_pool_add_nonce_data (
  RAND_POOL *pool
  )
{
  uint8 data[16];
  RandGetBytes (sizeof(data), data);

  return rand_pool_add (pool, (unsigned char*)&data, sizeof(data), 0);
}

/*
 * Implementation for UEFI
 *
 * This is OpenSSL required interface.
 */
int
rand_pool_add_additional_data (
  RAND_POOL *pool
  )
{
  uint8 data[16];
  RandGetBytes (sizeof(data), data);

  return rand_pool_add (pool, (unsigned char*)&data, sizeof(data), 0);
}

/*
 * Dummy Implementation for UEFI
 *
 * This is OpenSSL required interface.
 */
int
rand_pool_init (
  void
  )
{
  return 1;
}

/*
 * Dummy Implementation for UEFI
 *
 * This is OpenSSL required interface.
 */
void
rand_pool_cleanup(
  void
  )
{
}

/*
 * Dummy Implementation for UEFI
 *
 * This is OpenSSL required interface.
 */
void
rand_pool_keep_random_devices_open (
  int keep
  )
{
}
