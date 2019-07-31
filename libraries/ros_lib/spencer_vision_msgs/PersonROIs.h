#ifndef _ROS_spencer_vision_msgs_PersonROIs_h
#define _ROS_spencer_vision_msgs_PersonROIs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_vision_msgs/PersonROI.h"

namespace spencer_vision_msgs
{

  class PersonROIs : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _rgb_topic_type;
      _rgb_topic_type rgb_topic;
      typedef const char* _depth_topic_type;
      _depth_topic_type depth_topic;
      uint32_t elements_length;
      typedef spencer_vision_msgs::PersonROI _elements_type;
      _elements_type st_elements;
      _elements_type * elements;

    PersonROIs():
      header(),
      rgb_topic(""),
      depth_topic(""),
      elements_length(0), elements(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_rgb_topic = strlen(this->rgb_topic);
      varToArr(outbuffer + offset, length_rgb_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->rgb_topic, length_rgb_topic);
      offset += length_rgb_topic;
      uint32_t length_depth_topic = strlen(this->depth_topic);
      varToArr(outbuffer + offset, length_depth_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->depth_topic, length_depth_topic);
      offset += length_depth_topic;
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
      uint32_t length_rgb_topic;
      arrToVar(length_rgb_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rgb_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rgb_topic-1]=0;
      this->rgb_topic = (char *)(inbuffer + offset-1);
      offset += length_rgb_topic;
      uint32_t length_depth_topic;
      arrToVar(length_depth_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_depth_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_depth_topic-1]=0;
      this->depth_topic = (char *)(inbuffer + offset-1);
      offset += length_depth_topic;
      uint32_t elements_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      elements_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->elements_length);
      if(elements_lengthT > elements_length)
        this->elements = (spencer_vision_msgs::PersonROI*)realloc(this->elements, elements_lengthT * sizeof(spencer_vision_msgs::PersonROI));
      elements_length = elements_lengthT;
      for( uint32_t i = 0; i < elements_length; i++){
      offset += this->st_elements.deserialize(inbuffer + offset);
        memcpy( &(this->elements[i]), &(this->st_elements), sizeof(spencer_vision_msgs::PersonROI));
      }
     return offset;
    }

    const char * getType(){ return "spencer_vision_msgs/PersonROIs"; };
    const char * getMD5(){ return "5494785c7ce344707d7018890c22c251"; };

  };

}
#endif