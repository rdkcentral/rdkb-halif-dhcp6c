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
* @file dhcp4cApi.h
* @brief The dhcp4cApi gives the function call prototypes and structure definitions used for the RDK-Broadband DHCP4Client Status abstraction layer.
*/
#ifndef _DHCP4_CLIENT_API_
#define _DHCP4_CLIENT_API_

/**
 * @defgroup DHCPV4C_HAL DHCPV4C HAL
 *
 * DHCPv4C HAL is used for the RDK-B DHCPv4 Client Status abstraction layer.
 *
 * @defgroup DHCPV4C_HAL_TYPES  DHCPV4C HAL Data Types
 * @ingroup  DHCPV4C_HAL
 *
 * @defgroup DHCPV4C_HAL_APIS   DHCPV4C HAL APIs
 * @ingroup  DHCPV4C_HAL
 *
 **/

/**
 * @addtogroup DHCPV4C_HAL_TYPES
 * @{
 */

/**********************************************************************
                ENUMERATION DEFINITIONS
**********************************************************************/
/**
 * @brief Represents the information for the DHCP client.
 *
 * This enumeration contains the different information used in DHCP client such as lease time, 
 * configuration attempts, interface name, FSM state and server information.
 */
enum DHCPC_CMD{
        DHCPC_CMD_LEASE_TIME = 0,      /**< Represents the lease time obtained from the DHCP server */
        DHCPC_CMD_LEASE_TIME_REMAIN,   /**< Represents the remaining lease time */
        DHCPC_CMD_RENEW_TIME_REMAIN,   /**< Represents the remaining time for lease renewal */
        DHCPC_CMD_REBIND_TIME_REMAIN,  /**<  Represents the remaining time for rebinding */
        DHCPC_CMD_CONFIG_ATTEMPTS,     /**<  Represents the number of configuration attempts */
        DHCPC_CMD_GET_IFNAME,          /**<  Represents the interface name associated with the DHCP 
                                             Client */
        DHCPC_CMD_FSM_STATE,           /**<  Represents the FSM state of the DHCP client  */
        DHCPC_CMD_IP_ADDR,             /**<  Represents the  IP address obtained from the server */
        DHCPC_CMD_IP_MASK,             /**<  Represents the subnet mask obtained from the server   */
        DHCPC_CMD_ROUTERS,             /**<  Represents the list of routers obtained from the server  */
        DHCPC_CMD_DNS_SVRS,            /**<  Represents the list of DNS servers obtained from the DHCP 
                                             server */
        DHCPC_CMD_DHCP_SVR,            /**<  Represents the IP addresses of the DHCP servers */
        DHCPC_CMD_MAX                  /**<  Represents the maximum value of the elements */
};

/**
 * @brief Represents the different types of modules in the DHCP client.
 *
 * This enumeration contains modules which defines embedded cable modem, router related functionality,
 * embedded multimedia terminal adapter. 
 */
enum DHCPC_MODULE{
        DHCPC_ECM = 0,   /**<  Represents the module of embedded cable modem. This is associated with 
                               functionality or configurations specific to cable modems. */
        DHCPC_EROUTER,   /**<  Represents the module of routers which is used to handle or configure 
                               the routers. */
        DHCPC_EMTA       /**<  Represents the module which is associated with the functionality to 
                        multimedia terminal adapters.  */
};

#define MAX_IPV4_ADDR_LIST_NUMBER        4  //!< Maximum number of IPv4 addresses in the list  

/**********************************************************************
                STRUCTURE DEFINITIONS
**********************************************************************/
/**
 * @brief Represents IPv4 addresses.
 *
 * Holds information of the list of IPv4 addresses that are used by the specific server. 
 */
typedef struct{
        int    number;                                     /**<  @brief Number of IPv4 addresses in the 
                                                                  list */
        unsigned int addrList[MAX_IPV4_ADDR_LIST_NUMBER];  /**< @brief List of IPv4 addresses. Each IPv4
                                                                address is an unsigned integer of 4 bytes.
                                                                The valid ranges for IPv4 addresses are:
                                                                "1.0.0.0 to 127.0.0.0, 
                                                                128.0.0.0 to 191.255.0.0, 
                                                                192.0.0.0 to 223.255.255.0 */
}ipv4AddrList_t;

/** @} */  //END OF GROUP DHCPV4C_HAL_TYPES

/**
 * @addtogroup DHCPV4C_HAL_APIS
 * @{
 */


/**
* @brief Gets the E-Router Offered Lease Time
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is 604800.
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_lease_time(unsigned int *pValue);

/**
* @brief Gets the E-Router Remaining Lease Time.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_remain_lease_time(unsigned int *pValue);

/**
* @brief Gets the E-Router Interface Remaining Time to Renew
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_remain_renew_time(unsigned int *pValue);

/**
* @brief Gets the E-Router Interface Remaining Time to Rebind
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_remain_rebind_time(unsigned int *pValue);

/**
* @brief Gets the E-Router Number of Attempts to Configure.
*
* @param[out] pValue It is an integer pointer that provies the count.
*                    \n The maximum value is 0 to (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_config_attempts(int *pValue);

/**
* @brief Gets the E-Router Interface Name.
*
* @param[out] pName It is a 64 byte character array that provides the interface name.
*                   \n It is vendor specific.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_ifname(char *pName);

/**
* @brief Gets the E-Router DHCP State
*
* @param[out] pValue It is of type integer that provides the state of the DHCP.
*                    \n The valid range of values is 0 to 6, where:
*                    \n RELEASED = 1
*                    \n INIT_REBOOT = 1
*                    \n INIT_SELECTING = 2
*                    \n REQUESTING = 3
*                    \n REBINDING = 4
*                    \n BOUND = 5
*                    \n RENEWING = 6
*                    \n RENEW_REQUESTED = 6
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_fsm_state(int *pValue);

/**
* @brief Gets the E-Router Interface IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the interface.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_ip_addr(unsigned int *pValue);

/**
* @brief Gets the E-Router Subnet Mask.
*
* @param[out] pValue It is an unsigned integer pointer that represents the subnet mask(bitmask).
*                    \n The maximum value for each octet is 255.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_mask(unsigned int *pValue);

/**
* @brief Gets the E-Router Gateway IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the Gateway.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_gw(unsigned int *pValue);

/**
* @brief Gets the E-Router List of DNS Servers
*
* @param[out] pList Pointer to dhcpv4c_ip_list_t structure that contains the list of IP addresses of DNS Servers.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
*
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_dns_svrs(ipv4AddrList_t *pList);

/**
* @brief Gets the E-Router DHCP Server IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of DHCP Server.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
*
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ert_dhcp_svr(unsigned int *pValue);

/**
* @brief Gets the ECM Offered Lease Time.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is 604800.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_lease_time(unsigned int *pValue);

/**
* @brief Gets the ECM Remaining Lease Time
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_remain_lease_time(unsigned int *pValue);

/**
* @brief Gets the ECM Interface Remaining time to Renew.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_remain_renew_time(unsigned int *pValue);

/**
* @brief Gets the ECM Interface Remaining time to Rebind.
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_remain_rebind_time(unsigned int *pValue);

/**
* @brief Gets the ECM Configuration Number of Attemts.
*
* @param[out] pValue It is an integer pointer that provies the count.
*                    \n The maximum value is (2^31)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_config_attempts(int *pValue);

/**
* @brief Gets the ECM Interface Name.
*
* @param[out] pName     It is a 64 byte character array that provides the interface name.
*                       \n It is vendor specific.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/

int dhcp4c_get_ecm_ifname(char *pName);

/**
* @brief Gets the ECM DHCP State
*
* @param[out] pValue It is of type integer that provides the state of the DHCP.
*                    \n The range is 0 to 6, where:
*                    \n RELEASED = 1
*                    \n INIT_REBOOT = 1
*                    \n INIT_SELECTING = 2
*                    \n REQUESTING = 3
*                    \n REBINDING = 4
*                    \n BOUND = 5
*                    \n RENEWING = 6
*                    \n RENEW_REQUESTED = 6
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_fsm_state(int *pValue);

/**
* @brief Gets the ECM Interface IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the interface.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_ip_addr(unsigned int *pValue);

/**
* @brief Gets the ECM Interface Subnet Mask.
*
* @param[out] pValue It is an unsigned integer pointer that represents the subnet Mask(bitmask).
*                    \n The maximum value for each octet is 255.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_mask(unsigned int *pValue);

/**
* @brief Gets the ECM Gateway IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address of the gateway.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_gw(unsigned int *pValue);

/**
* @brief Gets the ECM List of DNS Servers
*
* @param[out] pList	Pointer to dhcpv4c_ip_list_t structure that contains the list of IP addresses of DNS Servers.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_dns_svrs(ipv4AddrList_t *pList);

/**
* @brief Gets the ECM DHCP Server IP Address
*
* @param[out] pValue It is an unsigned integer pointer that represents the IP address.
*                    \n The valid ranges for IPv4 addresses are: 1.0.0.0 to 127.0.0.0, 128.0.0.0 to 191.255.0.0, 192.0.0.0 to 223.255.255.0
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_ecm_dhcp_svr(unsigned int *pValue);

/**
* @brief Gets the E-MTA interface Least Time
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
* 
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_emta_remain_lease_time(unsigned int *pValue);

/**
* @brief Gets the E-MTA interface Remaining Time to Renew
*
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_emta_remain_renew_time(unsigned int *pValue);

/**
* @brief Gets the E-MTA interface Remaining Time to Rebind
* @param[out] pValue It is an unsigned integer pointer that provides the value in seconds.
*                    \n The maximum value is (2^32)-1.
*
* @return The status of the operation.
* @retval STATUS_SUCCESS which is 0 if successful.
* @retval STATUS_FAILURE which is -1 if any error is detected
*
* @remark The caller is responsible for providing a valid memory location for the function arguments.
*
* 
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int dhcp4c_get_emta_remain_rebind_time(unsigned int *pValue);

/** @} */  //END OF GROUP DHCPV4C_HAL_APIS

#endif
