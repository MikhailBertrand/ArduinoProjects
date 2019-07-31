#ifndef _ROS_SERVICE_SetElevProps_h
#define _ROS_SERVICE_SetElevProps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_gazebo_models
{

static const char SETELEVPROPS[] = "dynamic_gazebo_models/SetElevProps";

  class SetElevPropsRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef float _force_type;
      _force_type force;
      typedef float _velocity_type;
      _velocity_type velocity;

    SetElevPropsRequest():
      group_name(""),
      force(0),
      velocity(0)
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
        float real;
        uint32_t base;
      } u_force;
      u_force.real = this->force;
      *(outbuffer + offset + 0) = (u_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
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
        float real;
        uint32_t base;
      } u_force;
      u_force.base = 0;
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force = u_force.real;
      offset += sizeof(this->force);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
     return offset;
    }

    const char * getType(){ return SETELEVPROPS; };
    const char * getMD5(){ return "29e60d576a51a97591e15e29e4cbeb9a"; };

  };

  class SetElevPropsResponse : public ros::Msg
  {
    public:

    SetElevPropsResponse()
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

    const char * getType(){ return SETELEVPROPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetElevProps {
    public:
    typedef SetElevPropsRequest Request;
    typedef SetElevPropsResponse Response;
  };

}
#endif
