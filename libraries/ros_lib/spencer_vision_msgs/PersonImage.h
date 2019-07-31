#ifndef _ROS_spencer_vision_msgs_PersonImage_h
#define _ROS_spencer_vision_msgs_PersonImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace spencer_vision_msgs
{

  class PersonImage : public ros::Msg
  {
    public:
      typedef uint64_t _detection_id_type;
      _detection_id_type detection_id;
      typedef sensor_msgs::Image _image_type;
      _image_type image;

    PersonImage():
      detection_id(0),
      image()
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
      offset += this->image.serialize(outbuffer + offset);
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
      offset += this->image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "spencer_vision_msgs/PersonImage"; };
    const char * getMD5(){ return "d8c9467666c46ebf784964cbf610d8c1"; };

  };

}
#endif