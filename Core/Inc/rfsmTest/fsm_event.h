#ifndef _ROS_SERVICE_fsm_event_h
#define _ROS_SERVICE_fsm_event_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rfsmTest
{

static const char FSM_EVENT[] = "rfsmTest/fsm_event";

  class fsm_eventRequest : public ros::Msg
  {
    public:
      typedef const char* _event_type;
      _event_type event;

    fsm_eventRequest():
      event("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_event = strlen(this->event);
      varToArr(outbuffer + offset, length_event);
      offset += 4;
      memcpy(outbuffer + offset, this->event, length_event);
      offset += length_event;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_event;
      arrToVar(length_event, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_event; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_event-1]=0;
      this->event = (char *)(inbuffer + offset-1);
      offset += length_event;
     return offset;
    }

    const char * getType(){ return FSM_EVENT; };
    const char * getMD5(){ return "6aea470b1ed54075e83032ee4be16538"; };

  };

  class fsm_eventResponse : public ros::Msg
  {
    public:

    fsm_eventResponse()
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

    const char * getType(){ return FSM_EVENT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class fsm_event {
    public:
    typedef fsm_eventRequest Request;
    typedef fsm_eventResponse Response;
  };

}
#endif
