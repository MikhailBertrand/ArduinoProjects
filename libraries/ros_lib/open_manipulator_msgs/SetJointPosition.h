#ifndef _ROS_SERVICE_SetJointPosition_h
#define _ROS_SERVICE_SetJointPosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "open_manipulator_msgs/JointPosition.h"

namespace open_manipulator_msgs
{

static const char SETJOINTPOSITION[] = "open_manipulator_msgs/SetJointPosition";

  class SetJointPositionRequest : public ros::Msg
  {
    public:
      typedef open_manipulator_msgs::JointPosition _joint_position_type;
      _joint_position_type joint_position;

    SetJointPositionRequest():
      joint_position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETJOINTPOSITION; };
    const char * getMD5(){ return "e1f1ee99b5e77308297dc4eeedd305d4"; };

  };

  class SetJointPositionResponse : public ros::Msg
  {
    public:
      typedef bool _isPlanned_type;
      _isPlanned_type isPlanned;

    SetJointPositionResponse():
      isPlanned(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isPlanned;
      u_isPlanned.real = this->isPlanned;
      *(outbuffer + offset + 0) = (u_isPlanned.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isPlanned);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isPlanned;
      u_isPlanned.base = 0;
      u_isPlanned.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isPlanned = u_isPlanned.real;
      offset += sizeof(this->isPlanned);
     return offset;
    }

    const char * getType(){ return SETJOINTPOSITION; };
    const char * getMD5(){ return "c4a8e64ceeeccdab98609099e2b0c166"; };

  };

  class SetJointPosition {
    public:
    typedef SetJointPositionRequest Request;
    typedef SetJointPositionResponse Response;
  };

}
#endif
