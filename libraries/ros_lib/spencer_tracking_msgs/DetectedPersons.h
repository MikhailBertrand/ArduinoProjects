#ifndef _ROS_spencer_tracking_msgs_DetectedPersons_h
#define _ROS_spencer_tracking_msgs_DetectedPersons_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "spencer_tracking_msgs/DetectedPerson.h"

namespace spencer_tracking_msgs
{

  class DetectedPersons : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t detections_length;
      typedef spencer_tracking_msgs::DetectedPerson _detections_type;
      _detections_type st_detections;
      _detections_type * detections;

    DetectedPersons():
      header(),
      detections_length(0), detections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->detections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detections_length);
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t detections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detections_length);
      if(detections_lengthT > detections_length)
        this->detections = (spencer_tracking_msgs::DetectedPerson*)realloc(this->detections, detections_lengthT * sizeof(spencer_tracking_msgs::DetectedPerson));
      detections_length = detections_lengthT;
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(spencer_tracking_msgs::DetectedPerson));
      }
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/DetectedPersons"; };
    const char * getMD5(){ return "38e416cebb5dfd7363bde91113e7f3bd"; };

  };

}
#endif