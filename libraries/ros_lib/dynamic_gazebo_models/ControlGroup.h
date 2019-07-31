#ifndef _ROS_dynamic_gazebo_models_ControlGroup_h
#define _ROS_dynamic_gazebo_models_ControlGroup_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_gazebo_models
{

  class ControlGroup : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef const char* _type_type;
      _type_type type;
      uint32_t active_units_length;
      typedef uint32_t _active_units_type;
      _active_units_type st_active_units;
      _active_units_type * active_units;

    ControlGroup():
      group_name(""),
      type(""),
      active_units_length(0), active_units(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->active_units_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->active_units_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->active_units_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->active_units_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->active_units_length);
      for( uint32_t i = 0; i < active_units_length; i++){
      *(outbuffer + offset + 0) = (this->active_units[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->active_units[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->active_units[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->active_units[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->active_units[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t active_units_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      active_units_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      active_units_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      active_units_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->active_units_length);
      if(active_units_lengthT > active_units_length)
        this->active_units = (uint32_t*)realloc(this->active_units, active_units_lengthT * sizeof(uint32_t));
      active_units_length = active_units_lengthT;
      for( uint32_t i = 0; i < active_units_length; i++){
      this->st_active_units =  ((uint32_t) (*(inbuffer + offset)));
      this->st_active_units |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_active_units |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_active_units |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_active_units);
        memcpy( &(this->active_units[i]), &(this->st_active_units), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "dynamic_gazebo_models/ControlGroup"; };
    const char * getMD5(){ return "d80ffdc784099674c3e60482d6fc2419"; };

  };

}
#endif