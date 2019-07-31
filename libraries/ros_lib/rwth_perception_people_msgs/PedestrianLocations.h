#ifndef _ROS_rwth_perception_people_msgs_PedestrianLocations_h
#define _ROS_rwth_perception_people_msgs_PedestrianLocations_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace rwth_perception_people_msgs
{

  class PedestrianLocations : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t ids_length;
      typedef int32_t _ids_type;
      _ids_type st_ids;
      _ids_type * ids;
      uint32_t poses_length;
      typedef geometry_msgs::Pose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      uint32_t distances_length;
      typedef float _distances_type;
      _distances_type st_distances;
      _distances_type * distances;
      uint32_t angles_length;
      typedef float _angles_type;
      _angles_type st_angles;
      _angles_type * angles;
      typedef float _min_distance_type;
      _min_distance_type min_distance;
      typedef float _min_distance_angle_type;
      _min_distance_angle_type min_distance_angle;

    PedestrianLocations():
      header(),
      ids_length(0), ids(NULL),
      poses_length(0), poses(NULL),
      distances_length(0), distances(NULL),
      angles_length(0), angles(NULL),
      min_distance(0),
      min_distance_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ids_length);
      for( uint32_t i = 0; i < ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_idsi;
      u_idsi.real = this->ids[i];
      *(outbuffer + offset + 0) = (u_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ids[i]);
      }
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->distances_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distances_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distances_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distances_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distances_length);
      for( uint32_t i = 0; i < distances_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->distances[i]);
      }
      *(outbuffer + offset + 0) = (this->angles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->angles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->angles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angles_length);
      for( uint32_t i = 0; i < angles_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->angles[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->min_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_distance_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ids_length);
      if(ids_lengthT > ids_length)
        this->ids = (int32_t*)realloc(this->ids, ids_lengthT * sizeof(int32_t));
      ids_length = ids_lengthT;
      for( uint32_t i = 0; i < ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_ids;
      u_st_ids.base = 0;
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ids = u_st_ids.real;
      offset += sizeof(this->st_ids);
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(int32_t));
      }
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::Pose*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::Pose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::Pose));
      }
      uint32_t distances_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->distances_length);
      if(distances_lengthT > distances_length)
        this->distances = (float*)realloc(this->distances, distances_lengthT * sizeof(float));
      distances_length = distances_lengthT;
      for( uint32_t i = 0; i < distances_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_distances));
        memcpy( &(this->distances[i]), &(this->st_distances), sizeof(float));
      }
      uint32_t angles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->angles_length);
      if(angles_lengthT > angles_length)
        this->angles = (float*)realloc(this->angles, angles_lengthT * sizeof(float));
      angles_length = angles_lengthT;
      for( uint32_t i = 0; i < angles_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_angles));
        memcpy( &(this->angles[i]), &(this->st_angles), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_distance_angle));
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/PedestrianLocations"; };
    const char * getMD5(){ return "0f1ff45be31c79c3b674556d26791dcd"; };

  };

}
#endif