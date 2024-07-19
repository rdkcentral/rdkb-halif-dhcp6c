 /**
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 /**
 * @file dhcp6cApi.h
 * @brief DHCPv6 Client Hardware Abstraction Layer (HAL)
 *
 * This header file defines the interface for the RDK-B DHCP6c HAL, providing a
 * standardized way to access and manage DHCPv6 client information for E-Router
 * and ECM components across platforms and vendor implementations. It includes
 * function prototypes and data structures for retrieving DHCPv6 client details
 * like offered lease time, remaining lease time, remaining time to renew, and DHCP state.
 */

#ifndef _DHCP6_CLIENT_API_
#define _DHCP6_CLIENT_API_

/**
 * @addtogroup DHCPV6C_HAL_APIS
 * @{
 */

 /**
 * @TODO: Refactor Return Codes
 * This module currently uses basic #define macros for return codes. To improve error handling and provide more informative feedback to users, the following steps are recommended:
 *   i) Create a Return Code Enum: Define a comprehensive enum to represent the various success and error conditions that functions in this module can encounter. This will enhance type safety and readability.
 *  ii) Expand Error Codes: Include specific error values within the enum to provide detailed information about the cause of failures. For example, consider adding codes like DHCP6C_HAL_INVALID_ARGUMENT, DHCP6C_HAL_CLIENT_NOT_FOUND, etc.
 * iii) Update Function Signatures: Modify the return types of functions in this module to use the new enum type.
 *  iv) Implement Error Handling: Ensure that functions consistently use the new error codes to indicate the outcome of their operations.
 *
 * This refactoring was suggested during the open-source review process to enhance the usability and maintainability of the DHCP6C HAL module.
 */

/**
 * @brief Retrieves information about the E-Router (Edge Router) DHCPv6 client.
 *
 * This function fetches the current state and configuration details of the 
 * E-Router DHCPv6 client and stores them in the `dhcp6cInfo_t` structure 
 * pointed to by `pInfo`.
 *
 * @param[out] pInfo - Pointer to a `dhcp6cInfo_t` structure that will be filled 
 *                     with the E-Router DHCPv6 client information.
 *
 * @returns The status of the operation.
 * @retval STATUS_SUCCESS - The E-Router information was successfully retrieved.
 * @retval STATUS_FAILURE - An error occurred while retrieving the information.
 *
 * @TODO: Refactor return codes to use a more specific and informative enum (see
 *        general TODO comment).
 */
int ert_dhcp6c_get_info(dhcp6cInfo_t *pInfo);

/**
 * @brief Retrieves information about the ECM (Embedded Cable Modem) DHCPv6 client.
 *
 * This function fetches the current state and configuration details of the ECM 
 * DHCPv6 client and stores them in the `dhcp6cInfo_t` structure pointed to by 
 * `pInfo`.
 *
 * @param[out] pInfo - Pointer to a `dhcp6cInfo_t` structure that will be filled 
 *                     with the ECM DHCPv6 client information.
 *
 * @returns The status of the operation.
 * @retval STATUS_SUCCESS - The ECM information was successfully retrieved.
 * @retval STATUS_FAILURE - An error occurred while retrieving the information.
 *
 * @TODO: Refactor return codes to use a more specific and informative enum (see
 *        general TODO comment).
 */
int ecm_dhcp6c_get_info(dhcp6cInfo_t *pInfo);
/** @} */  //END OF GROUP DHCPV6C_HAL_APIS
#endif
