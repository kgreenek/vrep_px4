#pragma once
// MESSAGE SLUGS_ACTION PACKING

#define MAVLINK_MSG_ID_SLUGS_ACTION 183

MAVPACKED(
typedef struct __mavlink_slugs_action_t {
 uint8_t target; /*< The system reporting the action*/
 uint8_t actionId; /*< Action ID. See apDefinitions.h in the SLUGS /clib directory for the ID names*/
 uint16_t actionVal; /*< Value associated with the action*/
}) mavlink_slugs_action_t;

#define MAVLINK_MSG_ID_SLUGS_ACTION_LEN 4
#define MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN 4
#define MAVLINK_MSG_ID_183_LEN 4
#define MAVLINK_MSG_ID_183_MIN_LEN 4

#define MAVLINK_MSG_ID_SLUGS_ACTION_CRC 202
#define MAVLINK_MSG_ID_183_CRC 202



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SLUGS_ACTION { \
    183, \
    "SLUGS_ACTION", \
    3, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_slugs_action_t, target) }, \
         { "actionId", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_slugs_action_t, actionId) }, \
         { "actionVal", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_slugs_action_t, actionVal) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SLUGS_ACTION { \
    "SLUGS_ACTION", \
    3, \
    {  { "target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_slugs_action_t, target) }, \
         { "actionId", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_slugs_action_t, actionId) }, \
         { "actionVal", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_slugs_action_t, actionVal) }, \
         } \
}
#endif

/**
 * @brief Pack a slugs_action message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target The system reporting the action
 * @param actionId Action ID. See apDefinitions.h in the SLUGS /clib directory for the ID names
 * @param actionVal Value associated with the action
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slugs_action_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target, uint8_t actionId, uint16_t actionVal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLUGS_ACTION_LEN];
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, actionId);
    _mav_put_uint16_t(buf, 2, actionVal);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SLUGS_ACTION_LEN);
#else
    mavlink_slugs_action_t packet;
    packet.target = target;
    packet.actionId = actionId;
    packet.actionVal = actionVal;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SLUGS_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SLUGS_ACTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_CRC);
}

/**
 * @brief Pack a slugs_action message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system reporting the action
 * @param actionId Action ID. See apDefinitions.h in the SLUGS /clib directory for the ID names
 * @param actionVal Value associated with the action
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slugs_action_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target,uint8_t actionId,uint16_t actionVal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLUGS_ACTION_LEN];
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, actionId);
    _mav_put_uint16_t(buf, 2, actionVal);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SLUGS_ACTION_LEN);
#else
    mavlink_slugs_action_t packet;
    packet.target = target;
    packet.actionId = actionId;
    packet.actionVal = actionVal;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SLUGS_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SLUGS_ACTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_CRC);
}

/**
 * @brief Encode a slugs_action struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param slugs_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slugs_action_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_slugs_action_t* slugs_action)
{
    return mavlink_msg_slugs_action_pack(system_id, component_id, msg, slugs_action->target, slugs_action->actionId, slugs_action->actionVal);
}

/**
 * @brief Encode a slugs_action struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param slugs_action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slugs_action_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_slugs_action_t* slugs_action)
{
    return mavlink_msg_slugs_action_pack_chan(system_id, component_id, chan, msg, slugs_action->target, slugs_action->actionId, slugs_action->actionVal);
}

/**
 * @brief Send a slugs_action message
 * @param chan MAVLink channel to send the message
 *
 * @param target The system reporting the action
 * @param actionId Action ID. See apDefinitions.h in the SLUGS /clib directory for the ID names
 * @param actionVal Value associated with the action
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_slugs_action_send(mavlink_channel_t chan, uint8_t target, uint8_t actionId, uint16_t actionVal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SLUGS_ACTION_LEN];
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, actionId);
    _mav_put_uint16_t(buf, 2, actionVal);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLUGS_ACTION, buf, MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_CRC);
#else
    mavlink_slugs_action_t packet;
    packet.target = target;
    packet.actionId = actionId;
    packet.actionVal = actionVal;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLUGS_ACTION, (const char *)&packet, MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_CRC);
#endif
}

/**
 * @brief Send a slugs_action message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_slugs_action_send_struct(mavlink_channel_t chan, const mavlink_slugs_action_t* slugs_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_slugs_action_send(chan, slugs_action->target, slugs_action->actionId, slugs_action->actionVal);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLUGS_ACTION, (const char *)slugs_action, MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_SLUGS_ACTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_slugs_action_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target, uint8_t actionId, uint16_t actionVal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target);
    _mav_put_uint8_t(buf, 1, actionId);
    _mav_put_uint16_t(buf, 2, actionVal);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLUGS_ACTION, buf, MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_CRC);
#else
    mavlink_slugs_action_t *packet = (mavlink_slugs_action_t *)msgbuf;
    packet->target = target;
    packet->actionId = actionId;
    packet->actionVal = actionVal;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SLUGS_ACTION, (const char *)packet, MAVLINK_MSG_ID_SLUGS_ACTION_MIN_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_LEN, MAVLINK_MSG_ID_SLUGS_ACTION_CRC);
#endif
}
#endif

#endif

// MESSAGE SLUGS_ACTION UNPACKING


/**
 * @brief Get field target from slugs_action message
 *
 * @return The system reporting the action
 */
static inline uint8_t mavlink_msg_slugs_action_get_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field actionId from slugs_action message
 *
 * @return Action ID. See apDefinitions.h in the SLUGS /clib directory for the ID names
 */
static inline uint8_t mavlink_msg_slugs_action_get_actionId(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field actionVal from slugs_action message
 *
 * @return Value associated with the action
 */
static inline uint16_t mavlink_msg_slugs_action_get_actionVal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a slugs_action message into a struct
 *
 * @param msg The message to decode
 * @param slugs_action C-struct to decode the message contents into
 */
static inline void mavlink_msg_slugs_action_decode(const mavlink_message_t* msg, mavlink_slugs_action_t* slugs_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    slugs_action->target = mavlink_msg_slugs_action_get_target(msg);
    slugs_action->actionId = mavlink_msg_slugs_action_get_actionId(msg);
    slugs_action->actionVal = mavlink_msg_slugs_action_get_actionVal(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SLUGS_ACTION_LEN? msg->len : MAVLINK_MSG_ID_SLUGS_ACTION_LEN;
        memset(slugs_action, 0, MAVLINK_MSG_ID_SLUGS_ACTION_LEN);
    memcpy(slugs_action, _MAV_PAYLOAD(msg), len);
#endif
}
