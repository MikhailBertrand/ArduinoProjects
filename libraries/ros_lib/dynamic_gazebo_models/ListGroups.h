#ifndef _ROS_SERVICE_ListGroups_h
#define _ROS_SERVICE_ListGroups_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dynamic_gazebo_models/ControlGroup.h"

namespace dynamic_gazebo_models
{

static const char LISTGROUPS[] = "dynamic_gazebo_models/ListGroups";

  class ListGroupsRequest : public ros::Msg
  {
    public:

    ListGroupsRequest()
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

    const char * getType(){ return LISTGROUPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListGroupsResponse : public ros::Msg
  {
    public:
      uint32_t groups_length;
      typedef dynamic_gazebo_models::ControlGroup _groups_type;
      _groups_type st_groups;
      _groups_type * groups;

    ListGroupsResponse():
      groups_length(0), groups(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->groups_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->groups_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->groups_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->groups_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->groups_length);
      for( uint32_t i = 0; i < groups_length; i++){
      offset += this->groups[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t groups_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->groups_length);
      if(groups_lengthT > groups_length)
        this->groups = (dynamic_gazebo_models::ControlGroup*)realloc(this->groups, groups_lengthT * sizeof(dynamic_gazebo_models::ControlGroup));
      groups_length = groups_lengthT;
      for( uint32_t i = 0; i < groups_length; i++){
      offset += this->st_groups.deserialize(inbuffer + offset);
        memcpy( &(this->groups[i]), &(this->st_groups), sizeof(dynamic_gazebo_models::ControlGroup));
      }
     return offset;
    }

    const char * getType(){ return LISTGROUPS; };
    const char * getMD5(){ return "041d48f6e0f3ed52ac61ad386a2d292d"; };

  };

  class ListGroups {
    public:
    typedef ListGroupsRequest Request;
    typedef ListGroupsResponse Response;
  };

}
#endif
