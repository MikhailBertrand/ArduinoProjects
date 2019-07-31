#ifndef _ROS_spencer_tracking_msgs_ImmDebugInfos_h
#define _ROS_spencer_tracking_msgs_ImmDebugInfos_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_tracking_msgs/ImmDebugInfo.h"

namespace spencer_tracking_msgs
{

  class ImmDebugInfos : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t infos_length;
      typedef spencer_tracking_msgs::ImmDebugInfo _infos_type;
      _infos_type st_infos;
      _infos_type * infos;

    ImmDebugInfos():
      header(),
      infos_length(0), infos(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->infos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->infos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->infos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->infos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->infos_length);
      for( uint32_t i = 0; i < infos_length; i++){
      offset += this->infos[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t infos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->infos_length);
      if(infos_lengthT > infos_length)
        this->infos = (spencer_tracking_msgs::ImmDebugInfo*)realloc(this->infos, infos_lengthT * sizeof(spencer_tracking_msgs::ImmDebugInfo));
      infos_length = infos_lengthT;
      for( uint32_t i = 0; i < infos_length; i++){
      offset += this->st_infos.deserialize(inbuffer + offset);
        memcpy( &(this->infos[i]), &(this->st_infos), sizeof(spencer_tracking_msgs::ImmDebugInfo));
      }
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/ImmDebugInfos"; };
    const char * getMD5(){ return "ce7fa675b582455db7386ac3eaa36b5b"; };

  };

}
#endif