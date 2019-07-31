#ifndef _ROS_spencer_social_relation_msgs_SocialRelation_h
#define _ROS_spencer_social_relation_msgs_SocialRelation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_social_relation_msgs
{

  class SocialRelation : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      typedef float _strength_type;
      _strength_type strength;
      typedef uint32_t _track1_id_type;
      _track1_id_type track1_id;
      typedef uint32_t _track2_id_type;
      _track2_id_type track2_id;
      enum { TYPE_SPATIAL =  "spatial" };
      enum { TYPE_ROMANTIC =  "romantic" };
      enum { TYPE_PARENT_CHILD =  "parent_child" };
      enum { TYPE_FRIENDSHIP =  "friendship" };

    SocialRelation():
      type(""),
      strength(0),
      track1_id(0),
      track2_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      union {
        float real;
        uint32_t base;
      } u_strength;
      u_strength.real = this->strength;
      *(outbuffer + offset + 0) = (u_strength.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strength.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strength.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strength.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strength);
      *(outbuffer + offset + 0) = (this->track1_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->track1_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->track1_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->track1_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track1_id);
      *(outbuffer + offset + 0) = (this->track2_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->track2_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->track2_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->track2_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track2_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      union {
        float real;
        uint32_t base;
      } u_strength;
      u_strength.base = 0;
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strength.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strength = u_strength.real;
      offset += sizeof(this->strength);
      this->track1_id =  ((uint32_t) (*(inbuffer + offset)));
      this->track1_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->track1_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->track1_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->track1_id);
      this->track2_id =  ((uint32_t) (*(inbuffer + offset)));
      this->track2_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->track2_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->track2_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->track2_id);
     return offset;
    }

    const char * getType(){ return "spencer_social_relation_msgs/SocialRelation"; };
    const char * getMD5(){ return "004e9c919342c749d66dbc051dba51f6"; };

  };

}
#endif