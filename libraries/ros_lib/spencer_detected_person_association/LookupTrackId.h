#ifndef _ROS_SERVICE_LookupTrackId_h
#define _ROS_SERVICE_LookupTrackId_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace spencer_detected_person_association
{

static const char LOOKUPTRACKID[] = "spencer_detected_person_association/LookupTrackId";

  class LookupTrackIdRequest : public ros::Msg
  {
    public:
      typedef uint64_t _detection_id_type;
      _detection_id_type detection_id;

    LookupTrackIdRequest():
      detection_id(0)
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
     return offset;
    }

    const char * getType(){ return LOOKUPTRACKID; };
    const char * getMD5(){ return "429b45ef0055eafe06921700b8c599ba"; };

  };

  class LookupTrackIdResponse : public ros::Msg
  {
    public:
      typedef bool _was_found_type;
      _was_found_type was_found;
      typedef uint64_t _track_id_type;
      _track_id_type track_id;

    LookupTrackIdResponse():
      was_found(0),
      track_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_was_found;
      u_was_found.real = this->was_found;
      *(outbuffer + offset + 0) = (u_was_found.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->was_found);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_was_found;
      u_was_found.base = 0;
      u_was_found.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->was_found = u_was_found.real;
      offset += sizeof(this->was_found);
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
     return offset;
    }

    const char * getType(){ return LOOKUPTRACKID; };
    const char * getMD5(){ return "136927af1172c17b9b21fe747eac5b93"; };

  };

  class LookupTrackId {
    public:
    typedef LookupTrackIdRequest Request;
    typedef LookupTrackIdResponse Response;
  };

}
#endif
