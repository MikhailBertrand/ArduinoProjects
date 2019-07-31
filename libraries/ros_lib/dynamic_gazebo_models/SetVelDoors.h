#ifndef _ROS_SERVICE_SetVelDoors_h
#define _ROS_SERVICE_SetVelDoors_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_gazebo_models
{

static const char SETVELDOORS[] = "dynamic_gazebo_models/SetVelDoors";

  class SetVelDoorsRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef float _lin_x_type;
      _lin_x_type lin_x;
      typedef float _lin_y_type;
      _lin_y_type lin_y;
      typedef float _ang_z_type;
      _ang_z_type ang_z;

    SetVelDoorsRequest():
      group_name(""),
      lin_x(0),
      lin_y(0),
      ang_z(0)
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
      } u_lin_x;
      u_lin_x.real = this->lin_x;
      *(outbuffer + offset + 0) = (u_lin_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lin_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lin_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lin_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lin_x);
      union {
        float real;
        uint32_t base;
      } u_lin_y;
      u_lin_y.real = this->lin_y;
      *(outbuffer + offset + 0) = (u_lin_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lin_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lin_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lin_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lin_y);
      union {
        float real;
        uint32_t base;
      } u_ang_z;
      u_ang_z.real = this->ang_z;
      *(outbuffer + offset + 0) = (u_ang_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ang_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ang_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ang_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ang_z);
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
      } u_lin_x;
      u_lin_x.base = 0;
      u_lin_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lin_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lin_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lin_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lin_x = u_lin_x.real;
      offset += sizeof(this->lin_x);
      union {
        float real;
        uint32_t base;
      } u_lin_y;
      u_lin_y.base = 0;
      u_lin_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lin_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lin_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lin_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lin_y = u_lin_y.real;
      offset += sizeof(this->lin_y);
      union {
        float real;
        uint32_t base;
      } u_ang_z;
      u_ang_z.base = 0;
      u_ang_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ang_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ang_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ang_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ang_z = u_ang_z.real;
      offset += sizeof(this->ang_z);
     return offset;
    }

    const char * getType(){ return SETVELDOORS; };
    const char * getMD5(){ return "74cd915965cac1dd54daa61248fed7de"; };

  };

  class SetVelDoorsResponse : public ros::Msg
  {
    public:

    SetVelDoorsResponse()
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

    const char * getType(){ return SETVELDOORS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetVelDoors {
    public:
    typedef SetVelDoorsRequest Request;
    typedef SetVelDoorsResponse Response;
  };

}
#endif
