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

#ifndef ZENOH_PICO_TRANSPORT_LINK_RX_H
#define ZENOH_PICO_TRANSPORT_LINK_RX_H

#include "zenoh-pico/session/session.h"
#include "zenoh-pico/transport/transport.h"
#include "zenoh-pico/link/link.h"

/*------------------ Transmission and Reception helpers ------------------*/
_zn_transport_message_result_t _zn_recv_t_msg(_zn_transport_t *zt);
_zn_transport_message_result_t _zn_unicast_recv_t_msg(_zn_transport_unicast_t *ztu);
_zn_transport_message_result_t _zn_multicast_recv_t_msg(_zn_transport_multicast_t *ztm);

_zn_transport_message_result_t _zn_link_recv_t_msg(const _zn_link_t *zl);

void _zn_recv_t_msg_na(_zn_transport_t *zt, _zn_transport_message_result_t *r);
void _zn_unicast_recv_t_msg_na(_zn_transport_unicast_t *ztu, _zn_transport_message_result_t *r);
void _zn_multicast_recv_t_msg_na(_zn_transport_multicast_t *ztm, _zn_transport_message_result_t *r);

int _zn_handle_transport_message(_zn_transport_t *zt, _zn_transport_message_t *t_msg);
int _zn_unicast_handle_transport_message(_zn_transport_unicast_t *ztu, _zn_transport_message_t *t_msg);
int _zn_multicast_handle_transport_message(_zn_transport_multicast_t *ztm, _zn_transport_message_t *t_msg);

#endif /* ZENOH_PICO_TRANSPORT_LINK_RX_H */