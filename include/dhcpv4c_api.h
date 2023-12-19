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
* @file dhcpv4c_api.h
* @brief The dhcpv4c_api provides the function call prototypes and structure definitions used for the RDK-Broadband DHCPv4Client Status abstraction layer.
*/

#ifndef __DHCPV4_CLIENT_API_H__
#define __DHCPV4_CLIENT_API_H__


#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef BOOL
#define BOOL  unsigned char
#endif

#ifndef CHAR
#define CHAR  char
#endif

#ifndef UCHAR
#define UCHAR unsigned char
#endif

#ifndef INT
#define INT   int
#endif

#ifndef UINT
#define UINT  unsigned int
#endif

#ifndef TRUE
#define TRUE     1
#endif

#ifndef FALSE
#define FALSE    0
#endif

#ifndef ENABLE
#define ENABLE   1
#endif

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS     0
#endif

#ifndef STATUS_FAILURE
#define STATUS_FAILURE     -1
#endif

/**
 * @addtogroup DHCPV4C_HAL_TYPES
 * @{
 */
#define DHCPV4_MAX_IPV4_ADDRS   4

/**********************************************************************
                STRUCTURE DEFINITIONS
**********************************************************************/
typedef struct {
    
    INT number;                         /* Number of IPv4 addresses in the list */
	UINT addrs[DHCPV4_MAX_IPV4_ADDRS];  /*List of IPv4 addresses.Each IPv4 address is an unsigned integer of 4 bytes. 
                                        The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0 */
} dhcpv4c_ip_list_t;
/** @} */  //END OF GROUP DHCPV4C_HAL_TYPES

/**
 * @addtogroup DHCPV4C_HAL_APIS
 * @{
 */

/**********************************************************************************
 *
 *  DHCPV4-Client Subsystem level function prototypes
 *
**********************************************************************************/

/**
* @brief Gets the E-Router Offered Lease Time.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is 604800.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_lease_time(UINT *pValue);

/**
* @brief Gets the E-Router Remaining Lease Time.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_remain_lease_time(UINT *pValue);

/**
* @brief Gets the E-Router Interface Remaining Time to Renew.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_remain_renew_time(UINT *pValue);

/**
* @brief Gets the E-Router Interface Remaining Time to Rebind.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_remain_rebind_time(UINT *pValue);

/**
* @brief Gets the E-Router Number of Attemts to Configure.
*
* @param[out] pValue It is an integer pointer that provies the count.
*                    \n The maximum value is (2^31)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_config_attempts(INT *pValue);

/**
* @brief Gets the E-Router Interface Name.
*
* @param[out] pName It is a 64 byte character array that provides the interface name.
*                   \n It is vendor specific.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_ifname(CHAR *pName);

/**
* @brief Gets the E-Router DHCP State.
*
* @param[out] pValue It is an enumeration that provides the state of DHCP.
*                    \n The possible values are 1 to 6 based on _COSA_DML_DHCPC_STATUS enum type.
*                    \n COSA_DML_DHCPC_STATUS_Init = 1
*                    \n COSA_DML_DHCPC_STATUS_Selectin = 2
*                    \n COSA_DML_DHCPC_STATUS_Requesting = 3
*                    \n COSA_DML_DHCPC_STATUS_Rebinding = 4
*                    \n COSA_DML_DHCPC_STATUS_Bound = 5
*                    \n COSA_DML_DHCPC_STATUS_Renewing = 6
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_fsm_state(INT *pValue);

/**
* @brief Gets the E-Router Interface IP Address.
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the interface.
*                    \n The possible values for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_ip_addr(UINT *pValue);

/**
* @brief Gets the E-Router Subnet Mask.
*
* @param[out] pValue It is an unsigned integer pointer that represents the subnet mask(bitmask).
*                    \n The maximum value for each octet is 255.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_mask(UINT *pValue);

/**
* @brief Gets the E-Router Gateway IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the Gateway.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_gw(UINT *pValue);

/**
* @brief Gets the E-Router List of DNS Servers
*
* @param[out] pList Pointer to dhcpv4c_ip_list_t structure that contains the list of IP addresses of DNS Servers.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_dns_svrs(dhcpv4c_ip_list_t *pList);

/**
* @brief Gets the E-Router DHCP Server IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of DHCP Server.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ert_dhcp_svr(UINT *pValue);

/**
* @brief description Gets the ECM Offered Lease Time.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is 604800.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_lease_time(UINT *pValue);

/**
* @brief Gets the ECM Remaining Lease Time
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_remain_lease_time(UINT *pValue);

/**
* @brief Gets the ECM Interface Remaining time to Renew.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_remain_renew_time(UINT *pValue);

/**
* @brief Gets the ECM Interface Remaining time to Rebind.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_remain_rebind_time(UINT *pValue);

/**
* @brief Gets the ECM Configuration Number of Attemts.
*
* @param[out] pValue It is an integer pointer that provides the count.
*                    \n The maximum value is (2^31)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_config_attempts(INT *pValue);

/**
* @brief Gets the ECM Interface Name.
*
* @param[out] pName It is a 64 byte character array that represents the name of the interface.
*                   \n It is vendor specific.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_ifname(CHAR *pName);

/**
* @brief Gets the ECM DHCP State.
*
* @param[out] pValue It is an enumeration that provides the state of DHCP.
*                    \n The range of acceptable values is 1 to 6 based on _COSA_DML_DHCPC_STATUS enum type.
*                    \n COSA_DML_DHCPC_STATUS_Init = 1
*                    \n COSA_DML_DHCPC_STATUS_Selectin = 2
*                    \n COSA_DML_DHCPC_STATUS_Requesting = 3
*                    \n COSA_DML_DHCPC_STATUS_Rebinding = 4
*                    \n COSA_DML_DHCPC_STATUS_Bound = 5
*                    \n COSA_DML_DHCPC_STATUS_Renewing = 6
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_fsm_state(INT *pValue);

/**
* @brief Gets the ECM Interface IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the interface.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_ip_addr(UINT *pValue);

/**
* @brief Gets the ECM Interface Subnet Mask.
*
* @param[out] pValue It is an unsigned integer pointer that represents the subnet Mask(bitmask).
*                    \n The maximum value for each octet is 255.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*

* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_mask(UINT *pValue);

/**
* @brief Gets the ECM Gateway IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the gateway.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_gw(UINT *pValue);

/**
* @brief Gets the ECM List of DNS Servers
*
* @param[out] pList Pointer to dhcpv4c_ip_list_t structure that contains the list of IP addresses of DNS Servers.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_dns_svrs(dhcpv4c_ip_list_t *pList);

/**
* @brief Gets the ECM DHCP Server IP Address.
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_ecm_dhcp_svr(UINT *pValue);

/**
* @brief Gets the E-MTA interface Least Time
*
* @param[out] pValue It is an unsigned integer pointer that represents the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_emta_remain_lease_time(UINT *pValue);

/**
*
* @brief Gets the E-MTA interface Remaining Time to Renew
* @param[out] pValue It is an unsigned integer pointer that represents the value in seconds.
*                    \n The maximum value is (2^32)-1.
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_emta_remain_renew_time(UINT *pValue);

/**
* @brief Gets the E-MTA interface Remaining Time to Rebind
* @param[out] pValue It is an unsigned integer pointer that represents the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected.
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT dhcpv4c_get_emta_remain_rebind_time(UINT *pValue);

/** @} */  //END OF GROUP DHCPV4C_HAL_APIS
#endif
