#ifndef _ROS_SERVICE_GetJointPosition_h
#define _ROS_SERVICE_GetJointPosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "open_manipulator_msgs/JointPosition.h"

namespace open_manipulator_msgs
{

static const char GETJOINTPOSITION[] = "open_manipulator_msgs/GetJointPosition";

  class GetJointPositionRequest : public ros::Msg
  {
    public:

    GetJointPositionRequest()
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

    const char * getType(){ return GETJOINTPOSITION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetJointPositionResponse : public ros::Msg
  {
    public:
      typedef open_manipulator_msgs::JointPosition _joint_position_type;
      _joint_position_type joint_position;

    GetJointPositionResponse():
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

    const char * getType(){ return GETJOINTPOSITION; };
    const char * getMD5(){ return "e1f1ee99b5e77308297dc4eeedd305d4"; };

  };

  class GetJointPosition {
    public:
    typedef GetJointPositionRequest Request;
    typedef GetJointPositionResponse Response;
  };

}
#endif
