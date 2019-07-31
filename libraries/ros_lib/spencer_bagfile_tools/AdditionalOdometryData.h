#ifndef _ROS_spencer_bagfile_tools_AdditionalOdometryData_h
#define _ROS_spencer_bagfile_tools_AdditionalOdometryData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace spencer_bagfile_tools
{

  class AdditionalOdometryData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _hardwareTimestamp_type;
      _hardwareTimestamp_type hardwareTimestamp;
      typedef float _totalDistance_type;
      _totalDistance_type totalDistance;
      typedef float _theta_type;
      _theta_type theta;
      typedef int64_t _ticksLeft_type;
      _ticksLeft_type ticksLeft;
      typedef int64_t _ticksRight_type;
      _ticksRight_type ticksRight;
      typedef float _calibOverallMultiplier_type;
      _calibOverallMultiplier_type calibOverallMultiplier;
      typedef float _calibLeftEncMultiplier_type;
      _calibLeftEncMultiplier_type calibLeftEncMultiplier;

    AdditionalOdometryData():
      header(),
      hardwareTimestamp(0),
      totalDistance(0),
      theta(0),
      ticksLeft(0),
      ticksRight(0),
      calibOverallMultiplier(0),
      calibLeftEncMultiplier(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_hardwareTimestamp;
      u_hardwareTimestamp.real = this->hardwareTimestamp;
      *(outbuffer + offset + 0) = (u_hardwareTimestamp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hardwareTimestamp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hardwareTimestamp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hardwareTimestamp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hardwareTimestamp);
      offset += serializeAvrFloat64(outbuffer + offset, this->totalDistance);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta);
      union {
        int64_t real;
        uint64_t base;
      } u_ticksLeft;
      u_ticksLeft.real = this->ticksLeft;
      *(outbuffer + offset + 0) = (u_ticksLeft.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ticksLeft.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ticksLeft.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ticksLeft.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ticksLeft.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ticksLeft.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ticksLeft.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ticksLeft.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ticksLeft);
      union {
        int64_t real;
        uint64_t base;
      } u_ticksRight;
      u_ticksRight.real = this->ticksRight;
      *(outbuffer + offset + 0) = (u_ticksRight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ticksRight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ticksRight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ticksRight.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ticksRight.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ticksRight.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ticksRight.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ticksRight.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ticksRight);
      offset += serializeAvrFloat64(outbuffer + offset, this->calibOverallMultiplier);
      offset += serializeAvrFloat64(outbuffer + offset, this->calibLeftEncMultiplier);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_hardwareTimestamp;
      u_hardwareTimestamp.base = 0;
      u_hardwareTimestamp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hardwareTimestamp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hardwareTimestamp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hardwareTimestamp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hardwareTimestamp = u_hardwareTimestamp.real;
      offset += sizeof(this->hardwareTimestamp);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->totalDistance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta));
      union {
        int64_t real;
        uint64_t base;
      } u_ticksLeft;
      u_ticksLeft.base = 0;
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ticksLeft.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ticksLeft = u_ticksLeft.real;
      offset += sizeof(this->ticksLeft);
      union {
        int64_t real;
        uint64_t base;
      } u_ticksRight;
      u_ticksRight.base = 0;
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ticksRight.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ticksRight = u_ticksRight.real;
      offset += sizeof(this->ticksRight);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->calibOverallMultiplier));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->calibLeftEncMultiplier));
     return offset;
    }

    const char * getType(){ return "spencer_bagfile_tools/AdditionalOdometryData"; };
    const char * getMD5(){ return "ab677b3c60eb604fa8c19025b90f80c1"; };

  };

}
#endif