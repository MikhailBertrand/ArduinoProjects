#ifndef _ROS_SERVICE_SuspendApps_h
#define _ROS_SERVICE_SuspendApps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cube_apps
{

static const char SUSPENDAPPS[] = "cube_apps/SuspendApps";

  class SuspendAppsRequest : public ros::Msg
  {
    public:

    SuspendAppsRequest()
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

    const char * getType(){ return SUSPENDAPPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SuspendAppsResponse : public ros::Msg
  {
    public:
      typedef int8_t _responseCode_type;
      _responseCode_type responseCode;
      enum { SUCCEEDED = 0 };
      enum { REJECTED = 1    };
      enum { LOST = 9    };

    SuspendAppsResponse():
      responseCode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_responseCode;
      u_responseCode.real = this->responseCode;
      *(outbuffer + offset + 0) = (u_responseCode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->responseCode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_responseCode;
      u_responseCode.base = 0;
      u_responseCode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->responseCode = u_responseCode.real;
      offset += sizeof(this->responseCode);
     return offset;
    }

    const char * getType(){ return SUSPENDAPPS; };
    const char * getMD5(){ return "ed3766faef2fe12d47e1f3f5a75ad026"; };

  };

  class SuspendApps {
    public:
    typedef SuspendAppsRequest Request;
    typedef SuspendAppsResponse Response;
  };

}
#endif
