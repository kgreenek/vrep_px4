#pragma once
// MESSAGE DEBUG PACKING

#define MAVLINK_MSG_ID_DEBUG 255

MAVPACKED(
typedef struct __mavlink_debug_t {
 uint8_t ind; /*< index of debug variable*/
 float value; /*< DEBUG value*/
}) mavlink_debug_t;

#define MAVLINK_MSG_ID_DEBUG_LEN 5
#define MAVLINK_MSG_ID_DEBUG_MIN_LEN 5
#define MAVLINK_MSG_ID_255_LEN 5
#define MAVLINK_MSG_ID_255_MIN_LEN 5

#define MAVLINK_MSG_ID_DEBUG_CRC 7
#define MAVLINK_MSG_ID_255_CRC 7



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DEBUG { \
    255, \
    "DEBUG", \
    2, \
    {  { "ind", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_debug_t, ind) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 1, offsetof(mavlink_debug_t, value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DEBUG { \
    "DEBUG", \
    2, \
    {  { "ind", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_debug_t, ind) }, \
         { "value", NULL, MAVLINK_TYPE_FLOAT, 0, 1, offsetof(mavlink_debug_t, value) }, \
         } \
}
#endif

/**
 * @brief Pack a debug message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ind index of debug variable
 * @param value DEBUG value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ind, float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_LEN];
    _mav_put_uint8_t(buf, 0, ind);
    _mav_put_float(buf, 1, value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEBUG_LEN);
#else
    mavlink_debug_t packet;
    packet.ind = ind;
    packet.value = value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEBUG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
}

/**
 * @brief Pack a debug message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ind index of debug variable
 * @param value DEBUG value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_debug_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ind,float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_LEN];
    _mav_put_uint8_t(buf, 0, ind);
    _mav_put_float(buf, 1, value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DEBUG_LEN);
#else
    mavlink_debug_t packet;
    packet.ind = ind;
    packet.value = value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DEBUG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
}

/**
 * @brief Encode a debug struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_debug_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_debug_t* debug)
{
    return mavlink_msg_debug_pack(system_id, component_id, msg, debug->ind, debug->value);
}

/**
 * @brief Encode a debug struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_debug_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_debug_t* debug)
{
    return mavlink_msg_debug_pack_chan(system_id, component_id, chan, msg, debug->ind, debug->value);
}

/**
 * @brief Send a debug message
 * @param chan MAVLink channel to send the message
 *
 * @param ind index of debug variable
 * @param value DEBUG value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_debug_send(mavlink_channel_t chan, uint8_t ind, float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DEBUG_LEN];
    _mav_put_uint8_t(buf, 0, ind);
    _mav_put_float(buf, 1, value);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG, buf, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
#else
    mavlink_debug_t packet;
    packet.ind = ind;
    packet.value = value;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG, (const char *)&packet, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
#endif
}

/**
 * @brief Send a debug message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_debug_send_struct(mavlink_channel_t chan, const mavlink_debug_t* debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_debug_send(chan, debug->ind, debug->value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG, (const char *)debug, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
#endif
}

#if MAVLINK_MSG_ID_DEBUG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_debug_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ind, float value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, ind);
    _mav_put_float(buf, 1, value);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG, buf, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
#else
    mavlink_debug_t *packet = (mavlink_debug_t *)msgbuf;
    packet->ind = ind;
    packet->value = value;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DEBUG, (const char *)packet, MAVLINK_MSG_ID_DEBUG_MIN_LEN, MAVLINK_MSG_ID_DEBUG_LEN, MAVLINK_MSG_ID_DEBUG_CRC);
#endif
}
#endif

#endif

// MESSAGE DEBUG UNPACKING


/**
 * @brief Get field ind from debug message
 *
 * @return index of debug variable
 */
static inline uint8_t mavlink_msg_debug_get_ind(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field value from debug message
 *
 * @return DEBUG value
 */
static inline float mavlink_msg_debug_get_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  1);
}

/**
 * @brief Decode a debug message into a struct
 *
 * @param msg The message to decode
 * @param debug C-struct to decode the message contents into
 */
static inline void mavlink_msg_debug_decode(const mavlink_message_t* msg, mavlink_debug_t* debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    debug->ind = mavlink_msg_debug_get_ind(msg);
    debug->value = mavlink_msg_debug_get_value(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DEBUG_LEN? msg->len : MAVLINK_MSG_ID_DEBUG_LEN;
        memset(debug, 0, MAVLINK_MSG_ID_DEBUG_LEN);
    memcpy(debug, _MAV_PAYLOAD(msg), len);
#endif
}
