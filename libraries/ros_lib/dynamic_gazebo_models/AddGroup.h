#ifndef _ROS_SERVICE_AddGroup_h
#define _ROS_SERVICE_AddGroup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dynamic_gazebo_models/ControlGroup.h"

namespace dynamic_gazebo_models
{

static const char ADDGROUP[] = "dynamic_gazebo_models/AddGroup";

  class AddGroupRequest : public ros::Msg
  {
    public:
      typedef dynamic_gazebo_models::ControlGroup _group_type;
      _group_type group;

    AddGroupRequest():
      group()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->group.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->group.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ADDGROUP; };
    const char * getMD5(){ return "021079f9f705b68d0acbd57f8b383d3d"; };

  };

  class AddGroupResponse : public ros::Msg
  {
    public:

    AddGroupResponse()
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

    const char * getType(){ return ADDGROUP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddGroup {
    public:
    typedef AddGroupRequest Request;
    typedef AddGroupResponse Response;
  };

}
#endif
