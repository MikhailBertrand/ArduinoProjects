#ifndef _ROS_rwth_perception_people_msgs_VisualOdometry_h
#define _ROS_rwth_perception_people_msgs_VisualOdometry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rwth_perception_people_msgs
{

  class VisualOdometry : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _change_reference_frame_type;
      _change_reference_frame_type change_reference_frame;
      typedef int32_t _fast_threshold_type;
      _fast_threshold_type fast_threshold;
      typedef int32_t _num_total_detected_keypoints_type;
      _num_total_detected_keypoints_type num_total_detected_keypoints;
      uint32_t num_detected_keypoints_length;
      typedef int32_t _num_detected_keypoints_type;
      _num_detected_keypoints_type st_num_detected_keypoints;
      _num_detected_keypoints_type * num_detected_keypoints;
      typedef int32_t _num_total_keypoints_type;
      _num_total_keypoints_type num_total_keypoints;
      uint32_t num_keypoints_length;
      typedef int32_t _num_keypoints_type;
      _num_keypoints_type st_num_keypoints;
      _num_keypoints_type * num_keypoints;
      typedef int32_t _motion_estimate_status_code_type;
      _motion_estimate_status_code_type motion_estimate_status_code;
      typedef const char* _motion_estimate_status_type;
      _motion_estimate_status_type motion_estimate_status;
      typedef bool _motion_estimate_valid_type;
      _motion_estimate_valid_type motion_estimate_valid;
      typedef int32_t _num_matches_type;
      _num_matches_type num_matches;
      typedef int32_t _num_inliers_type;
      _num_inliers_type num_inliers;
      typedef int32_t _num_reprojection_failures_type;
      _num_reprojection_failures_type num_reprojection_failures;
      typedef float _runtime_type;
      _runtime_type runtime;
      uint32_t transformation_matrix_length;
      typedef float _transformation_matrix_type;
      _transformation_matrix_type st_transformation_matrix;
      _transformation_matrix_type * transformation_matrix;

    VisualOdometry():
      header(),
      change_reference_frame(0),
      fast_threshold(0),
      num_total_detected_keypoints(0),
      num_detected_keypoints_length(0), num_detected_keypoints(NULL),
      num_total_keypoints(0),
      num_keypoints_length(0), num_keypoints(NULL),
      motion_estimate_status_code(0),
      motion_estimate_status(""),
      motion_estimate_valid(0),
      num_matches(0),
      num_inliers(0),
      num_reprojection_failures(0),
      runtime(0),
      transformation_matrix_length(0), transformation_matrix(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_change_reference_frame;
      u_change_reference_frame.real = this->change_reference_frame;
      *(outbuffer + offset + 0) = (u_change_reference_frame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->change_reference_frame);
      union {
        int32_t real;
        uint32_t base;
      } u_fast_threshold;
      u_fast_threshold.real = this->fast_threshold;
      *(outbuffer + offset + 0) = (u_fast_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fast_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fast_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fast_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fast_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_num_total_detected_keypoints;
      u_num_total_detected_keypoints.real = this->num_total_detected_keypoints;
      *(outbuffer + offset + 0) = (u_num_total_detected_keypoints.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_total_detected_keypoints.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_total_detected_keypoints.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_total_detected_keypoints.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_total_detected_keypoints);
      *(outbuffer + offset + 0) = (this->num_detected_keypoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_detected_keypoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_detected_keypoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_detected_keypoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_detected_keypoints_length);
      for( uint32_t i = 0; i < num_detected_keypoints_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_num_detected_keypointsi;
      u_num_detected_keypointsi.real = this->num_detected_keypoints[i];
      *(outbuffer + offset + 0) = (u_num_detected_keypointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_detected_keypointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_detected_keypointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_detected_keypointsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_detected_keypoints[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_num_total_keypoints;
      u_num_total_keypoints.real = this->num_total_keypoints;
      *(outbuffer + offset + 0) = (u_num_total_keypoints.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_total_keypoints.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_total_keypoints.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_total_keypoints.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_total_keypoints);
      *(outbuffer + offset + 0) = (this->num_keypoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_keypoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_keypoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_keypoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_keypoints_length);
      for( uint32_t i = 0; i < num_keypoints_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_num_keypointsi;
      u_num_keypointsi.real = this->num_keypoints[i];
      *(outbuffer + offset + 0) = (u_num_keypointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_keypointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_keypointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_keypointsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_keypoints[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_motion_estimate_status_code;
      u_motion_estimate_status_code.real = this->motion_estimate_status_code;
      *(outbuffer + offset + 0) = (u_motion_estimate_status_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motion_estimate_status_code.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motion_estimate_status_code.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motion_estimate_status_code.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motion_estimate_status_code);
      uint32_t length_motion_estimate_status = strlen(this->motion_estimate_status);
      varToArr(outbuffer + offset, length_motion_estimate_status);
      offset += 4;
      memcpy(outbuffer + offset, this->motion_estimate_status, length_motion_estimate_status);
      offset += length_motion_estimate_status;
      union {
        bool real;
        uint8_t base;
      } u_motion_estimate_valid;
      u_motion_estimate_valid.real = this->motion_estimate_valid;
      *(outbuffer + offset + 0) = (u_motion_estimate_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motion_estimate_valid);
      union {
        int32_t real;
        uint32_t base;
      } u_num_matches;
      u_num_matches.real = this->num_matches;
      *(outbuffer + offset + 0) = (u_num_matches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_matches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_matches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_matches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_matches);
      union {
        int32_t real;
        uint32_t base;
      } u_num_inliers;
      u_num_inliers.real = this->num_inliers;
      *(outbuffer + offset + 0) = (u_num_inliers.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_inliers.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_inliers.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_inliers.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_inliers);
      union {
        int32_t real;
        uint32_t base;
      } u_num_reprojection_failures;
      u_num_reprojection_failures.real = this->num_reprojection_failures;
      *(outbuffer + offset + 0) = (u_num_reprojection_failures.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_reprojection_failures.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_reprojection_failures.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_reprojection_failures.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_reprojection_failures);
      offset += serializeAvrFloat64(outbuffer + offset, this->runtime);
      *(outbuffer + offset + 0) = (this->transformation_matrix_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transformation_matrix_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transformation_matrix_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transformation_matrix_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transformation_matrix_length);
      for( uint32_t i = 0; i < transformation_matrix_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->transformation_matrix[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_change_reference_frame;
      u_change_reference_frame.base = 0;
      u_change_reference_frame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->change_reference_frame = u_change_reference_frame.real;
      offset += sizeof(this->change_reference_frame);
      union {
        int32_t real;
        uint32_t base;
      } u_fast_threshold;
      u_fast_threshold.base = 0;
      u_fast_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fast_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fast_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fast_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fast_threshold = u_fast_threshold.real;
      offset += sizeof(this->fast_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_num_total_detected_keypoints;
      u_num_total_detected_keypoints.base = 0;
      u_num_total_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_total_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_total_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_total_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_total_detected_keypoints = u_num_total_detected_keypoints.real;
      offset += sizeof(this->num_total_detected_keypoints);
      uint32_t num_detected_keypoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      num_detected_keypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      num_detected_keypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      num_detected_keypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->num_detected_keypoints_length);
      if(num_detected_keypoints_lengthT > num_detected_keypoints_length)
        this->num_detected_keypoints = (int32_t*)realloc(this->num_detected_keypoints, num_detected_keypoints_lengthT * sizeof(int32_t));
      num_detected_keypoints_length = num_detected_keypoints_lengthT;
      for( uint32_t i = 0; i < num_detected_keypoints_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_num_detected_keypoints;
      u_st_num_detected_keypoints.base = 0;
      u_st_num_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_num_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_num_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_num_detected_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_num_detected_keypoints = u_st_num_detected_keypoints.real;
      offset += sizeof(this->st_num_detected_keypoints);
        memcpy( &(this->num_detected_keypoints[i]), &(this->st_num_detected_keypoints), sizeof(int32_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_num_total_keypoints;
      u_num_total_keypoints.base = 0;
      u_num_total_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_total_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_total_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_total_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_total_keypoints = u_num_total_keypoints.real;
      offset += sizeof(this->num_total_keypoints);
      uint32_t num_keypoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      num_keypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      num_keypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      num_keypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->num_keypoints_length);
      if(num_keypoints_lengthT > num_keypoints_length)
        this->num_keypoints = (int32_t*)realloc(this->num_keypoints, num_keypoints_lengthT * sizeof(int32_t));
      num_keypoints_length = num_keypoints_lengthT;
      for( uint32_t i = 0; i < num_keypoints_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_num_keypoints;
      u_st_num_keypoints.base = 0;
      u_st_num_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_num_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_num_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_num_keypoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_num_keypoints = u_st_num_keypoints.real;
      offset += sizeof(this->st_num_keypoints);
        memcpy( &(this->num_keypoints[i]), &(this->st_num_keypoints), sizeof(int32_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_motion_estimate_status_code;
      u_motion_estimate_status_code.base = 0;
      u_motion_estimate_status_code.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motion_estimate_status_code.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motion_estimate_status_code.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motion_estimate_status_code.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motion_estimate_status_code = u_motion_estimate_status_code.real;
      offset += sizeof(this->motion_estimate_status_code);
      uint32_t length_motion_estimate_status;
      arrToVar(length_motion_estimate_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_motion_estimate_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_motion_estimate_status-1]=0;
      this->motion_estimate_status = (char *)(inbuffer + offset-1);
      offset += length_motion_estimate_status;
      union {
        bool real;
        uint8_t base;
      } u_motion_estimate_valid;
      u_motion_estimate_valid.base = 0;
      u_motion_estimate_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motion_estimate_valid = u_motion_estimate_valid.real;
      offset += sizeof(this->motion_estimate_valid);
      union {
        int32_t real;
        uint32_t base;
      } u_num_matches;
      u_num_matches.base = 0;
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_matches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_matches = u_num_matches.real;
      offset += sizeof(this->num_matches);
      union {
        int32_t real;
        uint32_t base;
      } u_num_inliers;
      u_num_inliers.base = 0;
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_inliers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_inliers = u_num_inliers.real;
      offset += sizeof(this->num_inliers);
      union {
        int32_t real;
        uint32_t base;
      } u_num_reprojection_failures;
      u_num_reprojection_failures.base = 0;
      u_num_reprojection_failures.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_reprojection_failures.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_reprojection_failures.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_reprojection_failures.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_reprojection_failures = u_num_reprojection_failures.real;
      offset += sizeof(this->num_reprojection_failures);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->runtime));
      uint32_t transformation_matrix_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transformation_matrix_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transformation_matrix_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transformation_matrix_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->transformation_matrix_length);
      if(transformation_matrix_lengthT > transformation_matrix_length)
        this->transformation_matrix = (float*)realloc(this->transformation_matrix, transformation_matrix_lengthT * sizeof(float));
      transformation_matrix_length = transformation_matrix_lengthT;
      for( uint32_t i = 0; i < transformation_matrix_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_transformation_matrix));
        memcpy( &(this->transformation_matrix[i]), &(this->st_transformation_matrix), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/VisualOdometry"; };
    const char * getMD5(){ return "7438c791aea79027f990e123fc30b7f6"; };

  };

}
#endif