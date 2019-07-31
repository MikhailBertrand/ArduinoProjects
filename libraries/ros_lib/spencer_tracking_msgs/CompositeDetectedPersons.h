#ifndef _ROS_spencer_tracking_msgs_CompositeDetectedPersons_h
#define _ROS_spencer_tracking_msgs_CompositeDetectedPersons_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_tracking_msgs/CompositeDetectedPerson.h"

namespace spencer_tracking_msgs
{

  class CompositeDetectedPersons : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t elements_length;
      typedef spencer_tracking_msgs::CompositeDetectedPerson _elements_type;
      _elements_type st_elements;
      _elements_type * elements;

    CompositeDetectedPersons():
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
        this->elements = (spencer_tracking_msgs::CompositeDetectedPerson*)realloc(this->elements, elements_lengthT * sizeof(spencer_tracking_msgs::CompositeDetectedPerson));
      elements_length = elements_lengthT;
      for( uint32_t i = 0; i < elements_length; i++){
      offset += this->st_elements.deserialize(inbuffer + offset);
        memcpy( &(this->elements[i]), &(this->st_elements), sizeof(spencer_tracking_msgs::CompositeDetectedPerson));
      }
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/CompositeDetectedPersons"; };
    const char * getMD5(){ return "c4f9f34f5cb712f010de12fc027da3e6"; };

  };

}
#endif