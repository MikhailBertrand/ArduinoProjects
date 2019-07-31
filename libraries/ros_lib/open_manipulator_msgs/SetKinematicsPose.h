#ifndef _ROS_SERVICE_SetKinematicsPose_h
#define _ROS_SERVICE_SetKinematicsPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "open_manipulator_msgs/KinematicsPose.h"

namespace open_manipulator_msgs
{

static const char SETKINEMATICSPOSE[] = "open_manipulator_msgs/SetKinematicsPose";

  class SetKinematicsPoseRequest : public ros::Msg
  {
    public:
      typedef open_manipulator_msgs::KinematicsPose _kinematics_pose_type;
      _kinematics_pose_type kinematics_pose;

    SetKinematicsPoseRequest():
      kinematics_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->kinematics_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->kinematics_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETKINEMATICSPOSE; };
    const char * getMD5(){ return "061ceb25b20ec55ef37bf7bab518c5c3"; };

  };

  class SetKinematicsPoseResponse : public ros::Msg
  {
    public:
      typedef bool _isPlanned_type;
      _isPlanned_type isPlanned;

    SetKinematicsPoseResponse():
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

    const char * getType(){ return SETKINEMATICSPOSE; };
    const char * getMD5(){ return "c4a8e64ceeeccdab98609099e2b0c166"; };

  };

  class SetKinematicsPose {
    public:
    typedef SetKinematicsPoseRequest Request;
    typedef SetKinematicsPoseResponse Response;
  };

}
#endif
