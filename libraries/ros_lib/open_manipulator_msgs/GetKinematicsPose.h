#ifndef _ROS_SERVICE_GetKinematicsPose_h
#define _ROS_SERVICE_GetKinematicsPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "open_manipulator_msgs/KinematicsPose.h"
#include "std_msgs/Header.h"

namespace open_manipulator_msgs
{

static const char GETKINEMATICSPOSE[] = "open_manipulator_msgs/GetKinematicsPose";

  class GetKinematicsPoseRequest : public ros::Msg
  {
    public:

    GetKinematicsPoseRequest()
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

    const char * getType(){ return GETKINEMATICSPOSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetKinematicsPoseResponse : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef open_manipulator_msgs::KinematicsPose _kinematics_pose_type;
      _kinematics_pose_type kinematics_pose;

    GetKinematicsPoseResponse():
      header(),
      kinematics_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->kinematics_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->kinematics_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETKINEMATICSPOSE; };
    const char * getMD5(){ return "38159623face299098e8c400633c675e"; };

  };

  class GetKinematicsPose {
    public:
    typedef GetKinematicsPoseRequest Request;
    typedef GetKinematicsPoseResponse Response;
  };

}
#endif
