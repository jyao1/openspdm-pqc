/** @file
  Definitions of DSP0277 Secured Messages using SPDM Specification
  version 1.0.0 in Distributed Management Task Force (DMTF).

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __SPDM_SECURED_MESSAGE_H__
#define __SPDM_SECURED_MESSAGE_H__

#pragma pack(1)

//
// ENC+AUTH session:
//
// +-----------------+
// | ApplicationData |-----------------------------------------------------
// +-----------------+                                                     |
//                                                                         V
// +---------------------------------+--------------------------=-------+-------+------+---+
// |SPDM_SECURED_MESSAGE_ADATA_HEADER|spdm_secured_message_cipher_header_t|AppData|Random|MAC|
// | session_id | SeqNum (O) | length |       application_data_length      |       |  (O) |   |
// +---------------------------------+----------------------------------+-------+------+---+
// |                                 |                                                 |   |
//  --------------------------------- ------------------------------------------------- ---
//                  |                                         |                          |
//                  V                                         V                          V
//            AssociatedData                            encrypted_data                 AeadTag
//
// (O) means Optional or Transport Layer Specific.
//
// AUTH session:
//
// +-----------------+
// | ApplicationData |------------------
// +-----------------+                  |
//                                      V
// +---------------------------------+-------+---+
// |SPDM_SECURED_MESSAGE_ADATA_HEADER|AppData|MAC|
// | session_id | SeqNum (T) | length |       |   |
// +---------------------------------+-------+---+
// |                                         |   |
//  ----------------------------------------- ---
//                      |                     |
//                      V                     V
//                AssociatedData           AeadTag
//

typedef struct {
  uint32   session_id;
} spdm_secured_message_a_data_header1_t;

// The length of sequence_number between HEADER_1 and HEADER_2 is transport specific.

typedef struct {
  uint16   length; // The length of the remaining data, including application_data_length(O), payload, Random(O) and MAC.
} spdm_secured_message_a_data_header2_t;

typedef struct {
  uint16   application_data_length; // The length of the payload
} spdm_secured_message_cipher_header_t;

//
// Secured Messages opaque data format
//
#define SECURED_MESSAGE_OPAQUE_DATA_SPEC_ID  0x444D5446
#define SECURED_MESSAGE_OPAQUE_VERSION       0x1

typedef struct {
  uint32   spec_id;        // SECURED_MESSAGE_OPAQUE_DATA_SPEC_ID
  uint8    opaque_version; // SECURED_MESSAGE_OPAQUE_VERSION
  uint8    total_elements;
  uint16   reserved;
//opaque_element_table_t  opaque_list[];
} secured_message_general_opaque_data_table_header_t;

typedef struct {
  uint8    id;
  uint8    vendor_len;
//uint8    vendor_id[vendor_len];
//uint16   opaque_element_data_len;
//uint8    opaque_element_data[opaque_element_data_len];
//uint8    align_padding[];
} opaque_element_table_header_t;

#define SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_DATA_VERSION  0x1

typedef struct {
  uint8    id; // SPDM_REGISTRY_ID_DMTF
  uint8    vendor_len;
  uint16   opaque_element_data_len;
//uint8    sm_data_version;
//uint8    sm_data_id;
//uint8    sm_data[];
} secured_message_opaque_element_table_header_t;

typedef struct {
  uint8                 sm_data_version; // SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_DATA_VERSION
  uint8                 sm_data_id;      // SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_ID_VERSION_SELECTION
} secured_message_opaque_element_header_t;

#define SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_ID_VERSION_SELECTION  0x0

typedef struct {
  uint8                 sm_data_version; // SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_DATA_VERSION
  uint8                 sm_data_id;      // SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_ID_VERSION_SELECTION
  spdm_version_number_t   selected_version;
} secured_message_opaque_element_version_selection_t;

#define SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_ID_SUPPORTED_VERSION  0x1

typedef struct {
  uint8                 sm_data_version; // SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_DATA_VERSION
  uint8                 sm_data_id;      // SECURED_MESSAGE_OPAQUE_ELEMENT_SMDATA_ID_SUPPORTED_VERSION
  uint8                 version_count;
//spdm_version_number_t   versions_list[version_count];
} secured_message_opaque_element_supported_version_t;

#pragma pack()

#endif
