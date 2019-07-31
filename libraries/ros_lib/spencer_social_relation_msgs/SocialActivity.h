#ifndef _ROS_spencer_social_relation_msgs_SocialActivity_h
#define _ROS_spencer_social_relation_msgs_SocialActivity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_social_relation_msgs
{

  class SocialActivity : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      typedef float _confidence_type;
      _confidence_type confidence;
      uint32_t track_ids_length;
      typedef uint64_t _track_ids_type;
      _track_ids_type st_track_ids;
      _track_ids_type * track_ids;
      enum { TYPE_SHOPPING =  shopping };
      enum { TYPE_STANDING =  standing };
      enum { TYPE_INDIVIDUAL_MOVING =  individual_moving };
      enum { TYPE_WAITING_IN_QUEUE =  waiting_in_queue };
      enum { TYPE_LOOKING_AT_INFORMATION_SCREEN =  looking_at_information_screen };
      enum { TYPE_LOOKING_AT_KIOSK =  looking_at_kiosk };
      enum { TYPE_GROUP_ASSEMBLING =  group_assembling };
      enum { TYPE_GROUP_MOVING =  group_moving };
      enum { TYPE_FLOW_WITH_ROBOT =  flow };
      enum { TYPE_ANTIFLOW_AGAINST_ROBOT =  antiflow };
      enum { TYPE_WAITING_FOR_OTHERS =  waiting_for_others };
      enum { TYPE_LOOKING_FOR_HELP =  looking_for_help };

    SocialActivity():
      type(""),
      confidence(0),
      track_ids_length(0), track_ids(NULL)
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
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      *(outbuffer + offset + 0) = (this->track_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->track_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->track_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->track_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_ids_length);
      for( uint32_t i = 0; i < track_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_track_idsi;
      u_track_idsi.real = this->track_ids[i];
      *(outbuffer + offset + 0) = (u_track_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_ids[i]);
      }
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
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      uint32_t track_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      track_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      track_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      track_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->track_ids_length);
      if(track_ids_lengthT > track_ids_length)
        this->track_ids = (uint64_t*)realloc(this->track_ids, track_ids_lengthT * sizeof(uint64_t));
      track_ids_length = track_ids_lengthT;
      for( uint32_t i = 0; i < track_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_track_ids;
      u_st_track_ids.base = 0;
      u_st_track_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_track_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_track_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_track_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_track_ids = u_st_track_ids.real;
      offset += sizeof(this->st_track_ids);
        memcpy( &(this->track_ids[i]), &(this->st_track_ids), sizeof(uint64_t));
      }
     return offset;
    }

    const char * getType(){ return "spencer_social_relation_msgs/SocialActivity"; };
    const char * getMD5(){ return "b2c2f6733618189901fea0ddf041096b"; };

  };

}
#endif