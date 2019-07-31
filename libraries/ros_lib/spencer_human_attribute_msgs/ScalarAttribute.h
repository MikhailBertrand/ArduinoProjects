#ifndef _ROS_spencer_human_attribute_msgs_ScalarAttribute_h
#define _ROS_spencer_human_attribute_msgs_ScalarAttribute_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_human_attribute_msgs
{

  class ScalarAttribute : public ros::Msg
  {
    public:
      typedef uint64_t _subject_id_type;
      _subject_id_type subject_id;
      typedef const char* _type_type;
      _type_type type;
      uint32_t values_length;
      typedef float _values_type;
      _values_type st_values;
      _values_type * values;
      uint32_t confidences_length;
      typedef float _confidences_type;
      _confidences_type st_confidences;
      _confidences_type * confidences;
      enum { PERSON_HEIGHT =  person_height };

    ScalarAttribute():
      subject_id(0),
      type(""),
      values_length(0), values(NULL),
      confidences_length(0), confidences(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_subject_id;
      u_subject_id.real = this->subject_id;
      *(outbuffer + offset + 0) = (u_subject_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_subject_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_subject_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_subject_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subject_id);
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values_length);
      for( uint32_t i = 0; i < values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_valuesi;
      u_valuesi.real = this->values[i];
      *(outbuffer + offset + 0) = (u_valuesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valuesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valuesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values[i]);
      }
      *(outbuffer + offset + 0) = (this->confidences_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->confidences_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->confidences_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->confidences_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidences_length);
      for( uint32_t i = 0; i < confidences_length; i++){
      union {
        float real;
        uint32_t base;
      } u_confidencesi;
      u_confidencesi.real = this->confidences[i];
      *(outbuffer + offset + 0) = (u_confidencesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidencesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidencesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidencesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidences[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_subject_id;
      u_subject_id.base = 0;
      u_subject_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_subject_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_subject_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_subject_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->subject_id = u_subject_id.real;
      offset += sizeof(this->subject_id);
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->values_length);
      if(values_lengthT > values_length)
        this->values = (float*)realloc(this->values, values_lengthT * sizeof(float));
      values_length = values_lengthT;
      for( uint32_t i = 0; i < values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_values;
      u_st_values.base = 0;
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_values = u_st_values.real;
      offset += sizeof(this->st_values);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(float));
      }
      uint32_t confidences_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      confidences_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      confidences_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      confidences_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->confidences_length);
      if(confidences_lengthT > confidences_length)
        this->confidences = (float*)realloc(this->confidences, confidences_lengthT * sizeof(float));
      confidences_length = confidences_lengthT;
      for( uint32_t i = 0; i < confidences_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_confidences;
      u_st_confidences.base = 0;
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_confidences = u_st_confidences.real;
      offset += sizeof(this->st_confidences);
        memcpy( &(this->confidences[i]), &(this->st_confidences), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "spencer_human_attribute_msgs/ScalarAttribute"; };
    const char * getMD5(){ return "e10ac15d3bace9d3787523d1dd728fe0"; };

  };

}
#endif