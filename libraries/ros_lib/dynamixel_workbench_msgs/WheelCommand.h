#ifndef _ROS_SERVICE_WheelCommand_h
#define _ROS_SERVICE_WheelCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamixel_workbench_msgs
{

static const char WHEELCOMMAND[] = "dynamixel_workbench_msgs/WheelCommand";

  class WheelCommandRequest : public ros::Msg
  {
    public:
      typedef float _right_vel_type;
      _right_vel_type right_vel;
      typedef float _left_vel_type;
      _left_vel_type left_vel;

    WheelCommandRequest():
      right_vel(0),
      left_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_right_vel;
      u_right_vel.real = this->right_vel;
      *(outbuffer + offset + 0) = (u_right_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_vel);
      union {
        float real;
        uint32_t base;
      } u_left_vel;
      u_left_vel.real = this->left_vel;
      *(outbuffer + offset + 0) = (u_left_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_right_vel;
      u_right_vel.base = 0;
      u_right_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_vel = u_right_vel.real;
      offset += sizeof(this->right_vel);
      union {
        float real;
        uint32_t base;
      } u_left_vel;
      u_left_vel.base = 0;
      u_left_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_vel = u_left_vel.real;
      offset += sizeof(this->left_vel);
     return offset;
    }

    const char * getType(){ return WHEELCOMMAND; };
    const char * getMD5(){ return "0cfb8c816ece0d38d0a1c8583bdd4252"; };

  };

  class WheelCommandResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    WheelCommandResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return WHEELCOMMAND; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class WheelCommand {
    public:
    typedef WheelCommandRequest Request;
    typedef WheelCommandResponse Response;
  };

}
#endif
