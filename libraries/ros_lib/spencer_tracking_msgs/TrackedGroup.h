#ifndef _ROS_spencer_tracking_msgs_TrackedGroup_h
#define _ROS_spencer_tracking_msgs_TrackedGroup_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"
#include "geometry_msgs/PoseWithCovariance.h"

namespace spencer_tracking_msgs
{

  class TrackedGroup : public ros::Msg
  {
    public:
      typedef uint64_t _group_id_type;
      _group_id_type group_id;
      typedef ros::Duration _age_type;
      _age_type age;
      typedef geometry_msgs::PoseWithCovariance _centerOfGravity_type;
      _centerOfGravity_type centerOfGravity;
      uint32_t track_ids_length;
      typedef uint64_t _track_ids_type;
      _track_ids_type st_track_ids;
      _track_ids_type * track_ids;

    TrackedGroup():
      group_id(0),
      age(),
      centerOfGravity(),
      track_ids_length(0), track_ids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_group_id;
      u_group_id.real = this->group_id;
      *(outbuffer + offset + 0) = (u_group_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_group_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_group_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_group_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->group_id);
      *(outbuffer + offset + 0) = (this->age.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.sec);
      *(outbuffer + offset + 0) = (this->age.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age.nsec);
      offset += this->centerOfGravity.serialize(outbuffer + offset);
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
      union {
        uint64_t real;
        uint32_t base;
      } u_group_id;
      u_group_id.base = 0;
      u_group_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_group_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_group_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_group_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->group_id = u_group_id.real;
      offset += sizeof(this->group_id);
      this->age.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.sec);
      this->age.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age.nsec);
      offset += this->centerOfGravity.deserialize(inbuffer + offset);
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

    const char * getType(){ return "spencer_tracking_msgs/TrackedGroup"; };
    const char * getMD5(){ return "6a5318bfb8e49948a4dc15c1267f7e54"; };

  };

}
#endif