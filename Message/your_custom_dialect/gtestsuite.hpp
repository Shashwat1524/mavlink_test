/** @file
 *	@brief MAVLink comm testsuite protocol generated from your_custom_dialect.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "your_custom_dialect.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(your_custom_dialect, GET_ATTITUDE_BATTERY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::your_custom_dialect::msg::GET_ATTITUDE_BATTERY packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.current_battery = 18275;
    packet_in.energy_consumed = 963498296;
    packet_in.battery_remaining = -57;

    mavlink::your_custom_dialect::msg::GET_ATTITUDE_BATTERY packet1{};
    mavlink::your_custom_dialect::msg::GET_ATTITUDE_BATTERY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.current_battery, packet2.current_battery);
    EXPECT_EQ(packet1.energy_consumed, packet2.energy_consumed);
    EXPECT_EQ(packet1.battery_remaining, packet2.battery_remaining);
}

#ifdef TEST_INTEROP
TEST(your_custom_dialect_interop, GET_ATTITUDE_BATTERY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_get_attitude_battery_t packet_c {
         963497464, 45.0, 73.0, 101.0, 963498296, 18275, -57
    };

    mavlink::your_custom_dialect::msg::GET_ATTITUDE_BATTERY packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.roll = 45.0;
    packet_in.pitch = 73.0;
    packet_in.yaw = 101.0;
    packet_in.current_battery = 18275;
    packet_in.energy_consumed = 963498296;
    packet_in.battery_remaining = -57;

    mavlink::your_custom_dialect::msg::GET_ATTITUDE_BATTERY packet2{};

    mavlink_msg_get_attitude_battery_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.current_battery, packet2.current_battery);
    EXPECT_EQ(packet_in.energy_consumed, packet2.energy_consumed);
    EXPECT_EQ(packet_in.battery_remaining, packet2.battery_remaining);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
