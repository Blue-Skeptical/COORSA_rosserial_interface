#ifndef _ROS_sdc21x0_StampedEncoders_h
#define _ROS_sdc21x0_StampedEncoders_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sdc21x0/Encoders.h"

namespace sdc21x0
{

  class StampedEncoders : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sdc21x0::Encoders _encoders_type;
      _encoders_type encoders;

    StampedEncoders():
      header(),
      encoders()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->encoders.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->encoders.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "sdc21x0/StampedEncoders"; };
    const char * getMD5(){ return "7c217717e3bf9ebebdee0e043bc42e56"; };

  };

}
#endif
