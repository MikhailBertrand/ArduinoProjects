#ifndef _ROS_SERVICE_TargetFloorElev_h
#define _ROS_SERVICE_TargetFloorElev_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_gazebo_models
{

static const char TARGETFLOORELEV[] = "dynamic_gazebo_models/TargetFloorElev";

  class TargetFloorElevRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef int32_t _target_floor_type;
      _target_floor_type target_floor;

    TargetFloorElevRequest():
      group_name(""),
      target_floor(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      union {
        int32_t real;
        uint32_t base;
      } u_target_floor;
      u_target_floor.real = this->target_floor;
      *(outbuffer + offset + 0) = (u_target_floor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_floor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_floor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_floor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_floor);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      union {
        int32_t real;
        uint32_t base;
      } u_target_floor;
      u_target_floor.base = 0;
      u_target_floor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_floor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_floor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_floor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_floor = u_target_floor.real;
      offset += sizeof(this->target_floor);
     return offset;
    }

    const char * getType(){ return TARGETFLOORELEV; };
    const char * getMD5(){ return "3594019c126708164ced651eb96e7c99"; };

  };

  class TargetFloorElevResponse : public ros::Msg
  {
    public:

    TargetFloorElevResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return TARGETFLOORELEV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TargetFloorElev {
    public:
    typedef TargetFloorElevRequest Request;
    typedef TargetFloorElevResponse Response;
  };

}
#endif
