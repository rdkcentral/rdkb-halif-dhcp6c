# DHCP6C HAL Documentation

## Acronyms

- `HAL` \- Hardware Abstraction Layer
- `RDK-B` \- Reference Design Kit for Broadband Devices
- `OEM` \- Original Equipment Manufacture

## Description

The diagram below describes a high-level software architecture of the DHCP6C HAL module stack.

![DHCP6C HAL Architecture Diag](images/DHCP6C_HAL_Architecture.png)

DHCP6C HAL is an abstraction layer, implemented to interact with the underlying software through a standard set of APIs to get offered lease time, remaining lease time, remaining time to renew, DHCP State etc.

## Component Runtime Execution Requirements

### Initialization and Startup

3rd party vendors will implement appropriately to meet operational requirements. This interface is expected to block if the hardware is not ready.

## Threading Model

The interface is not thread safe.

Any module which is invoking the API should ensure calls are made in a thread safe manner.

Different 3rd party vendors allowed to create internal threads to meet the operational requirements. In this case 3rd party implementations
should be responsible to synchronize between the calls, events and cleanup the thread.

## Process Model

All API's are expected to be called from multiple process.

## Memory Model

The client module is responsible to allocate and deallocate memory for necessary API's as specified in API Documentation.

Different 3rd party vendors allowed to allocate memory for internal operational requirements. In this case 3rd party implementations
should be responsible to de-allocate internally.


## Power Management Requirements

The HAL is not involved in any of the power management operation.
Any power management state transitions MUST not affect the operation of the HAL.

## Asynchronous Notification Model

There are no asynchronous notifications.

## Blocking calls

The API's are expected to work synchronously and should complete within a time period commensurate with the complexity of the operation and in accordance with any relevant specification.
Any calls that can fail due to the lack of a response should have a timeout period in accordance with any API documentation.

## Internal Error Handling

All the DHCP6C HAL API's should return error synchronously as a return argument. HAL is responsible to handle system errors(e.g. out of memory) internally.

## Persistence Model

There is no requirement for HAL to persist any setting information. The caller is responsible to persist any settings related to their implementation.


## Nonfunctional requirements

Following non functional requirement should be supported by the component.

## Logging and debugging requirements

The component should log all the error and critical informative messages which helps to debug/triage the issues and understand the functional flow of the system.

The logging should be consistence across all HAL components.

If the vendor is going to log then it has to be logged in `xxx_vendor_hal.log` file name.

Logging should be defined with log levels as per Linux standard logging.

## Memory and performance requirements

The component should not contributing more to memory and CPU utilization while performing normal operations and commensurate with the operation required.


## Quality Control

DHCP6C HAL implementation should pass `Coverity`, `Black duck scan`, `valgrind` checks without any issue.

There should not be any memory leaks/corruption introduced by HAL and underneath 3rd party software implementation.


## Licensing

DHCP6C HAL implementation is expected to released under the Apache License 2.0.

## Build Requirements

The source code should be build under Linux Yocto environment and should be delivered as a shared library named as `libdhcp6cApi.so.0`

## Variability Management

Any new API introduced should be implemented by all the 3rd party module and RDK generic code should be compatible with specific version of HAL software

## DHCP6C or Product Customization

None

## Interface API Documentation

All HAL function prototypes and datatype definitions are available in `dhcp6cApi.h` file.

1. Components/Process must include `dhcp6cApi.h` to make use of DHCP6C hal capabilities.
2. Components/Process should add linker dependency for `libdhcp6cApi.so.0`

## Theory of operation and key concepts

Covered as per "Description" sections in the API documentation.

### UML Diagrams

#### Sequence Diagram

```mermaid
sequenceDiagram
participant Client Module
participant DHCP6C HAL
participant Vendor Software
participant Opensource Software
Client Module->>DHCP6C HAL: ert_dhcp6c_get_info()
DHCP6C HAL->>Vendor Software: 
Vendor Software->>DHCP6C HAL: 
DHCP6C HAL->>Client Module: return

Client Module->>DHCP6C HAL: ecm_dhcp6c_get_info()
DHCP6C HAL->>Vendor Software: 
Vendor Software->>DHCP6C HAL: 
DHCP6C HAL->>Client Module: return
```

