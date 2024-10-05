//
// Copyright (c) 2022 ZettaScale Technology
//
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// http://www.eclipse.org/legal/epl-2.0, or the Apache License, Version 2.0
// which is available at https://www.apache.org/licenses/LICENSE-2.0.
//
// SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
//
// Contributors:
//   ZettaScale Zenoh Team, <zenoh@zettascale.tech>
//

#ifndef ZENOH_PICO_SYSTEM_ZEPHYR_TYPES_H
#define ZENOH_PICO_SYSTEM_ZEPHYR_TYPES_H

#include <version.h>

#if KERNEL_VERSION_MAJOR == 2
#include <kernel.h>
#elif KERNEL_VERSION_MAJOR == 3
#include <zephyr/kernel.h>
#else
#pragma "This Zephyr version might not be supported."
#include <zephyr/kernel.h>
#endif

#ifdef CONFIG_PTHREAD
#include <pthread.h>
#endif

#include "zenoh-pico/config.h"

#if Z_FEATURE_MULTI_THREAD == 1
#ifdef CONFIG_PTHREAD
typedef pthread_t _z_task_t;
typedef pthread_attr_t z_task_attr_t;
typedef pthread_mutex_t _z_mutex_t;
typedef pthread_cond_t _z_condvar_t;
#else
typedef struct {
    struct k_thread thread;
    k_tid_t tid;
} _z_task_t;
typedef struct {
    k_thread_stack_t *stack;
    size_t stack_size;
    int prio;
    uint32_t options;
} z_task_attr_t;
#endif
typedef struct k_mutex _z_mutex_t;
typedef struct k_condvar _z_condvar_t;
#endif  // Z_FEATURE_MULTI_THREAD == 1

#ifdef CONFIG_PTHREAD
typedef struct timespec z_clock_t;
typedef struct timeval z_time_t;
#else
typedef int64_t z_clock_t;
typedef int64_t z_time_t;
#endif

typedef struct {
    union {
#if Z_FEATURE_LINK_TCP == 1 || Z_FEATURE_LINK_UDP_MULTICAST == 1 || Z_FEATURE_LINK_UDP_UNICAST == 1
        int _fd;
#endif
#if Z_FEATURE_LINK_SERIAL == 1
        const struct device *_serial;
#endif
    };
} _z_sys_net_socket_t;

typedef struct {
    union {
#if Z_FEATURE_LINK_TCP == 1 || Z_FEATURE_LINK_UDP_MULTICAST == 1 || Z_FEATURE_LINK_UDP_UNICAST == 1
        struct zsock_addrinfo *_iptcp;
#endif
    };
} _z_sys_net_endpoint_t;

#endif /* ZENOH_PICO_SYSTEM_ZEPHYR_TYPES_H */
