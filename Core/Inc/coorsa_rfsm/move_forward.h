// Generated by gencpp from file coorsa_rfsm/move_forward.msg
// DO NOT EDIT!


#ifndef COORSA_RFSM_MESSAGE_MOVE_FORWARD_H
#define COORSA_RFSM_MESSAGE_MOVE_FORWARD_H

#include <ros/service_traits.h>


#include <coorsa_rfsm/move_forwardRequest.h>
#include <coorsa_rfsm/move_forwardResponse.h>


namespace coorsa_rfsm
{

struct move_forward
{

typedef move_forwardRequest Request;
typedef move_forwardResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct move_forward
} // namespace coorsa_rfsm


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::coorsa_rfsm::move_forward > {
  static const char* value()
  {
    return "9dd3534bfa42243ad538074d47a7fb4a";
  }

  static const char* value(const ::coorsa_rfsm::move_forward&) { return value(); }
};

template<>
struct DataType< ::coorsa_rfsm::move_forward > {
  static const char* value()
  {
    return "coorsa_rfsm/move_forward";
  }

  static const char* value(const ::coorsa_rfsm::move_forward&) { return value(); }
};


// service_traits::MD5Sum< ::coorsa_rfsm::move_forwardRequest> should match
// service_traits::MD5Sum< ::coorsa_rfsm::move_forward >
template<>
struct MD5Sum< ::coorsa_rfsm::move_forwardRequest>
{
  static const char* value()
  {
    return MD5Sum< ::coorsa_rfsm::move_forward >::value();
  }
  static const char* value(const ::coorsa_rfsm::move_forwardRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::coorsa_rfsm::move_forwardRequest> should match
// service_traits::DataType< ::coorsa_rfsm::move_forward >
template<>
struct DataType< ::coorsa_rfsm::move_forwardRequest>
{
  static const char* value()
  {
    return DataType< ::coorsa_rfsm::move_forward >::value();
  }
  static const char* value(const ::coorsa_rfsm::move_forwardRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::coorsa_rfsm::move_forwardResponse> should match
// service_traits::MD5Sum< ::coorsa_rfsm::move_forward >
template<>
struct MD5Sum< ::coorsa_rfsm::move_forwardResponse>
{
  static const char* value()
  {
    return MD5Sum< ::coorsa_rfsm::move_forward >::value();
  }
  static const char* value(const ::coorsa_rfsm::move_forwardResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::coorsa_rfsm::move_forwardResponse> should match
// service_traits::DataType< ::coorsa_rfsm::move_forward >
template<>
struct DataType< ::coorsa_rfsm::move_forwardResponse>
{
  static const char* value()
  {
    return DataType< ::coorsa_rfsm::move_forward >::value();
  }
  static const char* value(const ::coorsa_rfsm::move_forwardResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // COORSA_RFSM_MESSAGE_MOVE_FORWARD_H
