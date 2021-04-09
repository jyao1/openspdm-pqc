/** @file  
  Application for Pseudorandom Number generator Validation.

Copyright (c) 2010, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "test_crypt.h"

#define  RANDOM_NUMBER_SIZE  256

const  uint8  m_seed_string[] = "This is the random seed for PRNG verification.";

uint8  m_previous_random_buffer[RANDOM_NUMBER_SIZE] = { 0x0 };

uint8  m_random_buffer[RANDOM_NUMBER_SIZE] = { 0x0 };

/**
  Validate Crypto pseudorandom number generator interfaces.

  @retval  RETURN_SUCCESS  Validation succeeded.
  @retval  RETURN_ABORTED  Validation failed.

**/
return_status
validate_crypt_prng (
  void
  )
{
  uintn    index;
  boolean  status;

  my_print (" \nCrypto PRNG Engine Testing:\n");

  my_print ("- Random Generation...");

  status = random_seed (m_seed_string, sizeof (m_seed_string));
  if (!status) {
    my_print ("[Fail]");
    return RETURN_ABORTED;
  }

  for (index = 0; index < 10; index ++) {
    status = random_bytes (m_random_buffer, RANDOM_NUMBER_SIZE);
    if (!status) {
      my_print ("[Fail]");
      return RETURN_ABORTED;
    }

    if (compare_mem (m_previous_random_buffer, m_random_buffer, RANDOM_NUMBER_SIZE) == 0) {
      my_print ("[Fail]");
      return RETURN_ABORTED;
    }

    copy_mem (m_previous_random_buffer, m_random_buffer, RANDOM_NUMBER_SIZE);
  }

  my_print ("[Pass]\n");

  return RETURN_SUCCESS;

}
