#ifndef _ROS_dynamixel_workbench_msgs_DynamixelState_h
#define _ROS_dynamixel_workbench_msgs_DynamixelState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamixel_workbench_msgs
{

  class DynamixelState : public ros::Msg
  {
    public:
      typedef const char* _model_name_type;
      _model_name_type model_name;
      typedef uint8_t _id_type;
      _id_type id;
      typedef uint8_t _torque_enable_type;
      _torque_enable_type torque_enable;
      typedef int16_t _goal_current_type;
      _goal_current_type goal_current;
      typedef int32_t _goal_velocity_type;
      _goal_velocity_type goal_velocity;
      typedef int32_t _goal_position_type;
      _goal_position_type goal_position;
      typedef int16_t _present_current_type;
      _present_current_type present_current;
      typedef int32_t _present_velocity_type;
      _present_velocity_type present_velocity;
      typedef int32_t _present_position_type;
      _present_position_type present_position;
      typedef uint8_t _moving_type;
      _moving_type moving;

    DynamixelState():
      model_name(""),
      id(0),
      torque_enable(0),
      goal_current(0),
      goal_velocity(0),
      goal_position(0),
      present_current(0),
      present_velocity(0),
      present_position(0),
      moving(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_name = strlen(this->model_name);
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_model_name);
      offset += length_model_name;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->torque_enable >> (8 * 0)) & 0xFF;
      offset += sizeof(this->torque_enable);
      union {
        int16_t real;
        uint16_t base;
      } u_goal_current;
      u_goal_current.real = this->goal_current;
      *(outbuffer + offset + 0) = (u_goal_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_goal_current.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->goal_current);
      union {
        int32_t real;
        uint32_t base;
      } u_goal_velocity;
      u_goal_velocity.real = this->goal_velocity;
      *(outbuffer + offset + 0) = (u_goal_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_goal_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_goal_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_goal_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->goal_velocity);
      union {
        int32_t real;
        uint32_t base;
      } u_goal_position;
      u_goal_position.real = this->goal_position;
      *(outbuffer + offset + 0) = (u_goal_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_goal_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_goal_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_goal_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->goal_position);
      union {
        int16_t real;
        uint16_t base;
      } u_present_current;
      u_present_current.real = this->present_current;
      *(outbuffer + offset + 0) = (u_present_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_present_current.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->present_current);
      union {
        int32_t real;
        uint32_t base;
      } u_present_velocity;
      u_present_velocity.real = this->present_velocity;
      *(outbuffer + offset + 0) = (u_present_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_present_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_present_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_present_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->present_velocity);
      union {
        int32_t real;
        uint32_t base;
      } u_present_position;
      u_present_position.real = this->present_position;
      *(outbuffer + offset + 0) = (u_present_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_present_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_present_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_present_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->present_position);
      *(outbuffer + offset + 0) = (this->moving >> (8 * 0)) & 0xFF;
      offset += sizeof(this->moving);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->torque_enable =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->torque_enable);
      union {
        int16_t real;
        uint16_t base;
      } u_goal_current;
      u_goal_current.base = 0;
      u_goal_current.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_goal_current.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->goal_current = u_goal_current.real;
      offset += sizeof(this->goal_current);
      union {
        int32_t real;
        uint32_t base;
      } u_goal_velocity;
      u_goal_velocity.base = 0;
      u_goal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_goal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_goal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_goal_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->goal_velocity = u_goal_velocity.real;
      offset += sizeof(this->goal_velocity);
      union {
        int32_t real;
        uint32_t base;
      } u_goal_position;
      u_goal_position.base = 0;
      u_goal_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_goal_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_goal_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_goal_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->goal_position = u_goal_position.real;
      offset += sizeof(this->goal_position);
      union {
        int16_t real;
        uint16_t base;
      } u_present_current;
      u_present_current.base = 0;
      u_present_current.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_present_current.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->present_current = u_present_current.real;
      offset += sizeof(this->present_current);
      union {
        int32_t real;
        uint32_t base;
      } u_present_velocity;
      u_present_velocity.base = 0;
      u_present_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_present_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_present_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_present_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->present_velocity = u_present_velocity.real;
      offset += sizeof(this->present_velocity);
      union {
        int32_t real;
        uint32_t base;
      } u_present_position;
      u_present_position.base = 0;
      u_present_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_present_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_present_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_present_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->present_position = u_present_position.real;
      offset += sizeof(this->present_position);
      this->moving =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->moving);
     return offset;
    }

    const char * getType(){ return "dynamixel_workbench_msgs/DynamixelState"; };
    const char * getMD5(){ return "75ef89ec4862f78146303f5792bac9b7"; };

  };

}
#endif