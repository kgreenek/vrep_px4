#pragma once
// MESSAGE OBJECT_DETECTION_EVENT PACKING

#define MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT 140

MAVPACKED(
typedef struct __mavlink_object_detection_event_t {
 uint32_t time; /*< Timestamp in milliseconds since system boot*/
 uint16_t object_id; /*< Object ID*/
 uint8_t type; /*< Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal*/
 char name[20]; /*< Name of the object as defined by the detector*/
 uint8_t quality; /*< Detection quality / confidence. 0: bad, 255: maximum confidence*/
 float bearing; /*< Angle of the object with respect to the body frame in NED coordinates in radians. 0: front*/
 float distance; /*< Ground distance in meters*/
}) mavlink_object_detection_event_t;

#define MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN 36
#define MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN 36
#define MAVLINK_MSG_ID_140_LEN 36
#define MAVLINK_MSG_ID_140_MIN_LEN 36

#define MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC 155
#define MAVLINK_MSG_ID_140_CRC 155

#define MAVLINK_MSG_OBJECT_DETECTION_EVENT_FIELD_NAME_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OBJECT_DETECTION_EVENT { \
    140, \
    "OBJECT_DETECTION_EVENT", \
    7, \
    {  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_object_detection_event_t, time) }, \
         { "object_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_object_detection_event_t, object_id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_object_detection_event_t, type) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 20, 7, offsetof(mavlink_object_detection_event_t, name) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_object_detection_event_t, quality) }, \
         { "bearing", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_object_detection_event_t, bearing) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_object_detection_event_t, distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OBJECT_DETECTION_EVENT { \
    "OBJECT_DETECTION_EVENT", \
    7, \
    {  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_object_detection_event_t, time) }, \
         { "object_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_object_detection_event_t, object_id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_object_detection_event_t, type) }, \
         { "name", NULL, MAVLINK_TYPE_CHAR, 20, 7, offsetof(mavlink_object_detection_event_t, name) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_object_detection_event_t, quality) }, \
         { "bearing", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_object_detection_event_t, bearing) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_object_detection_event_t, distance) }, \
         } \
}
#endif

/**
 * @brief Pack a object_detection_event message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time Timestamp in milliseconds since system boot
 * @param object_id Object ID
 * @param type Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 * @param name Name of the object as defined by the detector
 * @param quality Detection quality / confidence. 0: bad, 255: maximum confidence
 * @param bearing Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 * @param distance Ground distance in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_object_detection_event_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time, uint16_t object_id, uint8_t type, const char *name, uint8_t quality, float bearing, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN];
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_uint16_t(buf, 4, object_id);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 27, quality);
    _mav_put_float(buf, 28, bearing);
    _mav_put_float(buf, 32, distance);
    _mav_put_char_array(buf, 7, name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN);
#else
    mavlink_object_detection_event_t packet;
    packet.time = time;
    packet.object_id = object_id;
    packet.type = type;
    packet.quality = quality;
    packet.bearing = bearing;
    packet.distance = distance;
    mav_array_memcpy(packet.name, name, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC);
}

/**
 * @brief Pack a object_detection_event message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time Timestamp in milliseconds since system boot
 * @param object_id Object ID
 * @param type Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 * @param name Name of the object as defined by the detector
 * @param quality Detection quality / confidence. 0: bad, 255: maximum confidence
 * @param bearing Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 * @param distance Ground distance in meters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_object_detection_event_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time,uint16_t object_id,uint8_t type,const char *name,uint8_t quality,float bearing,float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN];
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_uint16_t(buf, 4, object_id);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 27, quality);
    _mav_put_float(buf, 28, bearing);
    _mav_put_float(buf, 32, distance);
    _mav_put_char_array(buf, 7, name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN);
#else
    mavlink_object_detection_event_t packet;
    packet.time = time;
    packet.object_id = object_id;
    packet.type = type;
    packet.quality = quality;
    packet.bearing = bearing;
    packet.distance = distance;
    mav_array_memcpy(packet.name, name, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC);
}

/**
 * @brief Encode a object_detection_event struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param object_detection_event C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_object_detection_event_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_object_detection_event_t* object_detection_event)
{
    return mavlink_msg_object_detection_event_pack(system_id, component_id, msg, object_detection_event->time, object_detection_event->object_id, object_detection_event->type, object_detection_event->name, object_detection_event->quality, object_detection_event->bearing, object_detection_event->distance);
}

/**
 * @brief Encode a object_detection_event struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param object_detection_event C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_object_detection_event_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_object_detection_event_t* object_detection_event)
{
    return mavlink_msg_object_detection_event_pack_chan(system_id, component_id, chan, msg, object_detection_event->time, object_detection_event->object_id, object_detection_event->type, object_detection_event->name, object_detection_event->quality, object_detection_event->bearing, object_detection_event->distance);
}

/**
 * @brief Send a object_detection_event message
 * @param chan MAVLink channel to send the message
 *
 * @param time Timestamp in milliseconds since system boot
 * @param object_id Object ID
 * @param type Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 * @param name Name of the object as defined by the detector
 * @param quality Detection quality / confidence. 0: bad, 255: maximum confidence
 * @param bearing Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 * @param distance Ground distance in meters
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_object_detection_event_send(mavlink_channel_t chan, uint32_t time, uint16_t object_id, uint8_t type, const char *name, uint8_t quality, float bearing, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN];
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_uint16_t(buf, 4, object_id);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 27, quality);
    _mav_put_float(buf, 28, bearing);
    _mav_put_float(buf, 32, distance);
    _mav_put_char_array(buf, 7, name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT, buf, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC);
#else
    mavlink_object_detection_event_t packet;
    packet.time = time;
    packet.object_id = object_id;
    packet.type = type;
    packet.quality = quality;
    packet.bearing = bearing;
    packet.distance = distance;
    mav_array_memcpy(packet.name, name, sizeof(char)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT, (const char *)&packet, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC);
#endif
}

/**
 * @brief Send a object_detection_event message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_object_detection_event_send_struct(mavlink_channel_t chan, const mavlink_object_detection_event_t* object_detection_event)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_object_detection_event_send(chan, object_detection_event->time, object_detection_event->object_id, object_detection_event->type, object_detection_event->name, object_detection_event->quality, object_detection_event->bearing, object_detection_event->distance);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT, (const char *)object_detection_event, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC);
#endif
}

#if MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_object_detection_event_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, uint16_t object_id, uint8_t type, const char *name, uint8_t quality, float bearing, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_uint16_t(buf, 4, object_id);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 27, quality);
    _mav_put_float(buf, 28, bearing);
    _mav_put_float(buf, 32, distance);
    _mav_put_char_array(buf, 7, name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT, buf, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC);
#else
    mavlink_object_detection_event_t *packet = (mavlink_object_detection_event_t *)msgbuf;
    packet->time = time;
    packet->object_id = object_id;
    packet->type = type;
    packet->quality = quality;
    packet->bearing = bearing;
    packet->distance = distance;
    mav_array_memcpy(packet->name, name, sizeof(char)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT, (const char *)packet, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_MIN_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_CRC);
#endif
}
#endif

#endif

// MESSAGE OBJECT_DETECTION_EVENT UNPACKING


/**
 * @brief Get field time from object_detection_event message
 *
 * @return Timestamp in milliseconds since system boot
 */
static inline uint32_t mavlink_msg_object_detection_event_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field object_id from object_detection_event message
 *
 * @return Object ID
 */
static inline uint16_t mavlink_msg_object_detection_event_get_object_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field type from object_detection_event message
 *
 * @return Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
 */
static inline uint8_t mavlink_msg_object_detection_event_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field name from object_detection_event message
 *
 * @return Name of the object as defined by the detector
 */
static inline uint16_t mavlink_msg_object_detection_event_get_name(const mavlink_message_t* msg, char *name)
{
    return _MAV_RETURN_char_array(msg, name, 20,  7);
}

/**
 * @brief Get field quality from object_detection_event message
 *
 * @return Detection quality / confidence. 0: bad, 255: maximum confidence
 */
static inline uint8_t mavlink_msg_object_detection_event_get_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field bearing from object_detection_event message
 *
 * @return Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
 */
static inline float mavlink_msg_object_detection_event_get_bearing(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field distance from object_detection_event message
 *
 * @return Ground distance in meters
 */
static inline float mavlink_msg_object_detection_event_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a object_detection_event message into a struct
 *
 * @param msg The message to decode
 * @param object_detection_event C-struct to decode the message contents into
 */
static inline void mavlink_msg_object_detection_event_decode(const mavlink_message_t* msg, mavlink_object_detection_event_t* object_detection_event)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    object_detection_event->time = mavlink_msg_object_detection_event_get_time(msg);
    object_detection_event->object_id = mavlink_msg_object_detection_event_get_object_id(msg);
    object_detection_event->type = mavlink_msg_object_detection_event_get_type(msg);
    mavlink_msg_object_detection_event_get_name(msg, object_detection_event->name);
    object_detection_event->quality = mavlink_msg_object_detection_event_get_quality(msg);
    object_detection_event->bearing = mavlink_msg_object_detection_event_get_bearing(msg);
    object_detection_event->distance = mavlink_msg_object_detection_event_get_distance(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN? msg->len : MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN;
        memset(object_detection_event, 0, MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT_LEN);
    memcpy(object_detection_event, _MAV_PAYLOAD(msg), len);
#endif
}
