/** @file
 *    @brief MAVLink comm protocol testsuite generated from your_custom_dialect.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef YOUR_CUSTOM_DIALECT_TESTSUITE_H
#define YOUR_CUSTOM_DIALECT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_your_custom_dialect(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_your_custom_dialect(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_get_attitude_battery(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_get_attitude_battery_t packet_in = {
        963497464,45.0,73.0,101.0,963498296,18275,199
    };
    mavlink_get_attitude_battery_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.energy_consumed = packet_in.energy_consumed;
        packet1.current_battery = packet_in.current_battery;
        packet1.battery_remaining = packet_in.battery_remaining;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_get_attitude_battery_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_get_attitude_battery_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_get_attitude_battery_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.current_battery , packet1.energy_consumed , packet1.battery_remaining );
    mavlink_msg_get_attitude_battery_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_get_attitude_battery_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.current_battery , packet1.energy_consumed , packet1.battery_remaining );
    mavlink_msg_get_attitude_battery_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_get_attitude_battery_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_get_attitude_battery_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.roll , packet1.pitch , packet1.yaw , packet1.current_battery , packet1.energy_consumed , packet1.battery_remaining );
    mavlink_msg_get_attitude_battery_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GET_ATTITUDE_BATTERY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY) != NULL);
#endif
}

static void mavlink_test_your_custom_dialect(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_get_attitude_battery(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // YOUR_CUSTOM_DIALECT_TESTSUITE_H
