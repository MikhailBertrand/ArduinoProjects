#ifndef _ROS_SERVICE_LookupTrackIds_h
#define _ROS_SERVICE_LookupTrackIds_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_detected_person_association
{

static const char LOOKUPTRACKIDS[] = "spencer_detected_person_association/LookupTrackIds";

  class LookupTrackIdsRequest : public ros::Msg
  {
    public:
      uint32_t detection_ids_length;
      typedef uint64_t _detection_ids_type;
      _detection_ids_type st_detection_ids;
      _detection_ids_type * detection_ids;

    LookupTrackIdsRequest():
      detection_ids_length(0), detection_ids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->detection_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detection_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detection_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detection_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_ids_length);
      for( uint32_t i = 0; i < detection_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_detection_idsi;
      u_detection_idsi.real = this->detection_ids[i];
      *(outbuffer + offset + 0) = (u_detection_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detection_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detection_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detection_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_ids[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t detection_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detection_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detection_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detection_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detection_ids_length);
      if(detection_ids_lengthT > detection_ids_length)
        this->detection_ids = (uint64_t*)realloc(this->detection_ids, detection_ids_lengthT * sizeof(uint64_t));
      detection_ids_length = detection_ids_lengthT;
      for( uint32_t i = 0; i < detection_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_detection_ids;
      u_st_detection_ids.base = 0;
      u_st_detection_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_detection_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_detection_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_detection_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_detection_ids = u_st_detection_ids.real;
      offset += sizeof(this->st_detection_ids);
        memcpy( &(this->detection_ids[i]), &(this->st_detection_ids), sizeof(uint64_t));
      }
     return offset;
    }

    const char * getType(){ return LOOKUPTRACKIDS; };
    const char * getMD5(){ return "d5d9524ed74ef6a68fc08108b7e0df13"; };

  };

  class LookupTrackIdsResponse : public ros::Msg
  {
    public:
      uint32_t was_found_length;
      typedef bool _was_found_type;
      _was_found_type st_was_found;
      _was_found_type * was_found;
      uint32_t track_ids_length;
      typedef uint64_t _track_ids_type;
      _track_ids_type st_track_ids;
      _track_ids_type * track_ids;

    LookupTrackIdsResponse():
      was_found_length(0), was_found(NULL),
      track_ids_length(0), track_ids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->was_found_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->was_found_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->was_found_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->was_found_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->was_found_length);
      for( uint32_t i = 0; i < was_found_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_was_foundi;
      u_was_foundi.real = this->was_found[i];
      *(outbuffer + offset + 0) = (u_was_foundi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->was_found[i]);
      }
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
      uint32_t was_found_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      was_found_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      was_found_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      was_found_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->was_found_length);
      if(was_found_lengthT > was_found_length)
        this->was_found = (bool*)realloc(this->was_found, was_found_lengthT * sizeof(bool));
      was_found_length = was_found_lengthT;
      for( uint32_t i = 0; i < was_found_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_was_found;
      u_st_was_found.base = 0;
      u_st_was_found.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_was_found = u_st_was_found.real;
      offset += sizeof(this->st_was_found);
        memcpy( &(this->was_found[i]), &(this->st_was_found), sizeof(bool));
      }
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

    const char * getType(){ return LOOKUPTRACKIDS; };
    const char * getMD5(){ return "f75a3066dabe6cedc87592cb01e78f64"; };

  };

  class LookupTrackIds {
    public:
    typedef LookupTrackIdsRequest Request;
    typedef LookupTrackIdsResponse Response;
  };

}
#endif
