#ifndef _ROS_spencer_tracking_msgs_ImmDebugInfo_h
#define _ROS_spencer_tracking_msgs_ImmDebugInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_tracking_msgs
{

  class ImmDebugInfo : public ros::Msg
  {
    public:
      typedef uint64_t _track_id_type;
      _track_id_type track_id;
      typedef float _innovation_type;
      _innovation_type innovation;
      typedef float _CpXX_type;
      _CpXX_type CpXX;
      typedef float _CpYY_type;
      _CpYY_type CpYY;
      typedef float _CXX_type;
      _CXX_type CXX;
      typedef float _CYY_type;
      _CYY_type CYY;
      uint32_t modeProbabilities_length;
      typedef float _modeProbabilities_type;
      _modeProbabilities_type st_modeProbabilities;
      _modeProbabilities_type * modeProbabilities;

    ImmDebugInfo():
      track_id(0),
      innovation(0),
      CpXX(0),
      CpYY(0),
      CXX(0),
      CYY(0),
      modeProbabilities_length(0), modeProbabilities(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.real = this->track_id;
      *(outbuffer + offset + 0) = (u_track_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->innovation);
      offset += serializeAvrFloat64(outbuffer + offset, this->CpXX);
      offset += serializeAvrFloat64(outbuffer + offset, this->CpYY);
      offset += serializeAvrFloat64(outbuffer + offset, this->CXX);
      offset += serializeAvrFloat64(outbuffer + offset, this->CYY);
      *(outbuffer + offset + 0) = (this->modeProbabilities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modeProbabilities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->modeProbabilities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->modeProbabilities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modeProbabilities_length);
      for( uint32_t i = 0; i < modeProbabilities_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->modeProbabilities[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_track_id;
      u_track_id.base = 0;
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->track_id = u_track_id.real;
      offset += sizeof(this->track_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->innovation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->CpXX));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->CpYY));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->CXX));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->CYY));
      uint32_t modeProbabilities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      modeProbabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      modeProbabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      modeProbabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->modeProbabilities_length);
      if(modeProbabilities_lengthT > modeProbabilities_length)
        this->modeProbabilities = (float*)realloc(this->modeProbabilities, modeProbabilities_lengthT * sizeof(float));
      modeProbabilities_length = modeProbabilities_lengthT;
      for( uint32_t i = 0; i < modeProbabilities_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_modeProbabilities));
        memcpy( &(this->modeProbabilities[i]), &(this->st_modeProbabilities), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/ImmDebugInfo"; };
    const char * getMD5(){ return "824cd837fd158664a6f185fb8316da53"; };

  };

}
#endif