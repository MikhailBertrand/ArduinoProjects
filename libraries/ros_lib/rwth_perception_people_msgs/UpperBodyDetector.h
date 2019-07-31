#ifndef _ROS_rwth_perception_people_msgs_UpperBodyDetector_h
#define _ROS_rwth_perception_people_msgs_UpperBodyDetector_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rwth_perception_people_msgs
{

  class UpperBodyDetector : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t pos_x_length;
      typedef int64_t _pos_x_type;
      _pos_x_type st_pos_x;
      _pos_x_type * pos_x;
      uint32_t pos_y_length;
      typedef int64_t _pos_y_type;
      _pos_y_type st_pos_y;
      _pos_y_type * pos_y;
      uint32_t width_length;
      typedef int64_t _width_type;
      _width_type st_width;
      _width_type * width;
      uint32_t height_length;
      typedef int64_t _height_type;
      _height_type st_height;
      _height_type * height;
      uint32_t dist_length;
      typedef float _dist_type;
      _dist_type st_dist;
      _dist_type * dist;
      uint32_t median_depth_length;
      typedef float _median_depth_type;
      _median_depth_type st_median_depth;
      _median_depth_type * median_depth;

    UpperBodyDetector():
      header(),
      pos_x_length(0), pos_x(NULL),
      pos_y_length(0), pos_y(NULL),
      width_length(0), width(NULL),
      height_length(0), height(NULL),
      dist_length(0), dist(NULL),
      median_depth_length(0), median_depth(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pos_x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pos_x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pos_x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pos_x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_x_length);
      for( uint32_t i = 0; i < pos_x_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_pos_xi;
      u_pos_xi.real = this->pos_x[i];
      *(outbuffer + offset + 0) = (u_pos_xi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_xi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_xi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_xi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pos_xi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pos_xi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pos_xi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pos_xi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos_x[i]);
      }
      *(outbuffer + offset + 0) = (this->pos_y_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pos_y_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pos_y_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pos_y_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_y_length);
      for( uint32_t i = 0; i < pos_y_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_pos_yi;
      u_pos_yi.real = this->pos_y[i];
      *(outbuffer + offset + 0) = (u_pos_yi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_yi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_yi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_yi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pos_yi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pos_yi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pos_yi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pos_yi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos_y[i]);
      }
      *(outbuffer + offset + 0) = (this->width_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width_length);
      for( uint32_t i = 0; i < width_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_widthi;
      u_widthi.real = this->width[i];
      *(outbuffer + offset + 0) = (u_widthi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_widthi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_widthi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_widthi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_widthi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_widthi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_widthi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_widthi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->width[i]);
      }
      *(outbuffer + offset + 0) = (this->height_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height_length);
      for( uint32_t i = 0; i < height_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_heighti;
      u_heighti.real = this->height[i];
      *(outbuffer + offset + 0) = (u_heighti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heighti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heighti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heighti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heighti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heighti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heighti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heighti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->height[i]);
      }
      *(outbuffer + offset + 0) = (this->dist_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dist_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dist_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dist_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dist_length);
      for( uint32_t i = 0; i < dist_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->dist[i]);
      }
      *(outbuffer + offset + 0) = (this->median_depth_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->median_depth_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->median_depth_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->median_depth_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->median_depth_length);
      for( uint32_t i = 0; i < median_depth_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->median_depth[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t pos_x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pos_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pos_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pos_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pos_x_length);
      if(pos_x_lengthT > pos_x_length)
        this->pos_x = (int64_t*)realloc(this->pos_x, pos_x_lengthT * sizeof(int64_t));
      pos_x_length = pos_x_lengthT;
      for( uint32_t i = 0; i < pos_x_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_pos_x;
      u_st_pos_x.base = 0;
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_pos_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_pos_x = u_st_pos_x.real;
      offset += sizeof(this->st_pos_x);
        memcpy( &(this->pos_x[i]), &(this->st_pos_x), sizeof(int64_t));
      }
      uint32_t pos_y_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pos_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pos_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pos_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pos_y_length);
      if(pos_y_lengthT > pos_y_length)
        this->pos_y = (int64_t*)realloc(this->pos_y, pos_y_lengthT * sizeof(int64_t));
      pos_y_length = pos_y_lengthT;
      for( uint32_t i = 0; i < pos_y_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_pos_y;
      u_st_pos_y.base = 0;
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_pos_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_pos_y = u_st_pos_y.real;
      offset += sizeof(this->st_pos_y);
        memcpy( &(this->pos_y[i]), &(this->st_pos_y), sizeof(int64_t));
      }
      uint32_t width_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      width_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      width_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      width_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->width_length);
      if(width_lengthT > width_length)
        this->width = (int64_t*)realloc(this->width, width_lengthT * sizeof(int64_t));
      width_length = width_lengthT;
      for( uint32_t i = 0; i < width_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_width;
      u_st_width.base = 0;
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_width.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_width = u_st_width.real;
      offset += sizeof(this->st_width);
        memcpy( &(this->width[i]), &(this->st_width), sizeof(int64_t));
      }
      uint32_t height_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      height_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      height_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      height_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->height_length);
      if(height_lengthT > height_length)
        this->height = (int64_t*)realloc(this->height, height_lengthT * sizeof(int64_t));
      height_length = height_lengthT;
      for( uint32_t i = 0; i < height_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_height;
      u_st_height.base = 0;
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_height = u_st_height.real;
      offset += sizeof(this->st_height);
        memcpy( &(this->height[i]), &(this->st_height), sizeof(int64_t));
      }
      uint32_t dist_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dist_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dist_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dist_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dist_length);
      if(dist_lengthT > dist_length)
        this->dist = (float*)realloc(this->dist, dist_lengthT * sizeof(float));
      dist_length = dist_lengthT;
      for( uint32_t i = 0; i < dist_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_dist));
        memcpy( &(this->dist[i]), &(this->st_dist), sizeof(float));
      }
      uint32_t median_depth_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      median_depth_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      median_depth_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      median_depth_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->median_depth_length);
      if(median_depth_lengthT > median_depth_length)
        this->median_depth = (float*)realloc(this->median_depth, median_depth_lengthT * sizeof(float));
      median_depth_length = median_depth_lengthT;
      for( uint32_t i = 0; i < median_depth_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_median_depth));
        memcpy( &(this->median_depth[i]), &(this->st_median_depth), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/UpperBodyDetector"; };
    const char * getMD5(){ return "1565008f1da6caedd235c0aedddd12ad"; };

  };

}
#endif