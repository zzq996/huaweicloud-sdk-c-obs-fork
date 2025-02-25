/*
 * Copyright (c) 2002-2005, Network Appliance, Inc. All rights reserved.
 *
 * This Software is licensed under one of the following licenses:
 * 
 * 1) under the terms of the "Common Public License 1.0" a copy of which is
 *    in the file LICENSE.txt in the root directory. The license is also
 *    available from the Open Source Initiative, see 
 *    http://www.opensource.org/licenses/cpl.php.
 * 
 * 2) under the terms of the "The BSD License" a copy of which is in the file
 *    LICENSE2.txt in the root directory. The license is also available from
 *    the Open Source Initiative, see
 *    http://www.opensource.org/licenses/bsd-license.php.
 * 
 * 3) under the terms of the "GNU General Public License (GPL) Version 2" a
 *    copy of which is in the file LICENSE3.txt in the root directory. The
 *    license is also available from the Open Source Initiative, see
 *    http://www.opensource.org/licenses/gpl-license.php.
 * 
 * Licensee has the right to choose one of the above licenses.
 * 
 * Redistributions of source code must retain the above copyright
 * notice and one of the license notices.
 * 
 * Redistributions in binary form must reproduce both the above copyright
 * notice, one of the license notices in the documentation
 * and/or other materials provided with the distribution.
 */

/***************************************************************
 *
 * HEADER: dat_platform_specific.h
 *
 * PURPOSE: defines Platform-specific types.
 *
 * Description: Header file for "DAPL: Direct Access Programming
 *		Library, Version: 1.2"
 *
 * Mapping rules:
 *
 ***************************************************************/

#ifndef _DAT_PLATFORM_SPECIFIC_H_
#define _DAT_PLATFORM_SPECIFIC_H_

/* OS, processor, compiler type definitions. Add OSes as needed. */

/*
 * This captures the alignment for the bus transfer from the HCA/IB chip
 * to the main memory.
 */
#ifndef DAT_OPTIMAL_ALIGNMENT
#define DAT_OPTIMAL_ALIGNMENT   256             /* Performance optimal alignment */
#endif /* DAT_OPTIMAL_ALIGNMENT */

/* Assume all OSes use sockaddr, for address family: IPv4 == AF_INET,
 * IPv6 == AF_INET6. Use of "namelen" field indicated.
 *
 * The Interface Adapter Address names an Interface Adapter local or
 * remote, that is used for connection management and Name
 * Service. The format of the dat_ia_address_ptr follows the normal
 * socket programming practice of struct sockaddr *. DAT supports both
 * IPv4 and IPv6 address families.  Allocation and initialization of
 * DAT IA address structures must follow normal Sockets programming
 * procedures. The underlying type of the DAT IA address is the native
 * struct sockaddr for each target operating system. In all cases,
 * storage appropriate for the address family in use by the target
 * Provider must be allocated. For instance, when IPv6 addressing is
 * in use, this should be allocated as struct sockaddr_net6. The
 * sockaddr sa_family and, if present, sa_len fields must be
 * initialized appropriately, as well as the address information.
 * When passed across the DAPL API this storage is cast to the
 * DAT_IA_ADDRESS_PTR type. It is the responsibility of the callee to
 * verify that the sockaddr contains valid data for the requested
 * operation. It is always the responsibility of the caller to manage
 * the storage.
 *
 * uDAPL code example for Linux (kdapl would be similar):
 *
 * #include <stdio.h>
 * #include <sys/socket.h>
 * #include <netinet/in.h>
 * #include <dat/udat.h>
 *
 *  struct sockaddr_in6 addr;
 *  DAT_IA_ADDRESS_PTR ia_addr;
 *
 *	// Note: linux pton requires explicit encoding of IPv4 in IPv6
 *
 *	addr.sin6_family = AF_INET6;
 *	if (inet_pton(AF_INET6, "0:0:0:0:0:FFFF:192.168.0.1",
 *		      &addr.sin6_addr) <= 0)
 *	  return(-1); // Bad address or no address family support
 *
 *	// initialize other necessary fields such as port, flow, etc
 *
 *	ia_addr = (DAT_IA_ADDRESS_PTR) &addr;
 *	dat_ep_connect(ep_handle, ia_addr, conn_qual, timeout, 0, NULL,
 *		       qos, DAT_CONNECT_DEFAULT_FLAG);
 *
 */

#if defined (sun) || defined(__sun) || defined(_sun_) || defined (__solaris__)
/* Solaris begins */

#include <sys/types.h>
#include <inttypes.h>			/* needed for UINT64_C() macro */

typedef uint32_t                DAT_UINT32;	/* Unsigned host order, 32 bits */
typedef uint64_t                DAT_UINT64;	/* unsigned host order, 64 bits */
typedef unsigned long long	DAT_UVERYLONG;	/* unsigned longest native to compiler */

typedef void *                  DAT_PVOID;
typedef int                     DAT_COUNT;

#include <sys/socket.h>
#include <netinet/in.h>
typedef struct sockaddr        DAT_SOCK_ADDR;  /* Socket address header native to OS */
typedef struct sockaddr_in6    DAT_SOCK_ADDR6; /* Socket address header native to OS */

#define DAT_AF_INET             AF_INET
#define DAT_AF_INET6            AF_INET6

typedef DAT_UINT64		DAT_PADDR;

/* Solaris ends */


/* Linux begins */
#elif defined(__linux__) /* Linux */
#if defined(__KERNEL__)
#include <linux/types.h>
#else
#include <sys/types.h>
#include <linux/stddef.h>
#endif /* defined(__KERNEL__) */

typedef u_int32_t               DAT_UINT32;	/* unsigned host order, 32 bits */
typedef u_int64_t               DAT_UINT64;	/* unsigned host order, 64 bits */
typedef unsigned long long	DAT_UVERYLONG;	/* unsigned longest native to compiler */

typedef void *                  DAT_PVOID;
typedef int                     DAT_COUNT;
typedef DAT_UINT64		DAT_PADDR;

#ifndef UINT64_C
#define UINT64_C(c)	c ## ULL
#endif /* UINT64_C */

#if defined(__KERNEL__)
#include <linux/socket.h>
#include <linux/in.h>
#include <linux/in6.h>
#else
#include <sys/socket.h>
#endif /* defined(__KERNEL__) */

typedef struct sockaddr         DAT_SOCK_ADDR; /* Socket address header native to OS */
typedef struct sockaddr_in6     DAT_SOCK_ADDR6; /* Socket address header native to OS */
#define DAT_AF_INET AF_INET
#define DAT_AF_INET6 AF_INET6
/* Linux ends */


/* Win32 begins */
#elif defined(_MSC_VER) || defined(_WIN32) /* NT. MSC compiler, Win32 platform */

typedef unsigned __int32        DAT_UINT32;	/* Unsigned host order, 32 bits */
typedef unsigned __int64        DAT_UINT64;	/* unsigned host order, 64 bits */
typedef unsigned  long		DAT_UVERYLONG;	/* unsigned longest native to compiler */

typedef void *                  DAT_PVOID;
typedef long                    DAT_COUNT;

typedef struct sockaddr         DAT_SOCK_ADDR;	/* Socket address header native to OS */
typedef struct sockaddr_in6     DAT_SOCK_ADDR6; /* Socket address header native to OS */

#ifndef UINT64_C
#define UINT64_C(c) c ## i64
#endif /* UINT64_C */

#define DAT_AF_INET             AF_INET
#define DAT_AF_INET6            AF_INET6

#if defined(__KDAPL__)
/* must have the DDK for this definition */
typedef PHYSICAL_ADDRESS	DAT_PADDR;
#endif /* __KDAPL__ */

/* Win32 ends */


#else
#error dat_platform_specific.h : OS type not defined
#endif

#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef INOUT
#define INOUT
#endif

#endif /* _DAT_PLATFORM_SPECIFIC_H_ */
