/** @file
  HMAC-SHA256 KDF Wrapper Implementation over OpenSSL.

  RFC 5869: HMAC-based Extract-and-Expand key Derivation Function (HKDF)

Copyright (c) 2018 - 2019, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "internal_crypt_lib.h"

/**
  Derive SHA256 HMAC-based Extract-and-Expand key Derivation Function (HKDF).

  @param[in]   key              Pointer to the user-supplied key.
  @param[in]   key_size          key size in bytes.
  @param[in]   salt             Pointer to the salt(non-secret) value.
  @param[in]   salt_size         salt size in bytes.
  @param[in]   info             Pointer to the application specific info.
  @param[in]   info_size         info size in bytes.
  @param[out]  out              Pointer to buffer to receive hkdf value.
  @param[in]   out_size          size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha256_extract_and_expand (
  IN   const uint8  *key,
  IN   uintn        key_size,
  IN   const uint8  *salt,
  IN   uintn        salt_size,
  IN   const uint8  *info,
  IN   uintn        info_size,
  OUT  uint8        *out,
  IN   uintn        out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA256 HMAC-based Extract key Derivation Function (HKDF).

  @param[in]   key              Pointer to the user-supplied key.
  @param[in]   key_size          key size in bytes.
  @param[in]   salt             Pointer to the salt(non-secret) value.
  @param[in]   salt_size         salt size in bytes.
  @param[out]  prk_out           Pointer to buffer to receive hkdf value.
  @param[in]   prk_out_size       size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha256_extract (
  IN   const uint8  *key,
  IN   uintn        key_size,
  IN   const uint8  *salt,
  IN   uintn        salt_size,
  OUT  uint8        *prk_out,
  IN   uintn        prk_out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA256 HMAC-based Expand key Derivation Function (HKDF).

  @param[in]   prk              Pointer to the user-supplied key.
  @param[in]   prk_size          key size in bytes.
  @param[in]   info             Pointer to the application specific info.
  @param[in]   info_size         info size in bytes.
  @param[out]  out              Pointer to buffer to receive hkdf value.
  @param[in]   out_size          size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha256_expand (
  IN   const uint8  *prk,
  IN   uintn        prk_size,
  IN   const uint8  *info,
  IN   uintn        info_size,
  OUT  uint8        *out,
  IN   uintn        out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA384 HMAC-based Extract-and-Expand key Derivation Function (HKDF).

  @param[in]   key              Pointer to the user-supplied key.
  @param[in]   key_size          key size in bytes.
  @param[in]   salt             Pointer to the salt(non-secret) value.
  @param[in]   salt_size         salt size in bytes.
  @param[in]   info             Pointer to the application specific info.
  @param[in]   info_size         info size in bytes.
  @param[out]  out              Pointer to buffer to receive hkdf value.
  @param[in]   out_size          size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha384_extract_and_expand (
  IN   const uint8  *key,
  IN   uintn        key_size,
  IN   const uint8  *salt,
  IN   uintn        salt_size,
  IN   const uint8  *info,
  IN   uintn        info_size,
  OUT  uint8        *out,
  IN   uintn        out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA384 HMAC-based Extract key Derivation Function (HKDF).

  @param[in]   key              Pointer to the user-supplied key.
  @param[in]   key_size          key size in bytes.
  @param[in]   salt             Pointer to the salt(non-secret) value.
  @param[in]   salt_size         salt size in bytes.
  @param[out]  prk_out           Pointer to buffer to receive hkdf value.
  @param[in]   prk_out_size       size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha384_extract (
  IN   const uint8  *key,
  IN   uintn        key_size,
  IN   const uint8  *salt,
  IN   uintn        salt_size,
  OUT  uint8        *prk_out,
  IN   uintn        prk_out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA384 HMAC-based Expand key Derivation Function (HKDF).

  @param[in]   prk              Pointer to the user-supplied key.
  @param[in]   prk_size          key size in bytes.
  @param[in]   info             Pointer to the application specific info.
  @param[in]   info_size         info size in bytes.
  @param[out]  out              Pointer to buffer to receive hkdf value.
  @param[in]   out_size          size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha384_expand (
  IN   const uint8  *prk,
  IN   uintn        prk_size,
  IN   const uint8  *info,
  IN   uintn        info_size,
  OUT  uint8        *out,
  IN   uintn        out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA512 HMAC-based Extract-and-Expand key Derivation Function (HKDF).

  @param[in]   key              Pointer to the user-supplied key.
  @param[in]   key_size          key size in bytes.
  @param[in]   salt             Pointer to the salt(non-secret) value.
  @param[in]   salt_size         salt size in bytes.
  @param[in]   info             Pointer to the application specific info.
  @param[in]   info_size         info size in bytes.
  @param[out]  out              Pointer to buffer to receive hkdf value.
  @param[in]   out_size          size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha512_extract_and_expand (
  IN   const uint8  *key,
  IN   uintn        key_size,
  IN   const uint8  *salt,
  IN   uintn        salt_size,
  IN   const uint8  *info,
  IN   uintn        info_size,
  OUT  uint8        *out,
  IN   uintn        out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA512 HMAC-based Extract key Derivation Function (HKDF).

  @param[in]   key              Pointer to the user-supplied key.
  @param[in]   key_size          key size in bytes.
  @param[in]   salt             Pointer to the salt(non-secret) value.
  @param[in]   salt_size         salt size in bytes.
  @param[out]  prk_out           Pointer to buffer to receive hkdf value.
  @param[in]   prk_out_size       size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha512_extract (
  IN   const uint8  *key,
  IN   uintn        key_size,
  IN   const uint8  *salt,
  IN   uintn        salt_size,
  OUT  uint8        *prk_out,
  IN   uintn        prk_out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}

/**
  Derive SHA512 HMAC-based Expand key Derivation Function (HKDF).

  @param[in]   prk              Pointer to the user-supplied key.
  @param[in]   prk_size          key size in bytes.
  @param[in]   info             Pointer to the application specific info.
  @param[in]   info_size         info size in bytes.
  @param[out]  out              Pointer to buffer to receive hkdf value.
  @param[in]   out_size          size of hkdf bytes to generate.

  @retval TRUE   Hkdf generated successfully.
  @retval FALSE  Hkdf generation failed.

**/
boolean
hkdf_sha512_expand (
  IN   const uint8  *prk,
  IN   uintn        prk_size,
  IN   const uint8  *info,
  IN   uintn        info_size,
  OUT  uint8        *out,
  IN   uintn        out_size
  )
{
  ASSERT(FALSE);
  return FALSE;
}