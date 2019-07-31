#ifndef _ROS_spencer_tracking_msgs_TrackedPerson_h
#define _ROS_spencer_tracking_msgs_TrackedPerson_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/TwistWithCovariance.h"

namespace spencer_tracking_msgs
{

  class TrackedPerson : public ros::Msg
  {
    public:
      typedef uint64_t _track_id_type;
      _track_id_type track_id;
      typedef bool _is_occluded_type;
      _is_occluded_type is_occluded;
      typedef bool _is_matched_type;
      _is_matched_type is_matched;
      typedef uint64_t _detection_id_type;
      _detection_id_type detection_id;
      typedef ros::Duration _age_type;
      _age_type age;
      typedef geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;
      typedef geometry_msgs::TwistWithCovariance _twist_type;
      _twist_type twist;

    TrackedPerson():
      track_id(0),
      is_occluded(0),
      is_matched(0),
      detection_id(0),
      age(),
      pose(),
      twist()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.real = this->track_id;
      *(outbuffer + offset + 0) = (u_track_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_id);
      union {
        bool real;
        uint8_t base;
      } u_is_occluded;
      u_is_occluded.real = this->is_occluded;
      *(outbuffer + offset + 0) = (u_is_occluded.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_occluded);
      union {
        bool real;
        uint8_t base;
      } u_is_matched;
      u_is_matched.real = this->is_matched;
      *(outbuffer + offset + 0) = (u_is_matched.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_matched);
      union {
        uint64_t real;
        uint32_t base;
      } u_detection_id;
      u_detection_id.real = this->detection_id;
      *(outbuffer + offset + 0) = (u_detection_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detection_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detection_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detection_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_id);
      *(outbuffer + offset + 0) = (this->age.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.sec);
      *(outbuffer + offset + 0) = (this->age.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.nsec);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.base = 0;
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->track_id = u_track_id.real;
      offset += sizeof(this->track_id);
      union {
        bool real;
        uint8_t base;
      } u_is_occluded;
      u_is_occluded.base = 0;
      u_is_occluded.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_occluded = u_is_occluded.real;
      offset += sizeof(this->is_occluded);
      union {
        bool real;
        uint8_t base;
      } u_is_matched;
      u_is_matched.base = 0;
      u_is_matched.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_matched = u_is_matched.real;
      offset += sizeof(this->is_matched);
      union {
        uint64_t real;
        uint32_t base;
      } u_detection_id;
      u_detection_id.base = 0;
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detection_id = u_detection_id.real;
      offset += sizeof(this->detection_id);
      this->age.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.sec);
      this->age.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.nsec);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/TrackedPerson"; };
    const char * getMD5(){ return "28bdd0d6d6551c668e4fde8aecdf1885"; };

  };

}
#endif