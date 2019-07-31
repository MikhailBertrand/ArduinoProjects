#ifndef _ROS_spencer_control_msgs_ComponentStatus_h
#define _ROS_spencer_control_msgs_ComponentStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_control_msgs
{

  class ComponentStatus : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _alive_type;
      _alive_type alive;
      typedef const char* _detail_type;
      _detail_type detail;

    ComponentStatus():
      name(""),
      alive(0),
      detail("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_alive;
      u_alive.real = this->alive;
      *(outbuffer + offset + 0) = (u_alive.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->alive);
      uint32_t length_detail = strlen(this->detail);
      varToArr(outbuffer + offset, length_detail);
      offset += 4;
      memcpy(outbuffer + offset, this->detail, length_detail);
      offset += length_detail;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_alive;
      u_alive.base = 0;
      u_alive.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->alive = u_alive.real;
      offset += sizeof(this->alive);
      uint32_t length_detail;
      arrToVar(length_detail, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_detail; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_detail-1]=0;
      this->detail = (char *)(inbuffer + offset-1);
      offset += length_detail;
     return offset;
    }

    const char * getType(){ return "spencer_control_msgs/ComponentStatus"; };
    const char * getMD5(){ return "b570ce0ae5316c3ad53df1d245486902"; };

  };

}
#endif