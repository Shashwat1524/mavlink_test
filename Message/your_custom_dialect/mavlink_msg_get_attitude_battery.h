#pragma once
// MESSAGE GET_ATTITUDE_BATTERY PACKING

#define MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY 50000


typedef struct __mavlink_get_attitude_battery_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (Time Since System Boot>.*/
 float roll; /*< [rad] Roll*/
 float pitch; /*< [rad] Pitch*/
 float yaw; /*< [rad] Yaw*/
 int32_t energy_consumed; /*< [hJ] Consumed Energy*/
 int16_t current_battery; /*< [cA] Consumed Charge*/
 int8_t battery_remaining; /*< [%] Remaining Battery*/
} mavlink_get_attitude_battery_t;

#define MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN 23
#define MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN 23
#define MAVLINK_MSG_ID_50000_LEN 23
#define MAVLINK_MSG_ID_50000_MIN_LEN 23

#define MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC 199
#define MAVLINK_MSG_ID_50000_CRC 199



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GET_ATTITUDE_BATTERY { \
    50000, \
    "GET_ATTITUDE_BATTERY", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_get_attitude_battery_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_get_attitude_battery_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_get_attitude_battery_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_get_attitude_battery_t, yaw) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_get_attitude_battery_t, current_battery) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_get_attitude_battery_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 22, offsetof(mavlink_get_attitude_battery_t, battery_remaining) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GET_ATTITUDE_BATTERY { \
    "GET_ATTITUDE_BATTERY", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_get_attitude_battery_t, time_boot_ms) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_get_attitude_battery_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_get_attitude_battery_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_get_attitude_battery_t, yaw) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_get_attitude_battery_t, current_battery) }, \
         { "energy_consumed", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_get_attitude_battery_t, energy_consumed) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 22, offsetof(mavlink_get_attitude_battery_t, battery_remaining) }, \
         } \
}
#endif

/**
 * @brief Pack a get_attitude_battery message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (Time Since System Boot>.
 * @param roll [rad] Roll
 * @param pitch [rad] Pitch
 * @param yaw [rad] Yaw
 * @param current_battery [cA] Consumed Charge
 * @param energy_consumed [hJ] Consumed Energy
 * @param battery_remaining [%] Remaining Battery
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_get_attitude_battery_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float roll, float pitch, float yaw, int16_t current_battery, int32_t energy_consumed, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, energy_consumed);
    _mav_put_int16_t(buf, 20, current_battery);
    _mav_put_int8_t(buf, 22, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
#else
    mavlink_get_attitude_battery_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.energy_consumed = energy_consumed;
    packet.current_battery = current_battery;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
}

/**
 * @brief Pack a get_attitude_battery message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (Time Since System Boot>.
 * @param roll [rad] Roll
 * @param pitch [rad] Pitch
 * @param yaw [rad] Yaw
 * @param current_battery [cA] Consumed Charge
 * @param energy_consumed [hJ] Consumed Energy
 * @param battery_remaining [%] Remaining Battery
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_get_attitude_battery_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, float roll, float pitch, float yaw, int16_t current_battery, int32_t energy_consumed, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, energy_consumed);
    _mav_put_int16_t(buf, 20, current_battery);
    _mav_put_int8_t(buf, 22, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
#else
    mavlink_get_attitude_battery_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.energy_consumed = energy_consumed;
    packet.current_battery = current_battery;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
#endif
}

/**
 * @brief Pack a get_attitude_battery message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (Time Since System Boot>.
 * @param roll [rad] Roll
 * @param pitch [rad] Pitch
 * @param yaw [rad] Yaw
 * @param current_battery [cA] Consumed Charge
 * @param energy_consumed [hJ] Consumed Energy
 * @param battery_remaining [%] Remaining Battery
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_get_attitude_battery_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,float roll,float pitch,float yaw,int16_t current_battery,int32_t energy_consumed,int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, energy_consumed);
    _mav_put_int16_t(buf, 20, current_battery);
    _mav_put_int8_t(buf, 22, battery_remaining);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
#else
    mavlink_get_attitude_battery_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.energy_consumed = energy_consumed;
    packet.current_battery = current_battery;
    packet.battery_remaining = battery_remaining;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
}

/**
 * @brief Encode a get_attitude_battery struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param get_attitude_battery C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_get_attitude_battery_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_get_attitude_battery_t* get_attitude_battery)
{
    return mavlink_msg_get_attitude_battery_pack(system_id, component_id, msg, get_attitude_battery->time_boot_ms, get_attitude_battery->roll, get_attitude_battery->pitch, get_attitude_battery->yaw, get_attitude_battery->current_battery, get_attitude_battery->energy_consumed, get_attitude_battery->battery_remaining);
}

/**
 * @brief Encode a get_attitude_battery struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param get_attitude_battery C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_get_attitude_battery_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_get_attitude_battery_t* get_attitude_battery)
{
    return mavlink_msg_get_attitude_battery_pack_chan(system_id, component_id, chan, msg, get_attitude_battery->time_boot_ms, get_attitude_battery->roll, get_attitude_battery->pitch, get_attitude_battery->yaw, get_attitude_battery->current_battery, get_attitude_battery->energy_consumed, get_attitude_battery->battery_remaining);
}

/**
 * @brief Encode a get_attitude_battery struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param get_attitude_battery C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_get_attitude_battery_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_get_attitude_battery_t* get_attitude_battery)
{
    return mavlink_msg_get_attitude_battery_pack_status(system_id, component_id, _status, msg,  get_attitude_battery->time_boot_ms, get_attitude_battery->roll, get_attitude_battery->pitch, get_attitude_battery->yaw, get_attitude_battery->current_battery, get_attitude_battery->energy_consumed, get_attitude_battery->battery_remaining);
}

/**
 * @brief Send a get_attitude_battery message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (Time Since System Boot>.
 * @param roll [rad] Roll
 * @param pitch [rad] Pitch
 * @param yaw [rad] Yaw
 * @param current_battery [cA] Consumed Charge
 * @param energy_consumed [hJ] Consumed Energy
 * @param battery_remaining [%] Remaining Battery
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_get_attitude_battery_send(mavlink_channel_t chan, uint32_t time_boot_ms, float roll, float pitch, float yaw, int16_t current_battery, int32_t energy_consumed, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, energy_consumed);
    _mav_put_int16_t(buf, 20, current_battery);
    _mav_put_int8_t(buf, 22, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY, buf, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
#else
    mavlink_get_attitude_battery_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.energy_consumed = energy_consumed;
    packet.current_battery = current_battery;
    packet.battery_remaining = battery_remaining;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY, (const char *)&packet, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
#endif
}

/**
 * @brief Send a get_attitude_battery message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_get_attitude_battery_send_struct(mavlink_channel_t chan, const mavlink_get_attitude_battery_t* get_attitude_battery)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_get_attitude_battery_send(chan, get_attitude_battery->time_boot_ms, get_attitude_battery->roll, get_attitude_battery->pitch, get_attitude_battery->yaw, get_attitude_battery->current_battery, get_attitude_battery->energy_consumed, get_attitude_battery->battery_remaining);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY, (const char *)get_attitude_battery, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
#endif
}

#if MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_get_attitude_battery_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, float roll, float pitch, float yaw, int16_t current_battery, int32_t energy_consumed, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, roll);
    _mav_put_float(buf, 8, pitch);
    _mav_put_float(buf, 12, yaw);
    _mav_put_int32_t(buf, 16, energy_consumed);
    _mav_put_int16_t(buf, 20, current_battery);
    _mav_put_int8_t(buf, 22, battery_remaining);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY, buf, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
#else
    mavlink_get_attitude_battery_t *packet = (mavlink_get_attitude_battery_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->energy_consumed = energy_consumed;
    packet->current_battery = current_battery;
    packet->battery_remaining = battery_remaining;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY, (const char *)packet, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_MIN_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_CRC);
#endif
}
#endif

#endif

// MESSAGE GET_ATTITUDE_BATTERY UNPACKING


/**
 * @brief Get field time_boot_ms from get_attitude_battery message
 *
 * @return [ms] Timestamp (Time Since System Boot>.
 */
static inline uint32_t mavlink_msg_get_attitude_battery_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field roll from get_attitude_battery message
 *
 * @return [rad] Roll
 */
static inline float mavlink_msg_get_attitude_battery_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pitch from get_attitude_battery message
 *
 * @return [rad] Pitch
 */
static inline float mavlink_msg_get_attitude_battery_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yaw from get_attitude_battery message
 *
 * @return [rad] Yaw
 */
static inline float mavlink_msg_get_attitude_battery_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field current_battery from get_attitude_battery message
 *
 * @return [cA] Consumed Charge
 */
static inline int16_t mavlink_msg_get_attitude_battery_get_current_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field energy_consumed from get_attitude_battery message
 *
 * @return [hJ] Consumed Energy
 */
static inline int32_t mavlink_msg_get_attitude_battery_get_energy_consumed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field battery_remaining from get_attitude_battery message
 *
 * @return [%] Remaining Battery
 */
static inline int8_t mavlink_msg_get_attitude_battery_get_battery_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  22);
}

/**
 * @brief Decode a get_attitude_battery message into a struct
 *
 * @param msg The message to decode
 * @param get_attitude_battery C-struct to decode the message contents into
 */
static inline void mavlink_msg_get_attitude_battery_decode(const mavlink_message_t* msg, mavlink_get_attitude_battery_t* get_attitude_battery)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    get_attitude_battery->time_boot_ms = mavlink_msg_get_attitude_battery_get_time_boot_ms(msg);
    get_attitude_battery->roll = mavlink_msg_get_attitude_battery_get_roll(msg);
    get_attitude_battery->pitch = mavlink_msg_get_attitude_battery_get_pitch(msg);
    get_attitude_battery->yaw = mavlink_msg_get_attitude_battery_get_yaw(msg);
    get_attitude_battery->energy_consumed = mavlink_msg_get_attitude_battery_get_energy_consumed(msg);
    get_attitude_battery->current_battery = mavlink_msg_get_attitude_battery_get_current_battery(msg);
    get_attitude_battery->battery_remaining = mavlink_msg_get_attitude_battery_get_battery_remaining(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN? msg->len : MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN;
        memset(get_attitude_battery, 0, MAVLINK_MSG_ID_GET_ATTITUDE_BATTERY_LEN);
    memcpy(get_attitude_battery, _MAV_PAYLOAD(msg), len);
#endif
}
