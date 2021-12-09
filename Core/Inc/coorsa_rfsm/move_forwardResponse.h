// Generated by gencpp from file coorsa_rfsm/move_forwardResponse.msg
// DO NOT EDIT!


#ifndef COORSA_RFSM_MESSAGE_MOVE_FORWARDRESPONSE_H
#define COORSA_RFSM_MESSAGE_MOVE_FORWARDRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace coorsa_rfsm
{
template <class ContainerAllocator>
struct move_forwardResponse_
{
  typedef move_forwardResponse_<ContainerAllocator> Type;

  move_forwardResponse_()
    {
    }
  move_forwardResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> const> ConstPtr;

}; // struct move_forwardResponse_

typedef ::coorsa_rfsm::move_forwardResponse_<std::allocator<void> > move_forwardResponse;

typedef boost::shared_ptr< ::coorsa_rfsm::move_forwardResponse > move_forwardResponsePtr;
typedef boost::shared_ptr< ::coorsa_rfsm::move_forwardResponse const> move_forwardResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace coorsa_rfsm

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "coorsa_rfsm/move_forwardResponse";
  }

  static const char* value(const ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct move_forwardResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::coorsa_rfsm::move_forwardResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // COORSA_RFSM_MESSAGE_MOVE_FORWARDRESPONSE_H