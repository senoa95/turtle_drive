// Generated by gencpp from file novatel_gps_msgs/NovatelFRESETRequest.msg
// DO NOT EDIT!


#ifndef NOVATEL_GPS_MSGS_MESSAGE_NOVATELFRESETREQUEST_H
#define NOVATEL_GPS_MSGS_MESSAGE_NOVATELFRESETREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace novatel_gps_msgs
{
template <class ContainerAllocator>
struct NovatelFRESETRequest_
{
  typedef NovatelFRESETRequest_<ContainerAllocator> Type;

  NovatelFRESETRequest_()
    : target()  {
    }
  NovatelFRESETRequest_(const ContainerAllocator& _alloc)
    : target(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _target_type;
  _target_type target;





  typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> const> ConstPtr;

}; // struct NovatelFRESETRequest_

typedef ::novatel_gps_msgs::NovatelFRESETRequest_<std::allocator<void> > NovatelFRESETRequest;

typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelFRESETRequest > NovatelFRESETRequestPtr;
typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelFRESETRequest const> NovatelFRESETRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace novatel_gps_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'novatel_gps_msgs': ['/home/trex/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "10e5cb524446adda5ea1765c6838590d";
  }

  static const char* value(const ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x10e5cb524446addaULL;
  static const uint64_t static_value2 = 0x5ea1765c6838590dULL;
};

template<class ContainerAllocator>
struct DataType< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "novatel_gps_msgs/NovatelFRESETRequest";
  }

  static const char* value(const ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
string target\n\
\n\
";
  }

  static const char* value(const ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.target);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NovatelFRESETRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::novatel_gps_msgs::NovatelFRESETRequest_<ContainerAllocator>& v)
  {
    s << indent << "target: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.target);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NOVATEL_GPS_MSGS_MESSAGE_NOVATELFRESETREQUEST_H
