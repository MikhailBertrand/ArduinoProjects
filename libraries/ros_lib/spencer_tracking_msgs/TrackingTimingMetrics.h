#ifndef _ROS_spencer_tracking_msgs_TrackingTimingMetrics_h
#define _ROS_spencer_tracking_msgs_TrackingTimingMetrics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace spencer_tracking_msgs
{

  class TrackingTimingMetrics : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _track_count_type;
      _track_count_type track_count;
      typedef uint64_t _cycle_no_type;
      _cycle_no_type cycle_no;
      typedef float _average_cycle_time_type;
      _average_cycle_time_type average_cycle_time;
      typedef float _cycle_time_type;
      _cycle_time_type cycle_time;
      typedef float _average_processing_rate_type;
      _average_processing_rate_type average_processing_rate;
      typedef float _cpu_load_type;
      _cpu_load_type cpu_load;
      typedef float _average_cpu_load_type;
      _average_cpu_load_type average_cpu_load;
      typedef float _elapsed_time_type;
      _elapsed_time_type elapsed_time;
      typedef float _elapsed_cpu_time_type;
      _elapsed_cpu_time_type elapsed_cpu_time;

    TrackingTimingMetrics():
      header(),
      track_count(0),
      cycle_no(0),
      average_cycle_time(0),
      cycle_time(0),
      average_processing_rate(0),
      cpu_load(0),
      average_cpu_load(0),
      elapsed_time(0),
      elapsed_cpu_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_track_count;
      u_track_count.real = this->track_count;
      *(outbuffer + offset + 0) = (u_track_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_track_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_track_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_track_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->track_count);
      union {
        uint64_t real;
        uint32_t base;
      } u_cycle_no;
      u_cycle_no.real = this->cycle_no;
      *(outbuffer + offset + 0) = (u_cycle_no.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cycle_no.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cycle_no.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cycle_no.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cycle_no);
      union {
        float real;
        uint32_t base;
      } u_average_cycle_time;
      u_average_cycle_time.real = this->average_cycle_time;
      *(outbuffer + offset + 0) = (u_average_cycle_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average_cycle_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average_cycle_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average_cycle_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average_cycle_time);
      union {
        float real;
        uint32_t base;
      } u_cycle_time;
      u_cycle_time.real = this->cycle_time;
      *(outbuffer + offset + 0) = (u_cycle_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cycle_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cycle_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cycle_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cycle_time);
      union {
        float real;
        uint32_t base;
      } u_average_processing_rate;
      u_average_processing_rate.real = this->average_processing_rate;
      *(outbuffer + offset + 0) = (u_average_processing_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average_processing_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average_processing_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average_processing_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average_processing_rate);
      union {
        float real;
        uint32_t base;
      } u_cpu_load;
      u_cpu_load.real = this->cpu_load;
      *(outbuffer + offset + 0) = (u_cpu_load.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cpu_load.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cpu_load.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cpu_load.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cpu_load);
      union {
        float real;
        uint32_t base;
      } u_average_cpu_load;
      u_average_cpu_load.real = this->average_cpu_load;
      *(outbuffer + offset + 0) = (u_average_cpu_load.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average_cpu_load.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average_cpu_load.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average_cpu_load.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average_cpu_load);
      union {
        float real;
        uint32_t base;
      } u_elapsed_time;
      u_elapsed_time.real = this->elapsed_time;
      *(outbuffer + offset + 0) = (u_elapsed_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_elapsed_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_elapsed_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_elapsed_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->elapsed_time);
      union {
        float real;
        uint32_t base;
      } u_elapsed_cpu_time;
      u_elapsed_cpu_time.real = this->elapsed_cpu_time;
      *(outbuffer + offset + 0) = (u_elapsed_cpu_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_elapsed_cpu_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_elapsed_cpu_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_elapsed_cpu_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->elapsed_cpu_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_track_count;
      u_track_count.base = 0;
      u_track_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_track_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_track_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_track_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->track_count = u_track_count.real;
      offset += sizeof(this->track_count);
      union {
        uint64_t real;
        uint32_t base;
      } u_cycle_no;
      u_cycle_no.base = 0;
      u_cycle_no.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cycle_no.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cycle_no.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cycle_no.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cycle_no = u_cycle_no.real;
      offset += sizeof(this->cycle_no);
      union {
        float real;
        uint32_t base;
      } u_average_cycle_time;
      u_average_cycle_time.base = 0;
      u_average_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average_cycle_time = u_average_cycle_time.real;
      offset += sizeof(this->average_cycle_time);
      union {
        float real;
        uint32_t base;
      } u_cycle_time;
      u_cycle_time.base = 0;
      u_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cycle_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cycle_time = u_cycle_time.real;
      offset += sizeof(this->cycle_time);
      union {
        float real;
        uint32_t base;
      } u_average_processing_rate;
      u_average_processing_rate.base = 0;
      u_average_processing_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average_processing_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average_processing_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average_processing_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average_processing_rate = u_average_processing_rate.real;
      offset += sizeof(this->average_processing_rate);
      union {
        float real;
        uint32_t base;
      } u_cpu_load;
      u_cpu_load.base = 0;
      u_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cpu_load = u_cpu_load.real;
      offset += sizeof(this->cpu_load);
      union {
        float real;
        uint32_t base;
      } u_average_cpu_load;
      u_average_cpu_load.base = 0;
      u_average_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average_cpu_load.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average_cpu_load = u_average_cpu_load.real;
      offset += sizeof(this->average_cpu_load);
      union {
        float real;
        uint32_t base;
      } u_elapsed_time;
      u_elapsed_time.base = 0;
      u_elapsed_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_elapsed_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_elapsed_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_elapsed_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->elapsed_time = u_elapsed_time.real;
      offset += sizeof(this->elapsed_time);
      union {
        float real;
        uint32_t base;
      } u_elapsed_cpu_time;
      u_elapsed_cpu_time.base = 0;
      u_elapsed_cpu_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_elapsed_cpu_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_elapsed_cpu_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_elapsed_cpu_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->elapsed_cpu_time = u_elapsed_cpu_time.real;
      offset += sizeof(this->elapsed_cpu_time);
     return offset;
    }

    const char * getType(){ return "spencer_tracking_msgs/TrackingTimingMetrics"; };
    const char * getMD5(){ return "e5e4499959c0302da5d8864744a1d65a"; };

  };

}
#endif