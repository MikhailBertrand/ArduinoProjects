#ifndef _ROS_spencer_tracking_msgs_TrackedPerson2d_h
#define _ROS_spencer_tracking_msgs_TrackedPerson2d_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_tracking_msgs
{

  class TrackedPerson2d : public ros::Msg
  {
    public:
      typedef uint64_t _track_id_type;
      _track_id_type track_id;
      typedef float _person_height_type;
      _person_height_type person_height;
      typedef int32_t _x_type;
      _x_type x;
      typedef int32_t _y_type;
      _y_type y;
      typedef uint32_t _w_type;
      _w_type w;
      typedef uint32_t _h_type;
      _h_type h;
      typedef float _depth_type;
      _depth_type depth;

    TrackedPerson2d():
      track_id(0),
      person_height(0),
      x(0),
      y(0),
      w(0),
      h(0),
      depth(0)
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
        float real;
        uint32_t base;
      } u_person_height;
      u_person_height.real = this->person_height;
      *(outbuffer + offset + 0) = (u_person_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_person_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_person_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_person_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_height);
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      *(outbuffer + offset + 0) = (this->w >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->w >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->w >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->w >> (8 * 3)) & 0xFF;
      offset += sizeof(this->w);
      *(outbuffer + offset + 0) = (this->h >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->h >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->h >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->h >> (8 * 3)) & 0xFF;
      offset += sizeof(this->h);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.real = this->depth;
      *(outbuffer + offset + 0) = (u_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_depth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->depth);
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
        float real;
        uint32_t base;
      } u_person_height;
      u_person_height.base = 0;
      u_person_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_person_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_person_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_person_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->person_height = u_person_height.real;
      offset += sizeof(this->person_height);
      union {
        int32_t real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int32_t real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      this->w =  ((uint32_t) (*(inbuffer + offset)));
      this->w |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->w |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->w |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->w);
      this->h =  ((uint32_t) (*(inbuffer + offset)));
      this->h |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->h |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->h |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->h);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.base = 0;
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->depth = u_depth.real;
      offset += sizeof(this->depth);
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/TrackedPerson2d"; };
    const char * getMD5(){ return "12df4823c658df0d660d2a5c68ae4aea"; };

  };

}
#endif