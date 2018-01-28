// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file contains common input and result values use to verify the NTLM
// implementation. They are defined in [MS-NLMP] Section 4.2 [1].
//
// [MS-NLMP] has no test data for Extended Protection for Authentication (EPA).
// Test vectors related to EPA (aka Channel Binding) have been taken from
// a Microsoft blog post [2].
//
// [1] https://msdn.microsoft.com/en-us/library/cc236621.aspx
// [2] https://blogs.msdn.microsoft.com/openspecification/2013/03/26/ntlm-and-
//         channel-binding-hash-aka-extended-protection-for-authentication/

#ifndef NET_BASE_NTLM_TEST_DATA_H_
#define NET_BASE_NTLM_TEST_DATA_H_

#include "net/ntlm/ntlm_constants.h"

namespace net {
namespace ntlm {
namespace test {

// Common input values defined in [MS-NLMP] Section 4.2.1.
constexpr base::char16 kPassword[] = {'P', 'a', 's', 's', 'w',
                                      'o', 'r', 'd', '\0'};
constexpr base::char16 kNtlmDomain[] = {'D', 'o', 'm', 'a', 'i', 'n', '\0'};
constexpr uint8_t kNtlmDomainRaw[] = {'D', 0x00, 'o', 0x00, 'm', 0x00,
                                      'a', 0x00, 'i', 0x00, 'n', 0x00};
constexpr base::char16 kUser[] = {'U', 's', 'e', 'r', '\0'};
constexpr base::char16 kDomainUserCombined[] = {'D',  'o', 'm', 'a', 'i', 'n',
                                                '\\', 'U', 's', 'e', 'r', '\0'};
constexpr base::char16 kHostname[] = {'C', 'O', 'M', 'P', 'U',
                                      'T', 'E', 'R', '\0'};
constexpr base::char16 kServer[] = {'S', 'e', 'r', 'v', 'e', 'r', '\0'};
constexpr uint8_t kServerRaw[] = {'S', 0x00, 'e', 0x00, 'r', 0x00,
                                  'v', 0x00, 'e', 0x00, 'r', 0x00};

// ASCII Versions of the above strings.
constexpr char kNtlmDomainAscii[] = "Domain";
constexpr char kUserAscii[] = "User";
constexpr char kHostnameAscii[] = "COMPUTER";

// Test data obtained from [2].
constexpr char kChannelBindings[] = {
    't',  'l',  's',  '-',  's',  'e',  'r',  'v',  'e',  'r',  '-',
    'e',  'n',  'd',  '-',  'p',  'o',  'i',  'n',  't',  ':',  0xea,
    0x05, 0xfe, 0xfe, 0xcc, 0x6b, 0x0b, 0xd5, 0x71, 0xdb, 0xbc, 0x5b,
    0xaa, 0x3e, 0xd4, 0x53, 0x86, 0xd0, 0x44, 0x68, 0x35, 0xf7, 0xb7,
    0x4c, 0x85, 0x62, 0x1b, 0x99, 0x83, 0x47, 0x5f, 0x95, '\0'};

constexpr char kNtlmSpn[] = {'H', 'T', 'T', 'P', '/', 'S',
                             'e', 'r', 'v', 'e', 'r', '\0'};
constexpr uint8_t kNtlmSpnRaw[] = {'H', 0x00, 'T', 0x00, 'T', 0x00, 'P', 0x00,
                                   '/', 0x00, 'S', 0x00, 'e', 0x00, 'r', 0x00,
                                   'v', 0x00, 'e', 0x00, 'r', 0x00};

// Input value defined in [MS-NLMP] Section 4.2.1.
constexpr uint64_t kServerTimestamp = 0;

// Arbitrary value for client timestamp. The spec does not provide test data
// or scenarios involving the client timestamp. The relevant thing is that it
// is not equal to |kServerTimestamp| so it can be determined which timestamp
// is within the message.
// Tue, 23 May 2017 20:13:07 +0000
constexpr uint64_t kClientTimestamp = 131400439870000000;

// Challenge vectors defined in [MS-NLMP] Section 4.2.1.
constexpr uint8_t kServerChallenge[kChallengeLen] = {0x01, 0x23, 0x45, 0x67,
                                                     0x89, 0xab, 0xcd, 0xef};
constexpr uint8_t kClientChallenge[kChallengeLen] = {0xaa, 0xaa, 0xaa, 0xaa,
                                                     0xaa, 0xaa, 0xaa, 0xaa};

// Test input defined in [MS-NLMP] Section 4.2.3.3.
constexpr uint8_t kChallengeMsgV1[] = {
    0x4e, 0x54, 0x4c, 0x4d, 0x53, 0x53, 0x50, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x0c, 0x00, 0x38, 0x00, 0x00, 0x00, 0x33, 0x82, 0x0a, 0x82,
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x70, 0x17, 0x00, 0x00, 0x00, 0x0f, 0x53, 0x00, 0x65, 0x00,
    0x72, 0x00, 0x76, 0x00, 0x65, 0x00, 0x72, 0x00};

// Test input defined in [MS-NLMP] Section 4.2.4.3.
constexpr uint8_t kChallengeMsgFromSpecV2[] = {
    0x4e, 0x54, 0x4c, 0x4d, 0x53, 0x53, 0x50, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x0c, 0x00, 0x38, 0x00, 0x00, 0x00, 0x33, 0x82, 0x8a, 0xe2,
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x24, 0x00, 0x44, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x70, 0x17, 0x00, 0x00, 0x00, 0x0f, 0x53, 0x00, 0x65, 0x00,
    0x72, 0x00, 0x76, 0x00, 0x65, 0x00, 0x72, 0x00, 0x02, 0x00, 0x0c, 0x00,
    0x44, 0x00, 0x6f, 0x00, 0x6d, 0x00, 0x61, 0x00, 0x69, 0x00, 0x6e, 0x00,
    0x01, 0x00, 0x0c, 0x00, 0x53, 0x00, 0x65, 0x00, 0x72, 0x00, 0x76, 0x00,
    0x65, 0x00, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00,
};

// A minimal challenge message for tests. For NTLMv1 this implementation only
// reads the smallest required version of the message (32 bytes). Some
// servers may still send messages this small. The only relevant flags
// that affect behavior are that both NTLMSSP_NEGOTIATE_UNICODE and
// NTLMSSP_NEGOTIATE_EXTENDED_SESSIONSECURITY are set.
//
// [0-7]    - "NTLMSSP\0"                        (Signature)
// [9-11]   - |MessageType::kChallenge|          (Message Type = 0x00000002)
// [12-19]  - |SecBuf(kNegotiateMessageLen, 0)|  (Target Name - Not Used)
// [20-23]  - |kNegotiateMessageFlags|           (Flags = 0x00088207)
// [24-31]  - |kServerChallenge|                 (Server Challenge)
//
// See [MS-NLMP] Section 2.2.2.2 for more information about the Challenge
// message.
constexpr uint8_t kMinChallengeMessage[kChallengeHeaderLen] = {
    'N',  'T',  'L',  'M',  'S',  'S',  'P',  '\0', 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x07, 0x82,
    0x08, 0x00, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};

// The same message as |kMinChallengeMessage| but with the
// NTLMSSP_NEGOTIATE_UNICODE flag cleared.
constexpr uint8_t kMinChallengeMessageNoUnicode[kChallengeHeaderLen] = {
    'N',  'T',  'L',  'M',  'S',  'S',  'P',  '\0', 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x06, 0x82,
    0x08, 0x00, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};

// The same message as |kMinChallengeMessage| but with the
// NTLMSSP_NEGOTIATE_EXTENDED_SESSIONSECURITY flag cleared.
constexpr uint8_t kMinChallengeMessageNoSS[kChallengeHeaderLen] = {
    'N',  'T',  'L',  'M',  'S',  'S',  'P',  '\0', 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x07, 0x82,
    0x00, 0x00, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};

// Test result value for NTOWFv1() defined in [MS-NLMP] Section 4.2.2.1.2.
constexpr uint8_t kExpectedNtlmHashV1[kNtlmHashLen] = {
    0xa4, 0xf4, 0x9c, 0x40, 0x65, 0x10, 0xbd, 0xca,
    0xb6, 0x82, 0x4e, 0xe7, 0xc3, 0x0f, 0xd8, 0x52};

// Test result value for NTOWFv2() defined in [MS-NLMP] Section 4.2.4.1.1.
constexpr uint8_t kExpectedNtlmHashV2[kNtlmHashLen] = {
    0x0c, 0x86, 0x8a, 0x40, 0x3b, 0xfd, 0x7a, 0x93,
    0xa3, 0x00, 0x1e, 0xf2, 0x2e, 0xf0, 0x2e, 0x3f};

// Test result value defined in [MS-NLMP] Section 4.2.2.1.
constexpr uint8_t kExpectedNtlmResponseV1[kResponseLenV1] = {
    0x67, 0xc4, 0x30, 0x11, 0xf3, 0x02, 0x98, 0xa2, 0xad, 0x35, 0xec, 0xe6,
    0x4f, 0x16, 0x33, 0x1c, 0x44, 0xbd, 0xbe, 0xd9, 0x27, 0x84, 0x1f, 0x94};

// Test result value defined in [MS-NLMP] Section 4.2.3.2.2.
constexpr uint8_t kExpectedNtlmResponseWithV1SS[kResponseLenV1] = {
    0x75, 0x37, 0xf8, 0x03, 0xae, 0x36, 0x71, 0x28, 0xca, 0x45, 0x82, 0x04,
    0xbd, 0xe7, 0xca, 0xf8, 0x1e, 0x97, 0xed, 0x26, 0x83, 0x26, 0x72, 0x32};

// Test result value defined in [MS-NLMP] Section 4.2.3.2.1.
constexpr uint8_t kExpectedLmResponseWithV1SS[kResponseLenV1] = {
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// Test result value defined in [MS-NLMP] Section 4.2.4.1.3.
//
// "temp" is defined in Section 3.3.2 and is part of the data to be hashed
// to generate the NTLMv2 Proof. It is composed of 3 parts;
//
// 1) [0-27] A fixed length part in the first 28 (|kProofInputLenV2|) bytes
// which in this implementation is generated by |GenerateProofInputV2|.
//
// 2) [28-63] A variable length part which the spec calls "ServerName" but
// defines as the AV Pairs (aka Target Information) from the Authenticate
// message. See |kExpectedTargetInfoFromSpecV2| for more information.
//
// 3) [64-68] 4 zero bytes.
//
// NOTE: The timestamp (bytes [8-15]) should not actually be 0 here. In order
// to use the test data from the spec some lower level tests do generate this
// value. The target info sent by the server does not contain a timestamp
// AvPair, and section 3.1.5.1.2 states that the client should populate the
// timestamp with the servers timestamp if it exists, otherwise with the
// client's local time. For end to end tests the alternate value
// |kExpectedTempWithClientTimestampV2| below is used for end to end tests.
// Having different test data for the server and client time allows testing
// the logic more correctly.
constexpr uint8_t kExpectedTempFromSpecV2[] = {
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x00, 0x44, 0x00, 0x6f, 0x00,
    0x6d, 0x00, 0x61, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x01, 0x00, 0x0c, 0x00,
    0x53, 0x00, 0x65, 0x00, 0x72, 0x00, 0x76, 0x00, 0x65, 0x00, 0x72, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// This value is the same as |kExpectedTempFromSpecV2| but with the timestamp
// field at bytes [8-15] populated with |kClientTimestamp|.
constexpr uint8_t kExpectedTempWithClientTimestampV2[] = {
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0b, 0xc8, 0xfd,
    0x00, 0xd4, 0xd2, 0x01, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x00, 0x44, 0x00, 0x6f, 0x00,
    0x6d, 0x00, 0x61, 0x00, 0x69, 0x00, 0x6e, 0x00, 0x01, 0x00, 0x0c, 0x00,
    0x53, 0x00, 0x65, 0x00, 0x72, 0x00, 0x76, 0x00, 0x65, 0x00, 0x72, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// Test result value defined (indirectly) in [MS-NLMP] Section 4.2.4.
//
// This is part 2 (bytes [28-63]) of |kExpectedTempFromSpecV2|. Additional
// notes;
//
// a) The spec defines the AV Pairs to be in the opposite order to which they
//    actually appear in the output in Section 4.2.4.1.3.
//
// b) The implicit presence of a terminating AV Pair is not mentioned.
//
// c) Section 4.2.4 does not show the byte sequences of the AV Pair Headers.
//
// NOTE: The real implementation in default settings would not have such a
// simple set of AV Pairs since a flags field to indicate the presence of a
// MIC, and a channel bindings field would also have been added.
constexpr uint8_t kExpectedTargetInfoFromSpecV2[] = {
    0x02, 0x00, 0x0c, 0x00, 0x44, 0x00, 0x6f, 0x00, 0x6d, 0x00, 0x61, 0x00,
    0x69, 0x00, 0x6e, 0x00, 0x01, 0x00, 0x0c, 0x00, 0x53, 0x00, 0x65, 0x00,
    0x72, 0x00, 0x76, 0x00, 0x65, 0x00, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00};

// This target info is to test the behavior when a server timestamp is
// present. It is the same as |kExpectedTargetInfoFromSpecV2| but with
// an additional timestamp AvPair.
constexpr uint8_t kExpectedTargetInfoFromSpecPlusServerTimestampV2[] = {
    0x02, 0x00, 0x0c, 0x00, 0x44, 0x00, 0x6f, 0x00, 0x6d, 0x00, 0x61, 0x00,
    0x69, 0x00, 0x6e, 0x00, 0x01, 0x00, 0x0c, 0x00, 0x53, 0x00, 0x65, 0x00,
    0x72, 0x00, 0x76, 0x00, 0x65, 0x00, 0x72, 0x00, 0x07, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// The target info after being updated by the client when the server sends
// |kExpectedTargetInfoFromSpecV2| in the challenge message with both EPA and
// MIC enabled.
//
// When MIC and EPA are enabled, 3 additional AvPairs are added.
// 1) A flags AVPair with the MIC_PRESENT bit set.
// 2) A channel bindings AVPair containing the channel bindings hash.
// 3) A target name AVPair containing the SPN of the server.
//
// AvPair 1 [0-1]    |TargetInfoAvId::kDomainName|      Av ID = 0x0002
// AvPair 1 [2-3]    |len(kNtlmDomainRaw)|              Av Length = 0x000c
// AvPair 1 [4-15]   |kNtlmDomainRaw|                   Av Payload = L"Domain"
//
// AvPair 2 [16-17]  |TargetInfoAvId::kServerName|      Av ID = 0x0001
// AvPair 2 [18-19]  |len(kServerRaw)|                  Av Length = 0x000c
// AvPair 2 [20-31]  |kServerRaw|                       Av Payload = L"Server"
//
// AvPair 3 [32-33]  |TargetInfoAvId::kFlags|           Av ID = 0x0006
// AvPair 3 [34-35]  |sizeof(uint32_t)|                 Av Length = 0x0004
// AvPair 3 [36-39]  |TargetInfoAvFlags::kMicPresent|   Av Payload = 0x00000002
//
// AvPair 4 [40-41]  |TargetInfoAvId::kChannelBindings| Av ID = 0x000a
// AvPair 4 [42-43]  |kChannelBindingsHashLen|          Av Length = 0x0010
// AvPair 4 [44-59]  |kExpectedChannelBindingHashV2|    Av Payload
//
// AvPair 5 [60-61]  |TargetInfoAvId::kTargetName|      Av ID = 0x0009
// AvPair 5 [62-63]  |len(kNtlmSpnRaw)|                 Av Length = 0x0016
// AvPair 5 [64-85]  |kNtlmSpnRaw|                      Av Payload =
//                                                          L"HTTP/Server"
//
// AvPair 6 [86-87]  |TargetInfoAvId::kEol|             Av ID = 0x0000
// AvPair 6 [88-89]                                     Av Length = 0x0000
constexpr uint8_t kExpectedTargetInfoSpecResponseV2[] = {
    0x02, 0x00, 0x0c, 0x00, 'D',  0x00, 'o',  0x00, 'm',  0x00, 'a',  0x00,
    'i',  0x00, 'n',  0x00, 0x01, 0x00, 0x0c, 0x00, 'S',  0x00, 'e',  0x00,
    'r',  0x00, 'v',  0x00, 'e',  0x00, 'r',  0x00, 0x06, 0x00, 0x04, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10, 0x00, 0x65, 0x86, 0xE9, 0x9D,
    0x81, 0xC2, 0xFC, 0x98, 0x4E, 0x47, 0x17, 0x2F, 0xD4, 0xDD, 0x03, 0x10,
    0x09, 0x00, 0x16, 0x00, 'H',  0x00, 'T',  0x00, 'T',  0x00, 'P',  0x00,
    '/',  0x00, 'S',  0x00, 'e',  0x00, 'r',  0x00, 'v',  0x00, 'e',  0x00,
    'r',  0x00, 0x00, 0x00, 0x00, 0x00};

// Test result value defined in [MS-NLMP] Section 4.2.4.2.2.
constexpr uint8_t kExpectedProofFromSpecV2[kNtlmProofLenV2] = {
    0x68, 0xcd, 0x0a, 0xb8, 0x51, 0xe5, 0x1c, 0x96,
    0xaa, 0xbc, 0x92, 0x7b, 0xeb, 0xef, 0x6a, 0x1c};

// The value of the NTLMv2 proof when |kExpectedTargetInfoSpecResponseV2| is
// the updated target info in the Authenticate message.
constexpr uint8_t kExpectedProofSpecResponseV2[kNtlmProofLenV2] = {
    0x01, 0x0c, 0x0b, 0xd1, 0x4e, 0xf7, 0xa2, 0x96,
    0x89, 0xc0, 0xc1, 0x9c, 0xea, 0xe8, 0xb7, 0xdf};

// The value of the NTLMv2 proof when |kExpectedTargetInfoSpecResponseV2| is
// the updated target info, and |kClientTimestamp| is correctly set in the
// Authenticate message.
constexpr uint8_t
    kExpectedProofSpecResponseWithClientTimestampV2[kNtlmProofLenV2] = {
        0x8c, 0x02, 0x60, 0xdb, 0xef, 0x69, 0x06, 0x62,
        0xaf, 0x9c, 0x42, 0xd5, 0x07, 0x82, 0xd2, 0xed};

// Test result data obtained from [2].
constexpr uint8_t kExpectedChannelBindingHashV2[kChannelBindingsHashLen] = {
    0x65, 0x86, 0xE9, 0x9D, 0x81, 0xC2, 0xFC, 0x98,
    0x4E, 0x47, 0x17, 0x2F, 0xD4, 0xDD, 0x03, 0x10};

// Test result value defined in [MS-NLMP] Section 4.2.4.1.2.
constexpr uint8_t kExpectedSessionBaseKeyFromSpecV2[kSessionKeyLenV2] = {
    0x8d, 0xe4, 0x0c, 0xca, 0xdb, 0xc1, 0x4a, 0x82,
    0xf1, 0x5c, 0xb0, 0xad, 0x0d, 0xe9, 0x5c, 0xa3};

// The session base key when the proof is
// |kExpectedProofSpecResponseWithClientTimestampV2|.
constexpr uint8_t
    kExpectedSessionBaseKeyWithClientTimestampV2[kSessionKeyLenV2] = {
        0x62, 0x3d, 0xbd, 0x07, 0x1b, 0xe7, 0xa5, 0x30,
        0xb6, 0xa9, 0x5c, 0x2e, 0xb4, 0x98, 0x24, 0x70};

// The Message Integrity Check (MIC) using
// |kExpectedSessionBaseKeyWithClientTimestampV2| over the following 3
// messages; |kExpectedNegotiateMsg|, |kChallengeMsgFromSpecV2|, and
// |kExpectedAuthenticateMsgSpecResponseV2|.
// The MIC field in |kExpectedAuthenticateMsgSpecResponseV2| is set to all
// zeros while calculating the hash.
constexpr uint8_t kExpectedMicV2[kMicLenV2] = {
    0xf7, 0x36, 0x16, 0x33, 0xf0, 0xad, 0x9b, 0xdf,
    0x4a, 0x7c, 0x42, 0x1b, 0xc6, 0xb8, 0x24, 0xa3};

// Expected negotiate message from this implementation.
// [0-7]    - "NTLMSSP\0"                       (Signature)
// [9-11]   - |MessageType::kNegotiate|         (Message Type = 0x00000001)
// [12-15]  - |kNegotiateMessageFlags|          (Flags = 0x00088207)
// [16-23]  - |SecBuf(kNegotiateMessageLen, 0)| (Domain)
// [24-32]  - |SecBuf(kNegotiateMessageLen, 0)| (Workstation)
//
// NOTE: Message does not include Version field. Since
// NTLMSSP_NEGOTIATE_VERSION is never sent, it is not required, and the server
// won't try to read it. The field is currently omitted for test compatibility
// with the existing implementation. When NTLMv2 is implemented this field
// will be present for both NTLMv1 and NTLMv2, however it will always be set to
// all zeros. The version field is only used for debugging and only defines
// a mapping to Windows operating systems.
//
// Similarly both Domain and Workstation fields are are not strictly required
// either (though are included here) since neither
// NTLMSSP_NEGOTIATE_OEM_WORKSTATION_SUPPLIED nor
// NTLMSSP_NEGOTIATE_OEM_DOMAIN_SUPPLIED are ever sent. A compliant server
// should never read past the 16th byte in this message.
//
// See [MS-NLMP] Section 2.2.2.5 for more detail on flags and 2.2.2.1 for the
// Negotiate message in general.
constexpr uint8_t kExpectedNegotiateMsg[kNegotiateMessageLen] = {
    'N',  'T',  'L',  'M',  'S',  'S',  'P',  '\0', 0x01, 0x00, 0x00,
    0x00, 0x07, 0x82, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00};

// Expected V1 Authenticate message from this implementation when sent
// |kChallengeMsgV1| as the challenge.
//
// [0-7]    - "NTLMSSP\0"                         (Signature)
// [9-11]   - |MessageType::kAuthenticate|        (Message Type = 0x00000003)
// [12-19]  - |SecBuf(64, kResponseLenV1)|        (LM Response)
// [20-27]  - |SecBuf(88, kResponseLenV1)|       (NTLM Response)
// [28-35]  - |SecBuf(112, 12)|                   (Target Name = L"Domain")
// [36-43]  - |SecBuf(124, 8)|                    (User = L"User")
// [44-51]  - |SecBuf(132, 16)|                   (Workstation = L"COMPUTER")
// [52-59]  - |SecBuf(64, 0)|                     (Session Key (empty))
// [60-63]  - 0x00088203                          (Flags)
// [64-87]  - |EXPECTED_V1_WITH_SS_LM_RESPONSE|   (LM Response Payload)
// [88-111] - |EXPECTED_V1_WITH_SS_NTLM_RESPONSE| (NTLM Response Payload)
// [112-123]- L"Domain"                           (Target Name Payload)
// [124-132]- L"User"                             (User Payload)
// [132-147]- L"COMPUTER"                         (Workstation Payload)
//
// NOTE: This is not identical to the message in [MS-NLMP] Section 4.2.2.3 for
// several reasons.
//
// 1) The flags are different because this implementation does not support
// the flags related to version, key exchange, signing and sealing. These
// flags are not relevant to implementing the NTLM scheme in HTTP.
// 2) Since key exchange is not required nor supported, the session base key
// payload is not required nor present.
// 3) The specification allows payloads to be in any order. This (and the
// prior) implementation uses a different payload order than the example.
// 4) The version field is Windows specific and there is no provision for
// non-Windows OS information. This message does not include a version field.
constexpr uint8_t kExpectedAuthenticateMsgSpecResponseV1[] = {
    'N',  'T',  'L',  'M',  'S',  'S',  'P',  '\0', 0x03, 0x00, 0x00, 0x00,
    0x18, 0x00, 0x18, 0x00, 0x40, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00,
    0x58, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x70, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x08, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00,
    0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x03, 0x82, 0x08, 0x00, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x75, 0x37, 0xf8, 0x03, 0xae, 0x36, 0x71, 0x28,
    0xca, 0x45, 0x82, 0x04, 0xbd, 0xe7, 0xca, 0xf8, 0x1e, 0x97, 0xed, 0x26,
    0x83, 0x26, 0x72, 0x32, 'D',  0x00, 'o',  0x00, 'm',  0x00, 'a',  0x00,
    'i',  0x00, 'n',  0x00, 'U',  0x00, 's',  0x00, 'e',  0x00, 'r',  0x00,
    'C',  0x00, 'O',  0x00, 'M',  0x00, 'P',  0x00, 'U',  0x00, 'T',  0x00,
    'E',  0x00, 'R',  0x00,
};

// Expected V2 Authenticate message from this implementation when sent
// |kChallengeMsgFromSpecV2| as the challenge using default features.
//
// [0-7]    - "NTLMSSP\0"                          (Signature)
// [9-11]   - |MessageType::kAuthenticate|         (Message Type = 0x00000003)
// [12-19]  - |SecBuf(88, kResponseLenV1)|         (LM Response)
// [20-27]  - |SecBuf(112, 138)|                   (NTLM Response)
// [28-35]  - |SecBuf(250, 12)|                    (Target Name = L"Domain")
// [36-43]  - |SecBuf(262, 8)|                     (User = L"User")
// [44-51]  - |SecBuf(270, 16)|                    (Workstation = L"COMPUTER")
// [52-59]  - |SecBuf(88, 0)|                      (Session Key (empty))
// [60-63]  - 0x00088203                           (Flags)
// [64-71]  - All zero                             (Version)
// [72-87]  - |kExpectedMicV2|                     (MIC)
// [88-111] - All zero                             (LM Response Payload)
// [112-249]-------------------------------------- (NTLM Response Payload)
//   [112-127]-|kExpectedProofSpecResponseWithClientTimestampV2|
//                                                 (NTLMv2 Proof)
//   [128-155]-|kExpectedTempWithClientTimestampV2[0-27]|
//                                                 (Proof Input)
//   [156-245]-|kExpectedTargetInfoSpecResponseV2| (Updated target info)
//   [246-249]-0x00000000                          (Reserved - zeros)
// -----------------------------------------------------------------------
// [250-261]- L"Domain"                            (Target Name Payload)
// [262-269]- L"User"                              (User Payload)
// [270-285]- L"COMPUTER"                          (Workstation Payload)
//
// NOTE: This is not identical to the message in [MS-NLMP] Section TODO(X) for
// several reasons.
//
// 1) The flags are different because this implementation does not support
// the flags related to version, key exchange, signing and sealing. These
// flags are not relevant to implementing the NTLM scheme in HTTP.
// 2) Since key exchange is not required nor supported, the session base key
// payload is not required nor present.
// 3) The specification allows payloads to be in any order. This (and the
// prior) implementation uses a different payload order than the example.
// 4) The version field is Windows specific and there is no provision for a
// non-Windows OS information. This message does not include a version field.
// 5) The example in the spec does not use Extended Protection for
// Authentication (EPA). This message includes an extra AV Pair containing
// the hashed channel bindings.
// 6) The example in the spec does not use Message Integrity Check (MIC).
// The optional field is not present, nor is the flags AV Pair that indicates
// it's presence.
// 7) Since the server does not provide a timestamp, the client should
// provide one.
constexpr uint8_t kExpectedAuthenticateMsgSpecResponseV2[] = {
    'N',  'T',  'L',  'M',  'S',  'S',  'P',  '\0', 0x03, 0x00, 0x00, 0x00,
    0x18, 0x00, 0x18, 0x00, 0x58, 0x00, 0x00, 0x00, 0x8a, 0x00, 0x8a, 0x00,
    0x70, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xfa, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x08, 0x00, 0x06, 0x01, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00,
    0x0e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00,
    0x03, 0x82, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xf7, 0x36, 0x16, 0x33, 0xf0, 0xad, 0x9b, 0xdf, 0x4a, 0x7c, 0x42, 0x1b,
    0xc6, 0xb8, 0x24, 0xa3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x8c, 0x02, 0x60, 0xdb, 0xef, 0x69, 0x06, 0x62,
    0xaf, 0x9c, 0x42, 0xd5, 0x07, 0x82, 0xd2, 0xed, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x0b, 0xc8, 0xfd, 0x00, 0xd4, 0xd2, 0x01,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x0c, 0x00, 'D',  0x00, 'o',  0x00, 'm',  0x00, 'a',  0x00,
    'i',  0x00, 'n',  0x00, 0x01, 0x00, 0x0c, 0x00, 'S',  0x00, 'e',  0x00,
    'r',  0x00, 'v',  0x00, 'e',  0x00, 'r',  0x00, 0x06, 0x00, 0x04, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10, 0x00, 0x65, 0x86, 0xE9, 0x9D,
    0x81, 0xC2, 0xFC, 0x98, 0x4E, 0x47, 0x17, 0x2F, 0xD4, 0xDD, 0x03, 0x10,
    0x09, 0x00, 0x16, 0x00, 'H',  0x00, 'T',  0x00, 'T',  0x00, 'P',  0x00,
    '/',  0x00, 'S',  0x00, 'e',  0x00, 'r',  0x00, 'v',  0x00, 'e',  0x00,
    'r',  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 'D',  0x00,
    'o',  0x00, 'm',  0x00, 'a',  0x00, 'i',  0x00, 'n',  0x00, 'U',  0x00,
    's',  0x00, 'e',  0x00, 'r',  0x00, 'C',  0x00, 'O',  0x00, 'M',  0x00,
    'P',  0x00, 'U',  0x00, 'T',  0x00, 'E',  0x00, 'R',  0x00,
};

// Expected V2 Authenticate message from this implementation when sent
// |kChallengeMsgV1| as the challenge using default features. This scenario
// can occur because some older implementations (Windows 2003 and earlier),
// do not send NTLMSSP_NEGOTIATE_TARGET_INFO, nor a Target Info payload in
// the challenge message.
//
// [0-7]    - "NTLMSSP\0"                          (Signature)
// [9-11]   - |MessageType::kAuthenticate|         (Message Type = 0x00000003)
// [12-19]  - |SecBuf(88, kResponseLenV1)|         (LM Response)
// [20-27]  - |SecBuf(112, 106)|                   (NTLM Response)
// [28-35]  - |SecBuf(218, 12)|                    (Target Name = L"Domain")
// [36-43]  - |SecBuf(230, 8)|                     (User = L"User")
// [44-51]  - |SecBuf(238, 16)|                    (Workstation = L"COMPUTER")
// [52-59]  - |SecBuf(88, 0)|                      (Session Key (empty))
// [60-63]  - 0x00088203                           (Flags)
// [64-71]  - All zero                             (Version)
// [72-87]  -                                      (MIC)
// [88-111] - All zero                             (LM Response Payload)
// [112-217]-------------------------------------- (NTLM Response Payload)
//   [112-127]-                                    (NTLMv2 Proof)
//   [128-155]-|kExpectedTempWithClientTimestampV2[0-27]|
//                                                 (Proof Input)
//   [156-213]-|kExpectedTargetInfoSpecResponseV2[32-89]|
//                                                 (Updated target info)
//   [214-217]-0x00000000                          (Reserved - zeros)
// -----------------------------------------------------------------------
// [218-229]- L"Domain"                            (Target Name Payload)
// [230-237]- L"User"                              (User Payload)
// [238-253]- L"COMPUTER"                          (Workstation Payload)
//
// NOTE: This is message is almost the same as
// |kExpectedAuthenticateMsgSpecResponseV2| with the following changes.
// 1) The target info within the NTLM response is missing the first 32
// bytes, which represent the 2 AvPairs that the server does not send in
// this case.
// 2) The NTLM Response security buffer length is reduced by 32 and therefore
// all subsequent security buffer offsets are reduced by 32.
// 3) The NTLMv2 Proof is different since the different target info changes
// the hash.
// 4) As with the NTLMv2 Proof, the MIC is different because the message is
// different.
constexpr uint8_t kExpectedAuthenticateMsgToOldV1ChallegeV2[] = {
    'N',  'T',  'L',  'M',  'S',  'S',  'P',  '\0', 0x03, 0x00, 0x00, 0x00,
    0x18, 0x00, 0x18, 0x00, 0x58, 0x00, 0x00, 0x00, 0x6a, 0x00, 0x6a, 0x00,
    0x70, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0xda, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x08, 0x00, 0xe6, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00,
    0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00,
    0x03, 0x82, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x31, 0x37, 0xd6, 0x9e, 0x5c, 0xc8, 0x7d, 0x7a, 0x9f, 0x7c, 0xf4, 0x1a,
    0x5a, 0x19, 0xdc, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xbe, 0xd9, 0xa9, 0x42, 0x20, 0xc2, 0x25, 0x2b,
    0x91, 0x6e, 0x9c, 0xe3, 0x9d, 0x97, 0x3a, 0x2d, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x0b, 0xc8, 0xfd, 0x00, 0xd4, 0xd2, 0x01,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x04, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x10, 0x00,
    0x65, 0x86, 0xE9, 0x9D, 0x81, 0xC2, 0xFC, 0x98, 0x4E, 0x47, 0x17, 0x2F,
    0xD4, 0xDD, 0x03, 0x10, 0x09, 0x00, 0x16, 0x00, 'H',  0x00, 'T',  0x00,
    'T',  0x00, 'P',  0x00, '/',  0x00, 'S',  0x00, 'e',  0x00, 'r',  0x00,
    'v',  0x00, 'e',  0x00, 'r',  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 'D',  0x00, 'o',  0x00, 'm',  0x00, 'a',  0x00, 'i',  0x00,
    'n',  0x00, 'U',  0x00, 's',  0x00, 'e',  0x00, 'r',  0x00, 'C',  0x00,
    'O',  0x00, 'M',  0x00, 'P',  0x00, 'U',  0x00, 'T',  0x00, 'E',  0x00,
    'R',  0x00,
};

}  // namespace test
}  // namespace ntlm
}  // namespace net

#endif  // NET_BASE_NTLM_TEST_DATA_H_