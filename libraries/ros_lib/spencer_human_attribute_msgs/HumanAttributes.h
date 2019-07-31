#ifndef _ROS_spencer_human_attribute_msgs_HumanAttributes_h
#define _ROS_spencer_human_attribute_msgs_HumanAttributes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_human_attribute_msgs/CategoricalAttribute.h"
#include "spencer_human_attribute_msgs/ScalarAttribute.h"

namespace spencer_human_attribute_msgs
{

  class HumanAttributes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t categoricalAttributes_length;
      typedef spencer_human_attribute_msgs::CategoricalAttribute _categoricalAttributes_type;
      _categoricalAttributes_type st_categoricalAttributes;
      _categoricalAttributes_type * categoricalAttributes;
      uint32_t scalarAttributes_length;
      typedef spencer_human_attribute_msgs::ScalarAttribute _scalarAttributes_type;
      _scalarAttributes_type st_scalarAttributes;
      _scalarAttributes_type * scalarAttributes;

    HumanAttributes():
      header(),
      categoricalAttributes_length(0), categoricalAttributes(NULL),
      scalarAttributes_length(0), scalarAttributes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->categoricalAttributes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->categoricalAttributes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->categoricalAttributes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->categoricalAttributes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->categoricalAttributes_length);
      for( uint32_t i = 0; i < categoricalAttributes_length; i++){
      offset += this->categoricalAttributes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->scalarAttributes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scalarAttributes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scalarAttributes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scalarAttributes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scalarAttributes_length);
      for( uint32_t i = 0; i < scalarAttributes_length; i++){
      offset += this->scalarAttributes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t categoricalAttributes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      categoricalAttributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      categoricalAttributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      categoricalAttributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->categoricalAttributes_length);
      if(categoricalAttributes_lengthT > categoricalAttributes_length)
        this->categoricalAttributes = (spencer_human_attribute_msgs::CategoricalAttribute*)realloc(this->categoricalAttributes, categoricalAttributes_lengthT * sizeof(spencer_human_attribute_msgs::CategoricalAttribute));
      categoricalAttributes_length = categoricalAttributes_lengthT;
      for( uint32_t i = 0; i < categoricalAttributes_length; i++){
      offset += this->st_categoricalAttributes.deserialize(inbuffer + offset);
        memcpy( &(this->categoricalAttributes[i]), &(this->st_categoricalAttributes), sizeof(spencer_human_attribute_msgs::CategoricalAttribute));
      }
      uint32_t scalarAttributes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scalarAttributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scalarAttributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scalarAttributes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scalarAttributes_length);
      if(scalarAttributes_lengthT > scalarAttributes_length)
        this->scalarAttributes = (spencer_human_attribute_msgs::ScalarAttribute*)realloc(this->scalarAttributes, scalarAttributes_lengthT * sizeof(spencer_human_attribute_msgs::ScalarAttribute));
      scalarAttributes_length = scalarAttributes_lengthT;
      for( uint32_t i = 0; i < scalarAttributes_length; i++){
      offset += this->st_scalarAttributes.deserialize(inbuffer + offset);
        memcpy( &(this->scalarAttributes[i]), &(this->st_scalarAttributes), sizeof(spencer_human_attribute_msgs::ScalarAttribute));
      }
     return offset;
    }

    const char * getType(){ return "spencer_human_attribute_msgs/HumanAttributes"; };
    const char * getMD5(){ return "0ce67039f788378180e089c471174c58"; };

  };

}
#endif