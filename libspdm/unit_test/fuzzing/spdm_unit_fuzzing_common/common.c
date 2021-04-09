/**
@file
UEFI OS based application.

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "spdm_unit_fuzzing.h"

spdm_test_context_t       *m_spdm_test_context;

spdm_test_context_t *
get_spdm_test_context (
  void
  )
{
  return m_spdm_test_context;
}

void
setup_spdm_test_context (
  IN spdm_test_context_t       *spdm_test_context
  )
{
  m_spdm_test_context = spdm_test_context;
}

uintn spdm_unit_test_group_setup(void **State)
{
  spdm_test_context_t       *spdm_test_context;
  void                    *spdm_context;

  spdm_test_context = m_spdm_test_context;
  spdm_test_context->spdm_context = (void *)malloc (spdm_get_context_size());
  if (spdm_test_context->spdm_context == NULL) {
    return (uintn)-1;
  }
  spdm_context = spdm_test_context->spdm_context;

  spdm_init_context (spdm_context);
  spdm_register_device_io_func (spdm_context, spdm_test_context->send_message, spdm_test_context->receive_message);
  spdm_register_transport_layer_func (spdm_context, spdm_transport_test_encode_message, spdm_transport_test_decode_message);

  *State = spdm_test_context;
  return 0;
}

uintn spdm_unit_test_group_teardown(void **State)
{
  spdm_test_context_t       *spdm_test_context;

  spdm_test_context = *State;
  free (spdm_test_context->spdm_context);
  spdm_test_context->spdm_context = NULL;
  return 0;
}
