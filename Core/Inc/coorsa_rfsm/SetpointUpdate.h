#ifndef _ROS_coorsa_rfsm_SetpointUpdate_h
#define _ROS_coorsa_rfsm_SetpointUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace coorsa_rfsm
{

  class SetpointUpdate : public ros::Msg
  {
    public:
      typedef int8_t _LIM_type;
      _LIM_type LIM;
      typedef float _value_type;
      _value_type value;

    SetpointUpdate():
      LIM(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_LIM;
      u_LIM.real = this->LIM;
      *(outbuffer + offset + 0) = (u_LIM.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LIM);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_LIM;
      u_LIM.base = 0;
      u_LIM.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->LIM = u_LIM.real;
      offset += sizeof(this->LIM);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return "coorsa_rfsm/SetpointUpdate"; };
    const char * getMD5(){ return "a5435513701bc6bab9ada8288fb59da4"; };

  };

}
#endif
