#ifndef _ROS_rwth_perception_people_msgs_PedestrianTracking_h
#define _ROS_rwth_perception_people_msgs_PedestrianTracking_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rwth_perception_people_msgs
{

  class PedestrianTracking : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t traj_x_length;
      typedef float _traj_x_type;
      _traj_x_type st_traj_x;
      _traj_x_type * traj_x;
      uint32_t traj_y_length;
      typedef float _traj_y_type;
      _traj_y_type st_traj_y;
      _traj_y_type * traj_y;
      uint32_t traj_z_length;
      typedef float _traj_z_type;
      _traj_z_type st_traj_z;
      _traj_z_type * traj_z;
      uint32_t traj_x_camera_length;
      typedef float _traj_x_camera_type;
      _traj_x_camera_type st_traj_x_camera;
      _traj_x_camera_type * traj_x_camera;
      uint32_t traj_y_camera_length;
      typedef float _traj_y_camera_type;
      _traj_y_camera_type st_traj_y_camera;
      _traj_y_camera_type * traj_y_camera;
      uint32_t traj_z_camera_length;
      typedef float _traj_z_camera_type;
      _traj_z_camera_type st_traj_z_camera;
      _traj_z_camera_type * traj_z_camera;
      uint32_t dir_length;
      typedef float _dir_type;
      _dir_type st_dir;
      _dir_type * dir;
      typedef float _speed_type;
      _speed_type speed;
      typedef int64_t _id_type;
      _id_type id;
      typedef float _score_type;
      _score_type score;

    PedestrianTracking():
      header(),
      traj_x_length(0), traj_x(NULL),
      traj_y_length(0), traj_y(NULL),
      traj_z_length(0), traj_z(NULL),
      traj_x_camera_length(0), traj_x_camera(NULL),
      traj_y_camera_length(0), traj_y_camera(NULL),
      traj_z_camera_length(0), traj_z_camera(NULL),
      dir_length(0), dir(NULL),
      speed(0),
      id(0),
      score(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->traj_x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->traj_x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->traj_x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->traj_x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traj_x_length);
      for( uint32_t i = 0; i < traj_x_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->traj_x[i]);
      }
      *(outbuffer + offset + 0) = (this->traj_y_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->traj_y_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->traj_y_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->traj_y_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traj_y_length);
      for( uint32_t i = 0; i < traj_y_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->traj_y[i]);
      }
      *(outbuffer + offset + 0) = (this->traj_z_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->traj_z_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->traj_z_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->traj_z_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traj_z_length);
      for( uint32_t i = 0; i < traj_z_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->traj_z[i]);
      }
      *(outbuffer + offset + 0) = (this->traj_x_camera_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->traj_x_camera_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->traj_x_camera_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->traj_x_camera_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traj_x_camera_length);
      for( uint32_t i = 0; i < traj_x_camera_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->traj_x_camera[i]);
      }
      *(outbuffer + offset + 0) = (this->traj_y_camera_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->traj_y_camera_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->traj_y_camera_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->traj_y_camera_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traj_y_camera_length);
      for( uint32_t i = 0; i < traj_y_camera_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->traj_y_camera[i]);
      }
      *(outbuffer + offset + 0) = (this->traj_z_camera_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->traj_z_camera_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->traj_z_camera_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->traj_z_camera_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traj_z_camera_length);
      for( uint32_t i = 0; i < traj_z_camera_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->traj_z_camera[i]);
      }
      *(outbuffer + offset + 0) = (this->dir_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dir_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dir_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dir_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dir_length);
      for( uint32_t i = 0; i < dir_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->dir[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id);
      offset += serializeAvrFloat64(outbuffer + offset, this->score);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t traj_x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      traj_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      traj_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      traj_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->traj_x_length);
      if(traj_x_lengthT > traj_x_length)
        this->traj_x = (float*)realloc(this->traj_x, traj_x_lengthT * sizeof(float));
      traj_x_length = traj_x_lengthT;
      for( uint32_t i = 0; i < traj_x_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_traj_x));
        memcpy( &(this->traj_x[i]), &(this->st_traj_x), sizeof(float));
      }
      uint32_t traj_y_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      traj_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      traj_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      traj_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->traj_y_length);
      if(traj_y_lengthT > traj_y_length)
        this->traj_y = (float*)realloc(this->traj_y, traj_y_lengthT * sizeof(float));
      traj_y_length = traj_y_lengthT;
      for( uint32_t i = 0; i < traj_y_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_traj_y));
        memcpy( &(this->traj_y[i]), &(this->st_traj_y), sizeof(float));
      }
      uint32_t traj_z_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      traj_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      traj_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      traj_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->traj_z_length);
      if(traj_z_lengthT > traj_z_length)
        this->traj_z = (float*)realloc(this->traj_z, traj_z_lengthT * sizeof(float));
      traj_z_length = traj_z_lengthT;
      for( uint32_t i = 0; i < traj_z_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_traj_z));
        memcpy( &(this->traj_z[i]), &(this->st_traj_z), sizeof(float));
      }
      uint32_t traj_x_camera_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      traj_x_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      traj_x_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      traj_x_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->traj_x_camera_length);
      if(traj_x_camera_lengthT > traj_x_camera_length)
        this->traj_x_camera = (float*)realloc(this->traj_x_camera, traj_x_camera_lengthT * sizeof(float));
      traj_x_camera_length = traj_x_camera_lengthT;
      for( uint32_t i = 0; i < traj_x_camera_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_traj_x_camera));
        memcpy( &(this->traj_x_camera[i]), &(this->st_traj_x_camera), sizeof(float));
      }
      uint32_t traj_y_camera_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      traj_y_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      traj_y_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      traj_y_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->traj_y_camera_length);
      if(traj_y_camera_lengthT > traj_y_camera_length)
        this->traj_y_camera = (float*)realloc(this->traj_y_camera, traj_y_camera_lengthT * sizeof(float));
      traj_y_camera_length = traj_y_camera_lengthT;
      for( uint32_t i = 0; i < traj_y_camera_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_traj_y_camera));
        memcpy( &(this->traj_y_camera[i]), &(this->st_traj_y_camera), sizeof(float));
      }
      uint32_t traj_z_camera_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      traj_z_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      traj_z_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      traj_z_camera_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->traj_z_camera_length);
      if(traj_z_camera_lengthT > traj_z_camera_length)
        this->traj_z_camera = (float*)realloc(this->traj_z_camera, traj_z_camera_lengthT * sizeof(float));
      traj_z_camera_length = traj_z_camera_lengthT;
      for( uint32_t i = 0; i < traj_z_camera_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_traj_z_camera));
        memcpy( &(this->traj_z_camera[i]), &(this->st_traj_z_camera), sizeof(float));
      }
      uint32_t dir_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dir_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dir_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dir_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dir_length);
      if(dir_lengthT > dir_length)
        this->dir = (float*)realloc(this->dir, dir_lengthT * sizeof(float));
      dir_length = dir_lengthT;
      for( uint32_t i = 0; i < dir_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_dir));
        memcpy( &(this->dir[i]), &(this->st_dir), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->score));
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/PedestrianTracking"; };
    const char * getMD5(){ return "09aa33b8051238d8dd3261c282a34984"; };

  };

}
#endif