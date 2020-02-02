// Generated by gencpp from file riki_msgs/Battery.msg
// DO NOT EDIT!


#ifndef RIKI_MSGS_MESSAGE_BATTERY_H
#define RIKI_MSGS_MESSAGE_BATTERY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace riki_msgs
{
template <class ContainerAllocator>
struct Battery_
{
  typedef Battery_<ContainerAllocator> Type;

  Battery_()
    : battery(0.0)  {
    }
  Battery_(const ContainerAllocator& _alloc)
    : battery(0.0)  {
  (void)_alloc;
    }



   typedef float _battery_type;
  _battery_type battery;




  typedef boost::shared_ptr< ::riki_msgs::Battery_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::riki_msgs::Battery_<ContainerAllocator> const> ConstPtr;

}; // struct Battery_

typedef ::riki_msgs::Battery_<std::allocator<void> > Battery;

typedef boost::shared_ptr< ::riki_msgs::Battery > BatteryPtr;
typedef boost::shared_ptr< ::riki_msgs::Battery const> BatteryConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::riki_msgs::Battery_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::riki_msgs::Battery_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace riki_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'riki_msgs': ['/home/riki/catkin_ws/src/rikirobot_project/riki_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::riki_msgs::Battery_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::riki_msgs::Battery_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::riki_msgs::Battery_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::riki_msgs::Battery_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::riki_msgs::Battery_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::riki_msgs::Battery_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::riki_msgs::Battery_<ContainerAllocator> >
{
  static const char* value()
  {
    return "da7225c3562dd2b9b88bf15aa7eb6a9e";
  }

  static const char* value(const ::riki_msgs::Battery_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xda7225c3562dd2b9ULL;
  static const uint64_t static_value2 = 0xb88bf15aa7eb6a9eULL;
};

template<class ContainerAllocator>
struct DataType< ::riki_msgs::Battery_<ContainerAllocator> >
{
  static const char* value()
  {
    return "riki_msgs/Battery";
  }

  static const char* value(const ::riki_msgs::Battery_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::riki_msgs::Battery_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 battery\n\
";
  }

  static const char* value(const ::riki_msgs::Battery_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::riki_msgs::Battery_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.battery);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Battery_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::riki_msgs::Battery_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::riki_msgs::Battery_<ContainerAllocator>& v)
  {
    s << indent << "battery: ";
    Printer<float>::stream(s, indent + "  ", v.battery);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RIKI_MSGS_MESSAGE_BATTERY_H
