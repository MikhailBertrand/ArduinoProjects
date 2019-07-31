#ifndef _ROS_SERVICE_JobFinished_h
#define _ROS_SERVICE_JobFinished_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace srl_tracking_exporter
{

static const char JOBFINISHED[] = "srl_tracking_exporter/JobFinished";

  class JobFinishedRequest : public ros::Msg
  {
    public:
      typedef const char* _job_name_type;
      _job_name_type job_name;

    JobFinishedRequest():
      job_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_job_name = strlen(this->job_name);
      varToArr(outbuffer + offset, length_job_name);
      offset += 4;
      memcpy(outbuffer + offset, this->job_name, length_job_name);
      offset += length_job_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_job_name;
      arrToVar(length_job_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_job_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_job_name-1]=0;
      this->job_name = (char *)(inbuffer + offset-1);
      offset += length_job_name;
     return offset;
    }

    const char * getType(){ return JOBFINISHED; };
    const char * getMD5(){ return "d920fe80478d88b925da2abe2df35139"; };

  };

  class JobFinishedResponse : public ros::Msg
  {
    public:

    JobFinishedResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return JOBFINISHED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class JobFinished {
    public:
    typedef JobFinishedRequest Request;
    typedef JobFinishedResponse Response;
  };

}
#endif
