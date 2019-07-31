#ifndef _ROS_spencer_social_relation_msgs_SocialActivities_h
#define _ROS_spencer_social_relation_msgs_SocialActivities_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_social_relation_msgs/SocialActivity.h"

namespace spencer_social_relation_msgs
{

  class SocialActivities : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t elements_length;
      typedef spencer_social_relation_msgs::SocialActivity _elements_type;
      _elements_type st_elements;
      _elements_type * elements;

    SocialActivities():
      header(),
      elements_length(0), elements(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->elements_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->elements_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->elements_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->elements_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->elements_length);
      for( uint32_t i = 0; i < elements_length; i++){
      offset += this->elements[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t elements_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->elements_length);
      if(elements_lengthT > elements_length)
        this->elements = (spencer_social_relation_msgs::SocialActivity*)realloc(this->elements, elements_lengthT * sizeof(spencer_social_relation_msgs::SocialActivity));
      elements_length = elements_lengthT;
      for( uint32_t i = 0; i < elements_length; i++){
      offset += this->st_elements.deserialize(inbuffer + offset);
        memcpy( &(this->elements[i]), &(this->st_elements), sizeof(spencer_social_relation_msgs::SocialActivity));
      }
     return offset;
    }

    const char * getType(){ return "spencer_social_relation_msgs/SocialActivities"; };
    const char * getMD5(){ return "59f7b8ff037d2bbbd144704b9ef2b5be"; };

  };

}
#endif