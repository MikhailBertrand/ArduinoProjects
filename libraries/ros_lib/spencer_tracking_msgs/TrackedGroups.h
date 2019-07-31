#ifndef _ROS_spencer_tracking_msgs_TrackedGroups_h
#define _ROS_spencer_tracking_msgs_TrackedGroups_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_tracking_msgs/TrackedGroup.h"

namespace spencer_tracking_msgs
{

  class TrackedGroups : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t groups_length;
      typedef spencer_tracking_msgs::TrackedGroup _groups_type;
      _groups_type st_groups;
      _groups_type * groups;

    TrackedGroups():
      header(),
      groups_length(0), groups(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t groups_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->groups_length);
      if(groups_lengthT > groups_length)
        this->groups = (spencer_tracking_msgs::TrackedGroup*)realloc(this->groups, groups_lengthT * sizeof(spencer_tracking_msgs::TrackedGroup));
      groups_length = groups_lengthT;
      for( uint32_t i = 0; i < groups_length; i++){
      offset += this->st_groups.deserialize(inbuffer + offset);
        memcpy( &(this->groups[i]), &(this->st_groups), sizeof(spencer_tracking_msgs::TrackedGroup));
      }
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/TrackedGroups"; };
    const char * getMD5(){ return "44229e5f365e63f958cbe69d06c05cc4"; };

  };

}
#endif