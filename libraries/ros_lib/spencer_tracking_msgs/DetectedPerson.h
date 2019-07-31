#ifndef _ROS_spencer_tracking_msgs_DetectedPerson_h
#define _ROS_spencer_tracking_msgs_DetectedPerson_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovariance.h"

namespace spencer_tracking_msgs
{

  class DetectedPerson : public ros::Msg
  {
    public:
      typedef uint64_t _detection_id_type;
      _detection_id_type detection_id;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;
      typedef const char* _modality_type;
      _modality_type modality;
      enum { MODALITY_GENERIC_LASER_2D =  laser2d };
      enum { MODALITY_GENERIC_LASER_3D =  laser3d };
      enum { MODALITY_GENERIC_MONOCULAR_VISION =  mono };
      enum { MODALITY_GENERIC_STEREO_VISION =  stereo };
      enum { MODALITY_GENERIC_RGBD =  rgbd };

    DetectedPerson():
      detection_id(0),
      confidence(0),
      pose(),
      modality("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_detection_id;
      u_detection_id.real = this->detection_id;
      *(outbuffer + offset + 0) = (u_detection_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detection_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detection_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detection_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      offset += this->pose.serialize(outbuffer + offset);
      uint32_t length_modality = strlen(this->modality);
      varToArr(outbuffer + offset, length_modality);
      offset += 4;
      memcpy(outbuffer + offset, this->modality, length_modality);
      offset += length_modality;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_detection_id;
      u_detection_id.base = 0;
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detection_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detection_id = u_detection_id.real;
      offset += sizeof(this->detection_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t length_modality;
      arrToVar(length_modality, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modality; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modality-1]=0;
      this->modality = (char *)(inbuffer + offset-1);
      offset += length_modality;
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/DetectedPerson"; };
    const char * getMD5(){ return "62855d424a3d5f142c0e8f5f63be52fe"; };

  };

}
#endif