#ifndef _ROS_spencer_tracking_msgs_TrackedPersons2d_h
#define _ROS_spencer_tracking_msgs_TrackedPersons2d_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_tracking_msgs/TrackedPerson2d.h"

namespace spencer_tracking_msgs
{

  class TrackedPersons2d : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t boxes_length;
      typedef spencer_tracking_msgs::TrackedPerson2d _boxes_type;
      _boxes_type st_boxes;
      _boxes_type * boxes;

    TrackedPersons2d():
      header(),
      boxes_length(0), boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->boxes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->boxes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->boxes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->boxes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->boxes_length);
      for( uint32_t i = 0; i < boxes_length; i++){
      offset += this->boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t boxes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->boxes_length);
      if(boxes_lengthT > boxes_length)
        this->boxes = (spencer_tracking_msgs::TrackedPerson2d*)realloc(this->boxes, boxes_lengthT * sizeof(spencer_tracking_msgs::TrackedPerson2d));
      boxes_length = boxes_lengthT;
      for( uint32_t i = 0; i < boxes_length; i++){
      offset += this->st_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->boxes[i]), &(this->st_boxes), sizeof(spencer_tracking_msgs::TrackedPerson2d));
      }
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/TrackedPersons2d"; };
    const char * getMD5(){ return "972b7d693ce31c3b18f092f43387621c"; };

  };

}
#endif