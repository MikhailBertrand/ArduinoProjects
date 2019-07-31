#ifndef _ROS_SERVICE_OpenCloseElevDoors_h
#define _ROS_SERVICE_OpenCloseElevDoors_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_gazebo_models
{

static const char OPENCLOSEELEVDOORS[] = "dynamic_gazebo_models/OpenCloseElevDoors";

  class OpenCloseElevDoorsRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef bool _state_type;
      _state_type state;

    OpenCloseElevDoorsRequest():
      group_name(""),
      state(0)
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
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
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
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return OPENCLOSEELEVDOORS; };
    const char * getMD5(){ return "c88ad269159bcff927c949ecefd17f59"; };

  };

  class OpenCloseElevDoorsResponse : public ros::Msg
  {
    public:

    OpenCloseElevDoorsResponse()
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

    const char * getType(){ return OPENCLOSEELEVDOORS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenCloseElevDoors {
    public:
    typedef OpenCloseElevDoorsRequest Request;
    typedef OpenCloseElevDoorsResponse Response;
  };

}
#endif
