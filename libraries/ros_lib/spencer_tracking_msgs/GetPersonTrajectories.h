#ifndef _ROS_SERVICE_GetPersonTrajectories_h
#define _ROS_SERVICE_GetPersonTrajectories_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "spencer_tracking_msgs/PersonTrajectory.h"
#include "ros/duration.h"

namespace spencer_tracking_msgs
{

static const char GETPERSONTRAJECTORIES[] = "spencer_tracking_msgs/GetPersonTrajectories";

  class GetPersonTrajectoriesRequest : public ros::Msg
  {
    public:
      uint32_t requested_ids_length;
      typedef uint64_t _requested_ids_type;
      _requested_ids_type st_requested_ids;
      _requested_ids_type * requested_ids;
      typedef ros::Duration _max_age_type;
      _max_age_type max_age;

    GetPersonTrajectoriesRequest():
      requested_ids_length(0), requested_ids(NULL),
      max_age()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->requested_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->requested_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->requested_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->requested_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->requested_ids_length);
      for( uint32_t i = 0; i < requested_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_requested_idsi;
      u_requested_idsi.real = this->requested_ids[i];
      *(outbuffer + offset + 0) = (u_requested_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_requested_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_requested_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_requested_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->requested_ids[i]);
      }
      *(outbuffer + offset + 0) = (this->max_age.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_age.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_age.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_age.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_age.sec);
      *(outbuffer + offset + 0) = (this->max_age.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_age.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_age.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_age.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_age.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t requested_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      requested_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      requested_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      requested_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->requested_ids_length);
      if(requested_ids_lengthT > requested_ids_length)
        this->requested_ids = (uint64_t*)realloc(this->requested_ids, requested_ids_lengthT * sizeof(uint64_t));
      requested_ids_length = requested_ids_lengthT;
      for( uint32_t i = 0; i < requested_ids_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_requested_ids;
      u_st_requested_ids.base = 0;
      u_st_requested_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_requested_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_requested_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_requested_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_requested_ids = u_st_requested_ids.real;
      offset += sizeof(this->st_requested_ids);
        memcpy( &(this->requested_ids[i]), &(this->st_requested_ids), sizeof(uint64_t));
      }
      this->max_age.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_age.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_age.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_age.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_age.sec);
      this->max_age.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_age.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_age.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_age.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_age.nsec);
     return offset;
    }

    const char * getType(){ return GETPERSONTRAJECTORIES; };
    const char * getMD5(){ return "771ecc55f598ab2830cd2cba4bd8c15e"; };

  };

  class GetPersonTrajectoriesResponse : public ros::Msg
  {
    public:
      uint32_t trajectories_length;
      typedef spencer_tracking_msgs::PersonTrajectory _trajectories_type;
      _trajectories_type st_trajectories;
      _trajectories_type * trajectories;

    GetPersonTrajectoriesResponse():
      trajectories_length(0), trajectories(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->trajectories_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectories_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectories_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectories_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectories_length);
      for( uint32_t i = 0; i < trajectories_length; i++){
      offset += this->trajectories[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t trajectories_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectories_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trajectories_length);
      if(trajectories_lengthT > trajectories_length)
        this->trajectories = (spencer_tracking_msgs::PersonTrajectory*)realloc(this->trajectories, trajectories_lengthT * sizeof(spencer_tracking_msgs::PersonTrajectory));
      trajectories_length = trajectories_lengthT;
      for( uint32_t i = 0; i < trajectories_length; i++){
      offset += this->st_trajectories.deserialize(inbuffer + offset);
        memcpy( &(this->trajectories[i]), &(this->st_trajectories), sizeof(spencer_tracking_msgs::PersonTrajectory));
      }
     return offset;
    }

    const char * getType(){ return GETPERSONTRAJECTORIES; };
    const char * getMD5(){ return "cac69139f499658fd82ffbcabd799a3d"; };

  };

  class GetPersonTrajectories {
    public:
    typedef GetPersonTrajectoriesRequest Request;
    typedef GetPersonTrajectoriesResponse Response;
  };

}
#endif
