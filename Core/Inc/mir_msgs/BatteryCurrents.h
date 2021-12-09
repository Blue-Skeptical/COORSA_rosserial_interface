#ifndef _ROS_mir_msgs_BatteryCurrents_h
#define _ROS_mir_msgs_BatteryCurrents_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mir_msgs
{

  class BatteryCurrents : public ros::Msg
  {
    public:
      typedef double _battery1_current_type;
      _battery1_current_type battery1_current;
      typedef double _battery2_current_type;
      _battery2_current_type battery2_current;

    BatteryCurrents():
      battery1_current(0),
      battery2_current(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_battery1_current;
      u_battery1_current.real = this->battery1_current;
      *(outbuffer + offset + 0) = (u_battery1_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery1_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery1_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery1_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_battery1_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_battery1_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_battery1_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_battery1_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->battery1_current);
      union {
        double real;
        uint64_t base;
      } u_battery2_current;
      u_battery2_current.real = this->battery2_current;
      *(outbuffer + offset + 0) = (u_battery2_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery2_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery2_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery2_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_battery2_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_battery2_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_battery2_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_battery2_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->battery2_current);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_battery1_current;
      u_battery1_current.base = 0;
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_battery1_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->battery1_current = u_battery1_current.real;
      offset += sizeof(this->battery1_current);
      union {
        double real;
        uint64_t base;
      } u_battery2_current;
      u_battery2_current.base = 0;
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_battery2_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->battery2_current = u_battery2_current.real;
      offset += sizeof(this->battery2_current);
     return offset;
    }

    const char * getType(){ return "mir_msgs/BatteryCurrents"; };
    const char * getMD5(){ return "99e76fe5e1c8183e9d7ded8c13ebdf16"; };

  };

}
#endif
