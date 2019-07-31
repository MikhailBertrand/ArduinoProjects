#ifndef _ROS_SERVICE_DeleteGroup_h
#define _ROS_SERVICE_DeleteGroup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_gazebo_models
{

static const char DELETEGROUP[] = "dynamic_gazebo_models/DeleteGroup";

  class DeleteGroupRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;

    DeleteGroupRequest():
      group_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
     return offset;
    }

    const char * getType(){ return DELETEGROUP; };
    const char * getMD5(){ return "967d0b0c0d858ded8a6a69abbce0c981"; };

  };

  class DeleteGroupResponse : public ros::Msg
  {
    public:
      typedef const char* _feedback_type;
      _feedback_type feedback;

    DeleteGroupResponse():
      feedback("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_feedback = strlen(this->feedback);
      varToArr(outbuffer + offset, length_feedback);
      offset += 4;
      memcpy(outbuffer + offset, this->feedback, length_feedback);
      offset += length_feedback;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_feedback;
      arrToVar(length_feedback, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_feedback; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_feedback-1]=0;
      this->feedback = (char *)(inbuffer + offset-1);
      offset += length_feedback;
     return offset;
    }

    const char * getType(){ return DELETEGROUP; };
    const char * getMD5(){ return "c14cdf907e5c7c7fd47292add15660f0"; };

  };

  class DeleteGroup {
    public:
    typedef DeleteGroupRequest Request;
    typedef DeleteGroupResponse Response;
  };

}
#endif
