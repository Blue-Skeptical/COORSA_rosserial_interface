#ifndef _ROS_mir_msgs_BMSData_h
#define _ROS_mir_msgs_BMSData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mir_msgs
{

  class BMSData : public ros::Msg
  {
    public:
      typedef double _pack_voltage_type;
      _pack_voltage_type pack_voltage;
      typedef double _charge_current_type;
      _charge_current_type charge_current;
      typedef double _discharge_current_type;
      _discharge_current_type discharge_current;
      typedef int32_t _state_of_charge_type;
      _state_of_charge_type state_of_charge;
      typedef double _remaining_time_to_full_charge_type;
      _remaining_time_to_full_charge_type remaining_time_to_full_charge;
      typedef int32_t _remaining_capacity_type;
      _remaining_capacity_type remaining_capacity;
      typedef int32_t _state_of_health_type;
      _state_of_health_type state_of_health;
      typedef int32_t _status_flags_type;
      _status_flags_type status_flags;
      typedef int32_t _temperature_type;
      _temperature_type temperature;
      uint32_t cell_voltage_length;
      typedef uint32_t _cell_voltage_type;
      _cell_voltage_type st_cell_voltage;
      _cell_voltage_type * cell_voltage;
      typedef double _last_battery_msg_time_type;
      _last_battery_msg_time_type last_battery_msg_time;
      enum { DISCHARGING = 1 };
      enum { CHARGING = 2 };

    BMSData():
      pack_voltage(0),
      charge_current(0),
      discharge_current(0),
      state_of_charge(0),
      remaining_time_to_full_charge(0),
      remaining_capacity(0),
      state_of_health(0),
      status_flags(0),
      temperature(0),
      cell_voltage_length(0), cell_voltage(NULL),
      last_battery_msg_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_pack_voltage;
      u_pack_voltage.real = this->pack_voltage;
      *(outbuffer + offset + 0) = (u_pack_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pack_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pack_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pack_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pack_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pack_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pack_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pack_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pack_voltage);
      union {
        double real;
        uint64_t base;
      } u_charge_current;
      u_charge_current.real = this->charge_current;
      *(outbuffer + offset + 0) = (u_charge_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_charge_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_charge_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_charge_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_charge_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->charge_current);
      union {
        double real;
        uint64_t base;
      } u_discharge_current;
      u_discharge_current.real = this->discharge_current;
      *(outbuffer + offset + 0) = (u_discharge_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_discharge_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_discharge_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_discharge_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_discharge_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_discharge_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_discharge_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_discharge_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->discharge_current);
      union {
        int32_t real;
        uint32_t base;
      } u_state_of_charge;
      u_state_of_charge.real = this->state_of_charge;
      *(outbuffer + offset + 0) = (u_state_of_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_of_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_of_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_of_charge.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_of_charge);
      union {
        double real;
        uint64_t base;
      } u_remaining_time_to_full_charge;
      u_remaining_time_to_full_charge.real = this->remaining_time_to_full_charge;
      *(outbuffer + offset + 0) = (u_remaining_time_to_full_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remaining_time_to_full_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remaining_time_to_full_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remaining_time_to_full_charge.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_remaining_time_to_full_charge.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_remaining_time_to_full_charge.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_remaining_time_to_full_charge.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_remaining_time_to_full_charge.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->remaining_time_to_full_charge);
      union {
        int32_t real;
        uint32_t base;
      } u_remaining_capacity;
      u_remaining_capacity.real = this->remaining_capacity;
      *(outbuffer + offset + 0) = (u_remaining_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remaining_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remaining_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remaining_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remaining_capacity);
      union {
        int32_t real;
        uint32_t base;
      } u_state_of_health;
      u_state_of_health.real = this->state_of_health;
      *(outbuffer + offset + 0) = (u_state_of_health.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_of_health.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_of_health.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_of_health.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_of_health);
      union {
        int32_t real;
        uint32_t base;
      } u_status_flags;
      u_status_flags.real = this->status_flags;
      *(outbuffer + offset + 0) = (u_status_flags.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status_flags.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_status_flags.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_status_flags.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_flags);
      union {
        int32_t real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      *(outbuffer + offset + 0) = (this->cell_voltage_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cell_voltage_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cell_voltage_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cell_voltage_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cell_voltage_length);
      for( uint32_t i = 0; i < cell_voltage_length; i++){
      *(outbuffer + offset + 0) = (this->cell_voltage[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cell_voltage[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cell_voltage[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cell_voltage[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cell_voltage[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_last_battery_msg_time;
      u_last_battery_msg_time.real = this->last_battery_msg_time;
      *(outbuffer + offset + 0) = (u_last_battery_msg_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_battery_msg_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_battery_msg_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_battery_msg_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_battery_msg_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_battery_msg_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_battery_msg_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_battery_msg_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_battery_msg_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_pack_voltage;
      u_pack_voltage.base = 0;
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pack_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pack_voltage = u_pack_voltage.real;
      offset += sizeof(this->pack_voltage);
      union {
        double real;
        uint64_t base;
      } u_charge_current;
      u_charge_current.base = 0;
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_charge_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->charge_current = u_charge_current.real;
      offset += sizeof(this->charge_current);
      union {
        double real;
        uint64_t base;
      } u_discharge_current;
      u_discharge_current.base = 0;
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_discharge_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->discharge_current = u_discharge_current.real;
      offset += sizeof(this->discharge_current);
      union {
        int32_t real;
        uint32_t base;
      } u_state_of_charge;
      u_state_of_charge.base = 0;
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_of_charge = u_state_of_charge.real;
      offset += sizeof(this->state_of_charge);
      union {
        double real;
        uint64_t base;
      } u_remaining_time_to_full_charge;
      u_remaining_time_to_full_charge.base = 0;
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_remaining_time_to_full_charge.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->remaining_time_to_full_charge = u_remaining_time_to_full_charge.real;
      offset += sizeof(this->remaining_time_to_full_charge);
      union {
        int32_t real;
        uint32_t base;
      } u_remaining_capacity;
      u_remaining_capacity.base = 0;
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remaining_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->remaining_capacity = u_remaining_capacity.real;
      offset += sizeof(this->remaining_capacity);
      union {
        int32_t real;
        uint32_t base;
      } u_state_of_health;
      u_state_of_health.base = 0;
      u_state_of_health.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_of_health.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_of_health.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_of_health.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_of_health = u_state_of_health.real;
      offset += sizeof(this->state_of_health);
      union {
        int32_t real;
        uint32_t base;
      } u_status_flags;
      u_status_flags.base = 0;
      u_status_flags.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status_flags.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_status_flags.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_status_flags.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->status_flags = u_status_flags.real;
      offset += sizeof(this->status_flags);
      union {
        int32_t real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      uint32_t cell_voltage_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cell_voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cell_voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cell_voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cell_voltage_length);
      if(cell_voltage_lengthT > cell_voltage_length)
        this->cell_voltage = (uint32_t*)realloc(this->cell_voltage, cell_voltage_lengthT * sizeof(uint32_t));
      cell_voltage_length = cell_voltage_lengthT;
      for( uint32_t i = 0; i < cell_voltage_length; i++){
      this->st_cell_voltage =  ((uint32_t) (*(inbuffer + offset)));
      this->st_cell_voltage |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_cell_voltage |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_cell_voltage |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_cell_voltage);
        memcpy( &(this->cell_voltage[i]), &(this->st_cell_voltage), sizeof(uint32_t));
      }
      union {
        double real;
        uint64_t base;
      } u_last_battery_msg_time;
      u_last_battery_msg_time.base = 0;
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_battery_msg_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_battery_msg_time = u_last_battery_msg_time.real;
      offset += sizeof(this->last_battery_msg_time);
     return offset;
    }

    const char * getType(){ return "mir_msgs/BMSData"; };
    const char * getMD5(){ return "d493696478cec84b48f8cbfeb3941739"; };

  };

}
#endif
