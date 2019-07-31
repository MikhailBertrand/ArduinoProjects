#ifndef _ROS_rwth_perception_people_msgs_GroundPlane_h
#define _ROS_rwth_perception_people_msgs_GroundPlane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rwth_perception_people_msgs
{

  class GroundPlane : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t n_length;
      typedef float _n_type;
      _n_type st_n;
      _n_type * n;
      typedef float _d_type;
      _d_type d;

    GroundPlane():
      header(),
      n_length(0), n(NULL),
      d(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->n_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->n_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->n_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->n_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->n_length);
      for( uint32_t i = 0; i < n_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->n[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->d);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t n_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      n_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      n_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      n_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->n_length);
      if(n_lengthT > n_length)
        this->n = (float*)realloc(this->n, n_lengthT * sizeof(float));
      n_length = n_lengthT;
      for( uint32_t i = 0; i < n_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_n));
        memcpy( &(this->n[i]), &(this->st_n), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d));
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/GroundPlane"; };
    const char * getMD5(){ return "304eb2260bc88a91236784c7dd166ffd"; };

  };

}
#endif