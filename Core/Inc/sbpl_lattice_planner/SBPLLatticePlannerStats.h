#ifndef _ROS_sbpl_lattice_planner_SBPLLatticePlannerStats_h
#define _ROS_sbpl_lattice_planner_SBPLLatticePlannerStats_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace sbpl_lattice_planner
{

  class SBPLLatticePlannerStats : public ros::Msg
  {
    public:
      typedef double _initial_epsilon_type;
      _initial_epsilon_type initial_epsilon;
      typedef double _final_epsilon_type;
      _final_epsilon_type final_epsilon;
      typedef bool _plan_to_first_solution_type;
      _plan_to_first_solution_type plan_to_first_solution;
      typedef double _allocated_time_type;
      _allocated_time_type allocated_time;
      typedef double _actual_time_type;
      _actual_time_type actual_time;
      typedef double _time_to_first_solution_type;
      _time_to_first_solution_type time_to_first_solution;
      typedef double _solution_cost_type;
      _solution_cost_type solution_cost;
      typedef double _path_size_type;
      _path_size_type path_size;
      typedef int64_t _final_number_of_expands_type;
      _final_number_of_expands_type final_number_of_expands;
      typedef int64_t _number_of_expands_initial_solution_type;
      _number_of_expands_initial_solution_type number_of_expands_initial_solution;
      typedef geometry_msgs::PoseStamped _start_type;
      _start_type start;
      typedef geometry_msgs::PoseStamped _goal_type;
      _goal_type goal;

    SBPLLatticePlannerStats():
      initial_epsilon(0),
      final_epsilon(0),
      plan_to_first_solution(0),
      allocated_time(0),
      actual_time(0),
      time_to_first_solution(0),
      solution_cost(0),
      path_size(0),
      final_number_of_expands(0),
      number_of_expands_initial_solution(0),
      start(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_initial_epsilon;
      u_initial_epsilon.real = this->initial_epsilon;
      *(outbuffer + offset + 0) = (u_initial_epsilon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_initial_epsilon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_initial_epsilon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_initial_epsilon.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_initial_epsilon.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_initial_epsilon.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_initial_epsilon.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_initial_epsilon.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->initial_epsilon);
      union {
        double real;
        uint64_t base;
      } u_final_epsilon;
      u_final_epsilon.real = this->final_epsilon;
      *(outbuffer + offset + 0) = (u_final_epsilon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_final_epsilon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_final_epsilon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_final_epsilon.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_final_epsilon.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_final_epsilon.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_final_epsilon.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_final_epsilon.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->final_epsilon);
      union {
        bool real;
        uint8_t base;
      } u_plan_to_first_solution;
      u_plan_to_first_solution.real = this->plan_to_first_solution;
      *(outbuffer + offset + 0) = (u_plan_to_first_solution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_to_first_solution);
      union {
        double real;
        uint64_t base;
      } u_allocated_time;
      u_allocated_time.real = this->allocated_time;
      *(outbuffer + offset + 0) = (u_allocated_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_allocated_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_allocated_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_allocated_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_allocated_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_allocated_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_allocated_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_allocated_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->allocated_time);
      union {
        double real;
        uint64_t base;
      } u_actual_time;
      u_actual_time.real = this->actual_time;
      *(outbuffer + offset + 0) = (u_actual_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actual_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actual_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actual_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_actual_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_actual_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_actual_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_actual_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->actual_time);
      union {
        double real;
        uint64_t base;
      } u_time_to_first_solution;
      u_time_to_first_solution.real = this->time_to_first_solution;
      *(outbuffer + offset + 0) = (u_time_to_first_solution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_to_first_solution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_to_first_solution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_to_first_solution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time_to_first_solution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time_to_first_solution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time_to_first_solution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time_to_first_solution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time_to_first_solution);
      union {
        double real;
        uint64_t base;
      } u_solution_cost;
      u_solution_cost.real = this->solution_cost;
      *(outbuffer + offset + 0) = (u_solution_cost.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_solution_cost.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_solution_cost.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_solution_cost.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_solution_cost.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_solution_cost.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_solution_cost.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_solution_cost.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->solution_cost);
      union {
        double real;
        uint64_t base;
      } u_path_size;
      u_path_size.real = this->path_size;
      *(outbuffer + offset + 0) = (u_path_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_path_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_path_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_path_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_path_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_path_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_path_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_path_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->path_size);
      union {
        int64_t real;
        uint64_t base;
      } u_final_number_of_expands;
      u_final_number_of_expands.real = this->final_number_of_expands;
      *(outbuffer + offset + 0) = (u_final_number_of_expands.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_final_number_of_expands.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_final_number_of_expands.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_final_number_of_expands.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_final_number_of_expands.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_final_number_of_expands.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_final_number_of_expands.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_final_number_of_expands.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->final_number_of_expands);
      union {
        int64_t real;
        uint64_t base;
      } u_number_of_expands_initial_solution;
      u_number_of_expands_initial_solution.real = this->number_of_expands_initial_solution;
      *(outbuffer + offset + 0) = (u_number_of_expands_initial_solution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_expands_initial_solution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_expands_initial_solution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_expands_initial_solution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_number_of_expands_initial_solution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_number_of_expands_initial_solution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_number_of_expands_initial_solution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_number_of_expands_initial_solution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->number_of_expands_initial_solution);
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_initial_epsilon;
      u_initial_epsilon.base = 0;
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_initial_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->initial_epsilon = u_initial_epsilon.real;
      offset += sizeof(this->initial_epsilon);
      union {
        double real;
        uint64_t base;
      } u_final_epsilon;
      u_final_epsilon.base = 0;
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_final_epsilon.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->final_epsilon = u_final_epsilon.real;
      offset += sizeof(this->final_epsilon);
      union {
        bool real;
        uint8_t base;
      } u_plan_to_first_solution;
      u_plan_to_first_solution.base = 0;
      u_plan_to_first_solution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan_to_first_solution = u_plan_to_first_solution.real;
      offset += sizeof(this->plan_to_first_solution);
      union {
        double real;
        uint64_t base;
      } u_allocated_time;
      u_allocated_time.base = 0;
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_allocated_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->allocated_time = u_allocated_time.real;
      offset += sizeof(this->allocated_time);
      union {
        double real;
        uint64_t base;
      } u_actual_time;
      u_actual_time.base = 0;
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_actual_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->actual_time = u_actual_time.real;
      offset += sizeof(this->actual_time);
      union {
        double real;
        uint64_t base;
      } u_time_to_first_solution;
      u_time_to_first_solution.base = 0;
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time_to_first_solution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time_to_first_solution = u_time_to_first_solution.real;
      offset += sizeof(this->time_to_first_solution);
      union {
        double real;
        uint64_t base;
      } u_solution_cost;
      u_solution_cost.base = 0;
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_solution_cost.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->solution_cost = u_solution_cost.real;
      offset += sizeof(this->solution_cost);
      union {
        double real;
        uint64_t base;
      } u_path_size;
      u_path_size.base = 0;
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_path_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->path_size = u_path_size.real;
      offset += sizeof(this->path_size);
      union {
        int64_t real;
        uint64_t base;
      } u_final_number_of_expands;
      u_final_number_of_expands.base = 0;
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->final_number_of_expands = u_final_number_of_expands.real;
      offset += sizeof(this->final_number_of_expands);
      union {
        int64_t real;
        uint64_t base;
      } u_number_of_expands_initial_solution;
      u_number_of_expands_initial_solution.base = 0;
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->number_of_expands_initial_solution = u_number_of_expands_initial_solution.real;
      offset += sizeof(this->number_of_expands_initial_solution);
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "sbpl_lattice_planner/SBPLLatticePlannerStats"; };
    const char * getMD5(){ return "b1c85b1cec5e7b196cc477ac1440bbf0"; };

  };

}
#endif
