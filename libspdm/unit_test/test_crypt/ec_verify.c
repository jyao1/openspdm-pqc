/** @file
  Application for Elliptic Curve Primitives Validation.

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "test_crypt.h"

/**
  Validate Crypto EC Interfaces.

  @retval  RETURN_SUCCESS  Validation succeeded.
  @retval  RETURN_ABORTED  Validation failed.

**/
return_status
validate_crypt_ec (
  void
  )
{
  void    *ec1;
  void    *ec2;
  uint8   public1[66 * 2];
  uintn   public1_length;
  uint8   public2[66 * 2];
  uintn   public2_length;
  uint8   key1[32];
  uintn   key1_length;
  uint8   key2[32];
  uintn   key2_length;
  uint8   hash_value[SHA256_DIGEST_SIZE];
  uintn   hash_size;
  uint8   signature[66 * 2];
  uintn   sig_size;
  boolean status;

  my_print ("\nCrypto EC-DH key Exchange Testing:\n");

  //
  // Initialize key length
  //
  public1_length  = sizeof (public1);
  public2_length  = sizeof (public2);
  key1_length     = sizeof (key1);
  key2_length     = sizeof (key2);

  //
  // Generate & Initialize EC context
  //
  my_print ("- Context1 ... ");
  ec1 = ec_new_by_nid (CRYPTO_NID_SECP256R1);
  if (ec1 == NULL) {
    my_print ("[Fail]");
    return RETURN_ABORTED;
  }

  my_print ("Context2 ... ");
  ec2 = ec_new_by_nid (CRYPTO_NID_SECP256R1);
  if (ec2 == NULL) {
    my_print ("[Fail]");
    ec_free (ec1);
    return RETURN_ABORTED;
  }

  //
  // Verify EC-DH
  //
  my_print ("Generate key1 ... ");
  status = ec_generate_key (ec1, public1, &public1_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("Generate key2 ... ");
  status = ec_generate_key (ec2, public2, &public2_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("Compute key1 ... ");
  status = ec_compute_key (ec1, public2, public2_length, key1, &key1_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("Compute key2 ... ");
  status = ec_compute_key (ec2, public1, public1_length, key2, &key2_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("Compare Keys ... ");
  if (key1_length != key2_length) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  if (compare_mem (key1, key2, key1_length) != 0) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  } else {
    my_print ("[Pass]\n");
  }

  ec_free (ec1);
  ec_free (ec2);

  my_print ("\nCrypto EC-DSA Signing Verification Testing:\n");

  public1_length  = sizeof (public1);
  public2_length  = sizeof (public2);

  my_print ("- Context1 ... ");
  ec1 = ec_new_by_nid (CRYPTO_NID_SECP256R1);
  if (ec1 == NULL) {
    my_print ("[Fail]");
    return RETURN_ABORTED;
  }

  my_print ("Context2 ... ");
  ec2 = ec_new_by_nid (CRYPTO_NID_SECP521R1);
  if (ec2 == NULL) {
    my_print ("[Fail]");
    ec_free (ec1);
    return RETURN_ABORTED;
  }

  my_print ("Compute key1 ... ");
  status = ec_generate_key (ec1, public1, &public1_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("Compute key2 ... ");
  status = ec_generate_key (ec2, public2, &public2_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  //
  // Verify EC-DSA
  //
  hash_size = sizeof(hash_value);
  sig_size = sizeof(signature);
  my_print ("\n- EC-DSA Signing ... ");
  status  = ecdsa_sign (ec1, CRYPTO_NID_SHA256, hash_value, hash_size, signature, &sig_size);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("EC-DSA Verification ... ");
  status = ecdsa_verify (ec1, CRYPTO_NID_SHA256, hash_value, hash_size, signature, sig_size);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  } else {
    my_print ("[Pass]\n");
  }

  hash_size = sizeof(hash_value);
  sig_size = sizeof(signature);
  my_print ("- EC-DSA Signing ... ");
  status  = ecdsa_sign (ec2, CRYPTO_NID_SHA256, hash_value, hash_size, signature, &sig_size);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("EC-DSA Verification ... ");
  status = ecdsa_verify (ec2, CRYPTO_NID_SHA256, hash_value, hash_size, signature, sig_size);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  } else {
    my_print ("[Pass]\n");
  }

  ec_free (ec1);
  ec_free (ec2);

  my_print ("\nCrypto EC-DSA Signing Verification Testing with SetPubKey:\n");

  public1_length  = sizeof (public1);
  public2_length  = sizeof (public2);

  my_print ("- Context1 ... ");
  ec1 = ec_new_by_nid (CRYPTO_NID_SECP256R1);
  if (ec1 == NULL) {
    my_print ("[Fail]");
    return RETURN_ABORTED;
  }

  my_print ("Context2 ... ");
  ec2 = ec_new_by_nid (CRYPTO_NID_SECP256R1);
  if (ec2 == NULL) {
    my_print ("[Fail]");
    ec_free (ec1);
    return RETURN_ABORTED;
  }

  my_print ("Compute key in Context1 ... ");
  status = ec_generate_key (ec1, public1, &public1_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("Export key in Context1 ... ");
  status = ec_get_pub_key (ec1, public2, &public2_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("Import key in Context2 ... ");
  status = ec_set_pub_key (ec2, public2, public2_length);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  //
  // Verify EC-DSA
  //
  hash_size = sizeof(hash_value);
  sig_size = sizeof(signature);
  my_print ("\n- EC-DSA Signing in Context1 ... ");
  status  = ecdsa_sign (ec1, CRYPTO_NID_SHA256, hash_value, hash_size, signature, &sig_size);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  }

  my_print ("EC-DSA Verification in Context2 ... ");
  status = ecdsa_verify (ec2, CRYPTO_NID_SHA256, hash_value, hash_size, signature, sig_size);
  if (!status) {
    my_print ("[Fail]");
    ec_free (ec1);
    ec_free (ec2);
    return RETURN_ABORTED;
  } else {
    my_print ("[Pass]\n");
  }

  ec_free (ec1);
  ec_free (ec2);

  return RETURN_SUCCESS;
}