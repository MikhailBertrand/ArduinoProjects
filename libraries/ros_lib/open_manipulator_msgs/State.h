#ifndef _ROS_open_manipulator_msgs_State_h
#define _ROS_open_manipulator_msgs_State_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace open_manipulator_msgs
{

  class State : public ros::Msg
  {
    public:
      typedef const char* _robot_type;
      _robot_type robot;
      enum { IS_MOVING =  "IS_MOVING" };
      enum { STOPPED =  "STOPPED" };

    State():
      robot("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_robot = strlen(this->robot);
      varToArr(outbuffer + offset, length_robot);
      offset += 4;
      memcpy(outbuffer + offset, this->robot, length_robot);
      offset += length_robot;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_robot;
      arrToVar(length_robot, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot-1]=0;
      this->robot = (char *)(inbuffer + offset-1);
      offset += length_robot;
     return offset;
    }

    const char * getType(){ return "open_manipulator_msgs/State"; };
    const char * getMD5(){ return "94370aa4b03eef51ce4d539f789d976f"; };

  };

}
#endif