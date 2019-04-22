// Generated by gencpp from file novatel_gps_msgs/NovatelCorrectedImuData.msg
// DO NOT EDIT!


#ifndef NOVATEL_GPS_MSGS_MESSAGE_NOVATELCORRECTEDIMUDATA_H
#define NOVATEL_GPS_MSGS_MESSAGE_NOVATELCORRECTEDIMUDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <novatel_gps_msgs/NovatelMessageHeader.h>

namespace novatel_gps_msgs
{
template <class ContainerAllocator>
struct NovatelCorrectedImuData_
{
  typedef NovatelCorrectedImuData_<ContainerAllocator> Type;

  NovatelCorrectedImuData_()
    : header()
    , novatel_msg_header()
    , gps_week_num(0)
    , gps_seconds(0.0)
    , pitch_rate(0.0)
    , roll_rate(0.0)
    , yaw_rate(0.0)
    , lateral_acceleration(0.0)
    , longitudinal_acceleration(0.0)
    , vertical_acceleration(0.0)  {
    }
  NovatelCorrectedImuData_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , novatel_msg_header(_alloc)
    , gps_week_num(0)
    , gps_seconds(0.0)
    , pitch_rate(0.0)
    , roll_rate(0.0)
    , yaw_rate(0.0)
    , lateral_acceleration(0.0)
    , longitudinal_acceleration(0.0)
    , vertical_acceleration(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::novatel_gps_msgs::NovatelMessageHeader_<ContainerAllocator>  _novatel_msg_header_type;
  _novatel_msg_header_type novatel_msg_header;

   typedef uint32_t _gps_week_num_type;
  _gps_week_num_type gps_week_num;

   typedef double _gps_seconds_type;
  _gps_seconds_type gps_seconds;

   typedef double _pitch_rate_type;
  _pitch_rate_type pitch_rate;

   typedef double _roll_rate_type;
  _roll_rate_type roll_rate;

   typedef double _yaw_rate_type;
  _yaw_rate_type yaw_rate;

   typedef double _lateral_acceleration_type;
  _lateral_acceleration_type lateral_acceleration;

   typedef double _longitudinal_acceleration_type;
  _longitudinal_acceleration_type longitudinal_acceleration;

   typedef double _vertical_acceleration_type;
  _vertical_acceleration_type vertical_acceleration;





  typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> const> ConstPtr;

}; // struct NovatelCorrectedImuData_

typedef ::novatel_gps_msgs::NovatelCorrectedImuData_<std::allocator<void> > NovatelCorrectedImuData;

typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelCorrectedImuData > NovatelCorrectedImuDataPtr;
typedef boost::shared_ptr< ::novatel_gps_msgs::NovatelCorrectedImuData const> NovatelCorrectedImuDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace novatel_gps_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'novatel_gps_msgs': ['/home/nishanth/TurtleStuff/turtle_drive/src/novatel_gps_driver/novatel_gps_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "81ec3aad90f65315c03ad2199cdd99cf";
  }

  static const char* value(const ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x81ec3aad90f65315ULL;
  static const uint64_t static_value2 = 0xc03ad2199cdd99cfULL;
};

template<class ContainerAllocator>
struct DataType< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "novatel_gps_msgs/NovatelCorrectedImuData";
  }

  static const char* value(const ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Parsed corrected IMU data from Novatel OEM6 receiver\n\
Header header\n\
\n\
NovatelMessageHeader novatel_msg_header\n\
\n\
uint32 gps_week_num\n\
float64 gps_seconds\n\
\n\
# All measurements in this message are instantaneous values;\n\
# attitude rate is in radians\n\
float64 pitch_rate\n\
float64 roll_rate\n\
float64 yaw_rate\n\
\n\
# accelerations are in m/s\n\
float64 lateral_acceleration\n\
float64 longitudinal_acceleration\n\
float64 vertical_acceleration\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: novatel_gps_msgs/NovatelMessageHeader\n\
# Novatel Message Header\n\
\n\
string message_name\n\
string port\n\
uint32 sequence_num\n\
float32 percent_idle_time\n\
string gps_time_status\n\
uint32 gps_week_num\n\
float64 gps_seconds\n\
\n\
# Bit       Mask      Description\n\
#  0     0x00000001   Error flag (Bit = 0: No Error, Bit = 1: Error)\n\
#  1     0x00000002   Temperature Status (0: Within Spec, 1: Warning)\n\
#  2     0x00000004   Voltage Supply Status (0: OK, 1: Warning)\n\
#  3     0x00000008   Antenna Power Status (0: Powered, 1: Not Powered)\n\
#  4     0x00000010   <Reserved>\n\
#  5     0x00000020   Antenna open flag (0: OK, 1: Open)\n\
#  6     0x00000040   Antenna shorted flag (0: OK, 1: Shorted)\n\
#  7     0x00000080   CPU overload flag\n\
#  8     0x00000100   COM1 buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  9     0x00000200   COM2 buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  10    0x00000400   COM3 buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  11    0x00000800   USB buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  12    0x00001000   <Reserved>\n\
#  13    0x00002000   <Reserved>\n\
#  14    0x00004000   <Reserved>\n\
#  15    0x00008000   RF1 AGC Status (0: OK, 1: Bad)\n\
#  16    0x00010000   <Reserverd>\n\
#  17    0x00020000   RF2 AGC status (0: OK, 1: Bad)\n\
#  18    0x00040000   Almanac flag/UTC known (0: Valid, 1: Invalid)\n\
#  19    0x00080000   Position solution flag (0: Valid, 1: Invalid)\n\
#  20    0x00100000   Position fixed flag (0: Not fixed, 1: Fixed)\n\
#  21    0x00200000   Clock steering status (0: Enabled, 1: Disabled)\n\
#  22    0x00400000   Clock model flag (0: Valid, 1: Invalid)\n\
#  23    0x00800000   OEMV external oscillator flag (0: Disabled, 1: Enabled)\n\
#  24    0x01000000   Software resource (0: OK, 1: Warning)\n\
#  25    0x02000000   <Reserved>\n\
#  26    0x04000000   <Reserved>\n\
#  27    0x08000000   <Reserved>\n\
#  28    0x10000000   <Reserved>\n\
#  29    0x20000000   Auxiliary 3 status event flag (0: No event, 1: Event)\n\
#  30    0x40000000   Auxiliary 2 status event flag (0: No event, 1: Event)\n\
#  31    0x80000000   Auxiliary 1 status event flag (0: No event, 1: Event)\n\
NovatelReceiverStatus receiver_status\n\
\n\
# Receiver build number (0-65535)\n\
uint32 receiver_software_version\n\
================================================================================\n\
MSG: novatel_gps_msgs/NovatelReceiverStatus\n\
# From the original Novatel receiver status message bitfield\n\
#  0     0x00000001   Error flag (Bit = 0: No Error, Bit = 1: Error)\n\
#  1     0x00000002   Temperature Status (0: Within Spec, 1: Warning)\n\
#  2     0x00000004   Voltage Supply Status (0: OK, 1: Warning)\n\
#  3     0x00000008   Antenna Power Status (0: Powered, 1: Not Powered)\n\
#  4     0x00000010   <Reserved>\n\
#  5     0x00000020   Antenna open flag (0: OK, 1: Open)\n\
#  6     0x00000040   Antenna shorted flag (0: OK, 1: Shorted)\n\
#  7     0x00000080   CPU overload flag\n\
#  8     0x00000100   COM1 buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  9     0x00000200   COM2 buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  10    0x00000400   COM3 buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  11    0x00000800   USB buffer overrun flag (0: No overrun, 1: Overrun)\n\
#  12    0x00001000   <Reserved>\n\
#  13    0x00002000   <Reserved>\n\
#  14    0x00004000   <Reserved>\n\
#  15    0x00008000   RF1 AGC Status (0: OK, 1: Bad)\n\
#  16    0x00010000   <Reserverd>\n\
#  17    0x00020000   RF2 AGC status (0: OK, 1: Bad)\n\
#  18    0x00040000   Almanac flag/UTC known (0: Valid, 1: Invalid)\n\
#  19    0x00080000   Position solution flag (0: Valid, 1: Invalid)\n\
#  20    0x00100000   Position fixed flag (0: Not fixed, 1: Fixed)\n\
#  21    0x00200000   Clock steering status (0: Enabled, 1: Disabled)\n\
#  22    0x00400000   Clock model flag (0: Valid, 1: Invalid)\n\
#  23    0x00800000   OEMV external oscillator flag (0: Disabled, 1: Enabled)\n\
#  24    0x01000000   Software resource (0: OK, 1: Warning)\n\
#  25    0x02000000   <Reserved>\n\
#  26    0x04000000   <Reserved>\n\
#  27    0x08000000   <Reserved>\n\
#  28    0x10000000   <Reserved>\n\
#  29    0x20000000   Auxiliary 3 status event flag (0: No event, 1: Event)\n\
#  30    0x40000000   Auxiliary 2 status event flag (0: No event, 1: Event)\n\
#  31    0x80000000   Auxiliary 1 status event flag (0: No event, 1: Event)\n\
uint32 original_status_code\n\
bool error_flag\n\
bool temperature_flag\n\
bool voltage_supply_flag\n\
bool antenna_powered\n\
bool antenna_is_open\n\
bool antenna_is_shorted\n\
bool cpu_overload_flag\n\
bool com1_buffer_overrun\n\
bool com2_buffer_overrun\n\
bool com3_buffer_overrun\n\
bool usb_buffer_overrun\n\
bool rf1_agc_flag\n\
bool rf2_agc_flag\n\
bool almanac_flag\n\
bool position_solution_flag\n\
bool position_fixed_flag\n\
bool clock_steering_status_enabled\n\
bool clock_model_flag\n\
bool oemv_external_oscillator_flag\n\
bool software_resource_flag\n\
bool aux1_status_event_flag\n\
bool aux2_status_event_flag\n\
bool aux3_status_event_flag\n\
\n\
";
  }

  static const char* value(const ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.novatel_msg_header);
      stream.next(m.gps_week_num);
      stream.next(m.gps_seconds);
      stream.next(m.pitch_rate);
      stream.next(m.roll_rate);
      stream.next(m.yaw_rate);
      stream.next(m.lateral_acceleration);
      stream.next(m.longitudinal_acceleration);
      stream.next(m.vertical_acceleration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NovatelCorrectedImuData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::novatel_gps_msgs::NovatelCorrectedImuData_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "novatel_msg_header: ";
    s << std::endl;
    Printer< ::novatel_gps_msgs::NovatelMessageHeader_<ContainerAllocator> >::stream(s, indent + "  ", v.novatel_msg_header);
    s << indent << "gps_week_num: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.gps_week_num);
    s << indent << "gps_seconds: ";
    Printer<double>::stream(s, indent + "  ", v.gps_seconds);
    s << indent << "pitch_rate: ";
    Printer<double>::stream(s, indent + "  ", v.pitch_rate);
    s << indent << "roll_rate: ";
    Printer<double>::stream(s, indent + "  ", v.roll_rate);
    s << indent << "yaw_rate: ";
    Printer<double>::stream(s, indent + "  ", v.yaw_rate);
    s << indent << "lateral_acceleration: ";
    Printer<double>::stream(s, indent + "  ", v.lateral_acceleration);
    s << indent << "longitudinal_acceleration: ";
    Printer<double>::stream(s, indent + "  ", v.longitudinal_acceleration);
    s << indent << "vertical_acceleration: ";
    Printer<double>::stream(s, indent + "  ", v.vertical_acceleration);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NOVATEL_GPS_MSGS_MESSAGE_NOVATELCORRECTEDIMUDATA_H
