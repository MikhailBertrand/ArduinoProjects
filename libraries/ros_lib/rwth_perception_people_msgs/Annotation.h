#ifndef _ROS_rwth_perception_people_msgs_Annotation_h
#define _ROS_rwth_perception_people_msgs_Annotation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rwth_perception_people_msgs
{

  class Annotation : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _frame_type;
      _frame_type frame;
      typedef int64_t _id_type;
      _id_type id;
      typedef float _tlx_type;
      _tlx_type tlx;
      typedef float _tly_type;
      _tly_type tly;
      typedef float _width_type;
      _width_type width;
      typedef float _height_type;
      _height_type height;

    Annotation():
      header(),
      frame(0),
      id(0),
      tlx(0),
      tly(0),
      width(0),
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame;
      u_frame.real = this->frame;
      *(outbuffer + offset + 0) = (u_frame.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frame.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frame.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frame.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_frame.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_frame.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_frame.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_frame.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->frame);
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id);
      offset += serializeAvrFloat64(outbuffer + offset, this->tlx);
      offset += serializeAvrFloat64(outbuffer + offset, this->tly);
      offset += serializeAvrFloat64(outbuffer + offset, this->width);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame;
      u_frame.base = 0;
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->frame = u_frame.real;
      offset += sizeof(this->frame);
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tlx));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tly));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->width));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/Annotation"; };
    const char * getMD5(){ return "1184571960f4db44e163957ee1ece7f4"; };

  };

}
#endif