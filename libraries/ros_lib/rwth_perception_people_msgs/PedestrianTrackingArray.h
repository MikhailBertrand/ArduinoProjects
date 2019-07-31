#ifndef _ROS_rwth_perception_people_msgs_PedestrianTrackingArray_h
#define _ROS_rwth_perception_people_msgs_PedestrianTrackingArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rwth_perception_people_msgs/PedestrianTracking.h"

namespace rwth_perception_people_msgs
{

  class PedestrianTrackingArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t pedestrians_length;
      typedef rwth_perception_people_msgs::PedestrianTracking _pedestrians_type;
      _pedestrians_type st_pedestrians;
      _pedestrians_type * pedestrians;

    PedestrianTrackingArray():
      header(),
      pedestrians_length(0), pedestrians(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pedestrians_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pedestrians_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pedestrians_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pedestrians_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pedestrians_length);
      for( uint32_t i = 0; i < pedestrians_length; i++){
      offset += this->pedestrians[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t pedestrians_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pedestrians_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pedestrians_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pedestrians_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pedestrians_length);
      if(pedestrians_lengthT > pedestrians_length)
        this->pedestrians = (rwth_perception_people_msgs::PedestrianTracking*)realloc(this->pedestrians, pedestrians_lengthT * sizeof(rwth_perception_people_msgs::PedestrianTracking));
      pedestrians_length = pedestrians_lengthT;
      for( uint32_t i = 0; i < pedestrians_length; i++){
      offset += this->st_pedestrians.deserialize(inbuffer + offset);
        memcpy( &(this->pedestrians[i]), &(this->st_pedestrians), sizeof(rwth_perception_people_msgs::PedestrianTracking));
      }
     return offset;
    }

    const char * getType(){ return "rwth_perception_people_msgs/PedestrianTrackingArray"; };
    const char * getMD5(){ return "a9f67479ca0db5489cca876d9f98fd50"; };

  };

}
#endif