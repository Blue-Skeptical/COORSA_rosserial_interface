#ifndef _ROS_mir_msgs_ChargingState_h
#define _ROS_mir_msgs_ChargingState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mir_msgs
{

  class ChargingState : public ros::Msg
  {
    public:
      typedef bool _charging_relay_type;
      _charging_relay_type charging_relay;
      typedef double _charging_current_type;
      _charging_current_type charging_current;
      typedef uint32_t _charging_current_raw_type;
      _charging_current_raw_type charging_current_raw;
      typedef double _last_time_current_type;
      _last_time_current_type last_time_current;
      typedef double _charging_voltage_type;
      _charging_voltage_type charging_voltage;
      typedef uint32_t _charging_voltage_raw_type;
      _charging_voltage_raw_type charging_voltage_raw;
      typedef bool _is_voltage_low_type;
      _is_voltage_low_type is_voltage_low;
      typedef double _last_time_voltage_type;
      _last_time_voltage_type last_time_voltage;

    ChargingState():
      charging_relay(0),
      charging_current(0),
      charging_current_raw(0),
      last_time_current(0),
      charging_voltage(0),
      charging_voltage_raw(0),
      is_voltage_low(0),
      last_time_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_charging_relay;
      u_charging_relay.real = this->charging_relay;
      *(outbuffer + offset + 0) = (u_charging_relay.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charging_relay);
      union {
        double real;
        uint64_t base;
      } u_charging_current;
      u_charging_current.real = this->charging_current;
      *(outbuffer + offset + 0) = (u_charging_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charging_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charging_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charging_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_charging_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_charging_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_charging_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_charging_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->charging_current);
      *(outbuffer + offset + 0) = (this->charging_current_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charging_current_raw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->charging_current_raw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->charging_current_raw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charging_current_raw);
      union {
        double real;
        uint64_t base;
      } u_last_time_current;
      u_last_time_current.real = this->last_time_current;
      *(outbuffer + offset + 0) = (u_last_time_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_time_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_time_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_time_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_time_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_time_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_time_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_time_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_time_current);
      union {
        double real;
        uint64_t base;
      } u_charging_voltage;
      u_charging_voltage.real = this->charging_voltage;
      *(outbuffer + offset + 0) = (u_charging_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charging_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charging_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charging_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_charging_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_charging_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_charging_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_charging_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->charging_voltage);
      *(outbuffer + offset + 0) = (this->charging_voltage_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charging_voltage_raw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->charging_voltage_raw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->charging_voltage_raw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charging_voltage_raw);
      union {
        bool real;
        uint8_t base;
      } u_is_voltage_low;
      u_is_voltage_low.real = this->is_voltage_low;
      *(outbuffer + offset + 0) = (u_is_voltage_low.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_voltage_low);
      union {
        double real;
        uint64_t base;
      } u_last_time_voltage;
      u_last_time_voltage.real = this->last_time_voltage;
      *(outbuffer + offset + 0) = (u_last_time_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_time_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_time_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_time_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_time_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_time_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_time_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_time_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_time_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_charging_relay;
      u_charging_relay.base = 0;
      u_charging_relay.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->charging_relay = u_charging_relay.real;
      offset += sizeof(this->charging_relay);
      union {
        double real;
        uint64_t base;
      } u_charging_current;
      u_charging_current.base = 0;
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_charging_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->charging_current = u_charging_current.real;
      offset += sizeof(this->charging_current);
      this->charging_current_raw =  ((uint32_t) (*(inbuffer + offset)));
      this->charging_current_raw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->charging_current_raw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->charging_current_raw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->charging_current_raw);
      union {
        double real;
        uint64_t base;
      } u_last_time_current;
      u_last_time_current.base = 0;
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_time_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_time_current = u_last_time_current.real;
      offset += sizeof(this->last_time_current);
      union {
        double real;
        uint64_t base;
      } u_charging_voltage;
      u_charging_voltage.base = 0;
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_charging_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->charging_voltage = u_charging_voltage.real;
      offset += sizeof(this->charging_voltage);
      this->charging_voltage_raw =  ((uint32_t) (*(inbuffer + offset)));
      this->charging_voltage_raw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->charging_voltage_raw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->charging_voltage_raw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->charging_voltage_raw);
      union {
        bool real;
        uint8_t base;
      } u_is_voltage_low;
      u_is_voltage_low.base = 0;
      u_is_voltage_low.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_voltage_low = u_is_voltage_low.real;
      offset += sizeof(this->is_voltage_low);
      union {
        double real;
        uint64_t base;
      } u_last_time_voltage;
      u_last_time_voltage.base = 0;
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_time_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_time_voltage = u_last_time_voltage.real;
      offset += sizeof(this->last_time_voltage);
     return offset;
    }

    const char * getType(){ return "mir_msgs/ChargingState"; };
    const char * getMD5(){ return "1393c08007cacc5b837577273ba19ce7"; };

  };

}
#endif
