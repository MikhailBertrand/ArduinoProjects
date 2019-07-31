#ifndef _ROS_spencer_vision_msgs_PersonImages_h
#define _ROS_spencer_vision_msgs_PersonImages_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_vision_msgs/PersonImage.h"

namespace spencer_vision_msgs
{

  class PersonImages : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t elements_length;
      typedef spencer_vision_msgs::PersonImage _elements_type;
      _elements_type st_elements;
      _elements_type * elements;

    PersonImages():
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
        this->elements = (spencer_vision_msgs::PersonImage*)realloc(this->elements, elements_lengthT * sizeof(spencer_vision_msgs::PersonImage));
      elements_length = elements_lengthT;
      for( uint32_t i = 0; i < elements_length; i++){
      offset += this->st_elements.deserialize(inbuffer + offset);
        memcpy( &(this->elements[i]), &(this->st_elements), sizeof(spencer_vision_msgs::PersonImage));
      }
     return offset;
    }

    const char * getType(){ return "spencer_vision_msgs/PersonImages"; };
    const char * getMD5(){ return "6c5881059a7a7f9c813cdc2429f1b5cf"; };

  };

}
#endif