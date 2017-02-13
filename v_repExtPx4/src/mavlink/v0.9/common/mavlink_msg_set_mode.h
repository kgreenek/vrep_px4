#pragma once
// MESSAGE SET_MODE PACKING

#define MAVLINK_MSG_ID_SET_MODE 11

MAVPACKED(
typedef struct __mavlink_set_mode_t {
 uint8_t target; /*< The system setting the mode*/
 uint8_t mode; /*< The new mode*/
}) mavlink_set_mode_t;

#define MAVLINK_MSG_ID_SET_MODE_LEN 2
#define MAVLINK_MSG_ID_SET_MODE_MIN_LEN 2
#define MAVLINK_MSG_ID_11_LEN 2
#define MAVLINK_MSG_ID_11_MIN_LEN 2

#define MAVLINK_MSG_ID_SET_MODE_CRC 186
#define MAVLINK_MSG_ID_11_CRC 186



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    11, \
    "SET_MODE", \
    2, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_mode_t, target) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_set_mode_t, mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    "SET_MODE", \
    2, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_set_mode_t, target) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_set_mode_t, mode) }, \
         } \
}
#endif

/**
 * @brief Pack a set_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target The system setting the mode
 * @param mode The new mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MODE_LEN);
#else
    mavlink_set_mode_t packet;
    packet.target = target;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
}

/**
 * @brief Pack a set_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system setting the mode
 * @param mode The new mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target,uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MODE_LEN);
#else
    mavlink_set_mode_t packet;
    packet.target = target;
    packet.mode = mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
}

/**
 * @brief Encode a set_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
    return mavlink_msg_set_mode_pack(system_id, component_id, msg, set_mode->target, set_mode->mode);
}

/**
 * @brief Encode a set_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
    return mavlink_msg_set_mode_pack_chan(system_id, component_id, chan, msg, set_mode->target, set_mode->mode);
}

/**
 * @brief Send a set_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param target The system setting the mode
 * @param mode The new mode
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_mode_send(mavlink_channel_t chan, uint8_t target, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, buf, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
#else
    mavlink_set_mode_t packet;
    packet.target = target;
    packet.mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, (const char *)&packet, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
#endif
}

/**
 * @brief Send a set_mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_mode_send_struct(mavlink_channel_t chan, const mavlink_set_mode_t* set_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_mode_send(chan, set_mode->target, set_mode->mode);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, (const char *)set_mode, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target, uint8_t mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, buf, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
#else
    mavlink_set_mode_t *packet = (mavlink_set_mode_t *)msgbuf;
    packet->target = target;
    packet->mode = mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, (const char *)packet, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_MODE UNPACKING


/**
 * @brief Get field target from set_mode message
 *
 * @return The system setting the mode
 */
static inline uint8_t mavlink_msg_set_mode_get_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field mode from set_mode message
 *
 * @return The new mode
 */
static inline uint8_t mavlink_msg_set_mode_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a set_mode message into a struct
 *
 * @param msg The message to decode
 * @param set_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_mode_decode(const mavlink_message_t* msg, mavlink_set_mode_t* set_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_mode->target = mavlink_msg_set_mode_get_target(msg);
    set_mode->mode = mavlink_msg_set_mode_get_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_MODE_LEN? msg->len : MAVLINK_MSG_ID_SET_MODE_LEN;
        memset(set_mode, 0, MAVLINK_MSG_ID_SET_MODE_LEN);
    memcpy(set_mode, _MAV_PAYLOAD(msg), len);
#endif
}
