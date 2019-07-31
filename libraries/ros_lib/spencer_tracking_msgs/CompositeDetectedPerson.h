#ifndef _ROS_spencer_tracking_msgs_CompositeDetectedPerson_h
#define _ROS_spencer_tracking_msgs_CompositeDetectedPerson_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "spencer_tracking_msgs/DetectedPerson.h"

namespace spencer_tracking_msgs
{

  class CompositeDetectedPerson : public ros::Msg
  {
    public:
      typedef uint64_t _composite_detection_id_type;
      _composite_detection_id_type composite_detection_id;
      typedef float _mean_confidence_type;
      _mean_confidence_type mean_confidence;
      typedef float _max_confidence_type;
      _max_confidence_type max_confidence;
      typedef float _min_confidence_type;
      _min_confidence_type min_confidence;
      typedef geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;
      uint32_t original_detections_length;
      typedef spencer_tracking_msgs::DetectedPerson _original_detections_type;
      _original_detections_type st_original_detections;
      _original_detections_type * original_detections;

    CompositeDetectedPerson():
      composite_detection_id(0),
      mean_confidence(0),
      max_confidence(0),
      min_confidence(0),
      pose(),
      original_detections_length(0), original_detections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_composite_detection_id;
      u_composite_detection_id.real = this->composite_detection_id;
      *(outbuffer + offset + 0) = (u_composite_detection_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_composite_detection_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_composite_detection_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_composite_detection_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->composite_detection_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->mean_confidence);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_confidence);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_confidence);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->original_detections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->original_detections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->original_detections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->original_detections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->original_detections_length);
      for( uint32_t i = 0; i < original_detections_length; i++){
      offset += this->original_detections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_composite_detection_id;
      u_composite_detection_id.base = 0;
      u_composite_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_composite_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_composite_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_composite_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->composite_detection_id = u_composite_detection_id.real;
      offset += sizeof(this->composite_detection_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mean_confidence));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_confidence));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_confidence));
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t original_detections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      original_detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      original_detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      original_detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->original_detections_length);
      if(original_detections_lengthT > original_detections_length)
        this->original_detections = (spencer_tracking_msgs::DetectedPerson*)realloc(this->original_detections, original_detections_lengthT * sizeof(spencer_tracking_msgs::DetectedPerson));
      original_detections_length = original_detections_lengthT;
      for( uint32_t i = 0; i < original_detections_length; i++){
      offset += this->st_original_detections.deserialize(inbuffer + offset);
        memcpy( &(this->original_detections[i]), &(this->st_original_detections), sizeof(spencer_tracking_msgs::DetectedPerson));
      }
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/CompositeDetectedPerson"; };
    const char * getMD5(){ return "10e83f06a9bfbf6da1ae6f0fcdbe2cc4"; };

  };

}
#endif