#ifndef _ROS_rwth_perception_people_msgs_GroundHOGDetections_h
#define _ROS_rwth_perception_people_msgs_GroundHOGDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rwth_perception_people_msgs
{

  class GroundHOGDetections : public ros::Msg
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
      uint32_t scale_length;
      typedef float _scale_type;
      _scale_type st_scale;
      _scale_type * scale;
      uint32_t score_length;
      typedef float _score_type;
      _score_type st_score;
      _score_type * score;

    GroundHOGDetections():
      header(),
      pos_x_length(0), pos_x(NULL),
      pos_y_length(0), pos_y(NULL),
      width_length(0), width(NULL),
      height_length(0), height(NULL),
      scale_length(0), scale(NULL),
      score_length(0), score(NULL)
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
      *(outbuffer + offset + 0) = (this->scale_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scale_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scale_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scale_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scale_length);
      for( uint32_t i = 0; i < scale_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->scale[i]);
      }
      *(outbuffer + offset + 0) = (this->score_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->score_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->score_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->score_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score_length);
      for( uint32_t i = 0; i < score_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->score[i]);
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
      uint32_t scale_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->scale_length);
      if(scale_lengthT > scale_length)
        this->scale = (float*)realloc(this->scale, scale_lengthT * sizeof(float));
      scale_length = scale_lengthT;
      for( uint32_t i = 0; i < scale_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_scale));
        memcpy( &(this->scale[i]), &(this->st_scale), sizeof(float));
      }
      uint32_t score_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      score_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      score_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      score_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->score_length);
      if(score_lengthT > score_length)
        this->score = (float*)realloc(this->score, score_lengthT * sizeof(float));
      score_length = score_lengthT;
      for( uint32_t i = 0; i < score_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_score));
        memcpy( &(this->score[i]), &(this->st_score), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/GroundHOGDetections"; };
    const char * getMD5(){ return "e278dfbcb40304bacf23536a71084dab"; };

  };

}
#endif