// MESSAGE GET_ATTITUDE_BATTERY support class

#pragma once

namespace mavlink {
namespace your_custom_dialect {
namespace msg {

/**
 * @brief GET_ATTITUDE_BATTERY message
 *
 * Gives Attitude and Battery Values
 */
struct GET_ATTITUDE_BATTERY : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50000;
    static constexpr size_t LENGTH = 23;
    static constexpr size_t MIN_LENGTH = 23;
    static constexpr uint8_t CRC_EXTRA = 199;
    static constexpr auto NAME = "GET_ATTITUDE_BATTERY";


    uint32_t time_boot_ms; /*< [ms] Timestamp (Time Since System Boot>. */
    float roll; /*< [rad] Roll */
    float pitch; /*< [rad] Pitch */
    float yaw; /*< [rad] Yaw */
    int16_t current_battery; /*< [cA] Consumed Charge */
    int32_t energy_consumed; /*< [hJ] Consumed Energy */
    int8_t battery_remaining; /*< [%] Remaining Battery */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  yaw: " << yaw << std::endl;
        ss << "  current_battery: " << current_battery << std::endl;
        ss << "  energy_consumed: " << energy_consumed << std::endl;
        ss << "  battery_remaining: " << +battery_remaining << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << roll;                          // offset: 4
        map << pitch;                         // offset: 8
        map << yaw;                           // offset: 12
        map << energy_consumed;               // offset: 16
        map << current_battery;               // offset: 20
        map << battery_remaining;             // offset: 22
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> roll;                          // offset: 4
        map >> pitch;                         // offset: 8
        map >> yaw;                           // offset: 12
        map >> energy_consumed;               // offset: 16
        map >> current_battery;               // offset: 20
        map >> battery_remaining;             // offset: 22
    }
};

} // namespace msg
} // namespace your_custom_dialect
} // namespace mavlink
