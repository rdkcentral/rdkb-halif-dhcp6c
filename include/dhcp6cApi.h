/*
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
* @brief The dhcp6cApi provides the function call prototypes and structure definitions used for the RDK-Broadband DHCP6Client Status abstraction layer.
*/

#ifndef _DHCP6_CLIENT_API_
#define _DHCP6_CLIENT_API_

/**
 * @addtogroup DHCPV4C_HAL_APIS
 * @{
 */


/*
 * TODO:
 *
 * 1. Extend the return codes by listing out the possible reasons of failure, to improve the interface in the future.
 *    This was reported during the review for header file migration to opensource github.
 *
 */

/**
* @brief Gets the E-Router Info.
* @param[out] pInfo - Pointer to dhcp6cInfo_t structure that will hold the complete E-Router information.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected
*
*
* 
*
*/
int ert_dhcp6c_get_info(dhcp6cInfo_t *pInfo);

/**
* @brief Gets the ECM Info.
* @param[out] pInfo - Pointer to dhcp6cInfo_t structure that will hold the complete ECM information.

* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected
*
*
* 
*
*
*/
int ecm_dhcp6c_get_info(dhcp6cInfo_t *pInfo);
/** @} */  //END OF GROUP DHCPV4C_HAL_APIS
#endif
