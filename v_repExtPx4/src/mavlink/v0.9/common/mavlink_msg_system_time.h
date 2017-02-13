#pragma once
// MESSAGE SYSTEM_TIME PACKING

#define MAVLINK_MSG_ID_SYSTEM_TIME 2

MAVPACKED(
typedef struct __mavlink_system_time_t {
 uint64_t time_usec; /*< Timestamp of the master clock in microseconds since UNIX epoch.*/
}) mavlink_system_time_t;

#define MAVLINK_MSG_ID_SYSTEM_TIME_LEN 8
#define MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN 8
#define MAVLINK_MSG_ID_2_LEN 8
#define MAVLINK_MSG_ID_2_MIN_LEN 8

#define MAVLINK_MSG_ID_SYSTEM_TIME_CRC 190
#define MAVLINK_MSG_ID_2_CRC 190



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME { \
    2, \
    "SYSTEM_TIME", \
    1, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_time_t, time_usec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_TIME { \
    "SYSTEM_TIME", \
    1, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_time_t, time_usec) }, \
         } \
}
#endif

/**
 * @brief Pack a system_time message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp of the master clock in microseconds since UNIX epoch.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_time_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_TIME_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
#else
    mavlink_system_time_t packet;
    packet.time_usec = time_usec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_TIME;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
}

/**
 * @brief Pack a system_time message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp of the master clock in microseconds since UNIX epoch.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_time_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_TIME_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
#else
    mavlink_system_time_t packet;
    packet.time_usec = time_usec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_TIME;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
}

/**
 * @brief Encode a system_time struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param system_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_time_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_system_time_t* system_time)
{
    return mavlink_msg_system_time_pack(system_id, component_id, msg, system_time->time_usec);
}

/**
 * @brief Encode a system_time struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_time_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_system_time_t* system_time)
{
    return mavlink_msg_system_time_pack_chan(system_id, component_id, chan, msg, system_time->time_usec);
}

/**
 * @brief Send a system_time message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp of the master clock in microseconds since UNIX epoch.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_system_time_send(mavlink_channel_t chan, uint64_t time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_TIME_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME, buf, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
#else
    mavlink_system_time_t packet;
    packet.time_usec = time_usec;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME, (const char *)&packet, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
#endif
}

/**
 * @brief Send a system_time message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_system_time_send_struct(mavlink_channel_t chan, const mavlink_system_time_t* system_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_system_time_send(chan, system_time->time_usec);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME, (const char *)system_time, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYSTEM_TIME_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_system_time_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME, buf, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
#else
    mavlink_system_time_t *packet = (mavlink_system_time_t *)msgbuf;
    packet->time_usec = time_usec;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_TIME, (const char *)packet, MAVLINK_MSG_ID_SYSTEM_TIME_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_LEN, MAVLINK_MSG_ID_SYSTEM_TIME_CRC);
#endif
}
#endif

#endif

// MESSAGE SYSTEM_TIME UNPACKING


/**
 * @brief Get field time_usec from system_time message
 *
 * @return Timestamp of the master clock in microseconds since UNIX epoch.
 */
static inline uint64_t mavlink_msg_system_time_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a system_time message into a struct
 *
 * @param msg The message to decode
 * @param system_time C-struct to decode the message contents into
 */
static inline void mavlink_msg_system_time_decode(const mavlink_message_t* msg, mavlink_system_time_t* system_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    system_time->time_usec = mavlink_msg_system_time_get_time_usec(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYSTEM_TIME_LEN? msg->len : MAVLINK_MSG_ID_SYSTEM_TIME_LEN;
        memset(system_time, 0, MAVLINK_MSG_ID_SYSTEM_TIME_LEN);
    memcpy(system_time, _MAV_PAYLOAD(msg), len);
#endif
}
