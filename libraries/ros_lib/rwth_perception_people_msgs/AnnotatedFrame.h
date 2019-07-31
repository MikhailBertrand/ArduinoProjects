#ifndef _ROS_rwth_perception_people_msgs_AnnotatedFrame_h
#define _ROS_rwth_perception_people_msgs_AnnotatedFrame_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"
#include "rwth_perception_people_msgs/Annotation.h"

namespace rwth_perception_people_msgs
{

  class AnnotatedFrame : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _frame_type;
      _frame_type frame;
      typedef ros::Time _timestamp_type;
      _timestamp_type timestamp;
      uint32_t annotations_length;
      typedef rwth_perception_people_msgs::Annotation _annotations_type;
      _annotations_type st_annotations;
      _annotations_type * annotations;

    AnnotatedFrame():
      header(),
      frame(0),
      timestamp(),
      annotations_length(0), annotations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame;
      u_frame.real = this->frame;
      *(outbuffer + offset + 0) = (u_frame.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frame.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frame.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frame.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_frame.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_frame.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_frame.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_frame.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->frame);
      *(outbuffer + offset + 0) = (this->timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.sec);
      *(outbuffer + offset + 0) = (this->timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.nsec);
      *(outbuffer + offset + 0) = (this->annotations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->annotations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->annotations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->annotations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->annotations_length);
      for( uint32_t i = 0; i < annotations_length; i++){
      offset += this->annotations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame;
      u_frame.base = 0;
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_frame.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->frame = u_frame.real;
      offset += sizeof(this->frame);
      this->timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.sec);
      this->timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.nsec);
      uint32_t annotations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      annotations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      annotations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      annotations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->annotations_length);
      if(annotations_lengthT > annotations_length)
        this->annotations = (rwth_perception_people_msgs::Annotation*)realloc(this->annotations, annotations_lengthT * sizeof(rwth_perception_people_msgs::Annotation));
      annotations_length = annotations_lengthT;
      for( uint32_t i = 0; i < annotations_length; i++){
      offset += this->st_annotations.deserialize(inbuffer + offset);
        memcpy( &(this->annotations[i]), &(this->st_annotations), sizeof(rwth_perception_people_msgs::Annotation));
      }
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/AnnotatedFrame"; };
    const char * getMD5(){ return "82b48dede9c8aa960b68e052ed5ee37e"; };

  };

}
#endif