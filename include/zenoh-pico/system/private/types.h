
/*
 * Copyright (c) 2017, 2021 ADLINK Technology Inc.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Apache License, Version 2.0
 * which is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
 *
 * Contributors:
 *   ADLINK zenoh team, <zenoh@adlink-labs.tech>
 */

#ifndef _ZENOH_PICO_SYSTEM_TYPES_H
#define _ZENOH_PICO_SYSTEM_TYPES_H

#if defined(ZENOH_LINUX) || defined(ZENOH_MACOS)
#include "zenoh-pico/system/private/unix.h"
#elif defined(ZENOH_ZEPHYR)
#include "zenoh-pico/system/private/zephyr.h"
#else
#include "zenoh-pico/system/private/void.h"
#error "Unknown platform"
#endif

typedef struct
{
    void *elem;
    int full;
    _z_mutex_t mtx;
    _z_condvar_t can_put;
    _z_condvar_t can_get;
} _z_mvar_t;

#endif /* _ZENOH_PICO_SYSTEM_TYPES_H */
