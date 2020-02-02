// Generated by gencpp from file riki_msgs/Infrared.msg
// DO NOT EDIT!


#ifndef RIKI_MSGS_MESSAGE_INFRARED_H
#define RIKI_MSGS_MESSAGE_INFRARED_H


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
struct Infrared_
{
  typedef Infrared_<ContainerAllocator> Type;

  Infrared_()
    : front(0.0)
    , rear(0.0)  {
    }
  Infrared_(const ContainerAllocator& _alloc)
    : front(0.0)
    , rear(0.0)  {
  (void)_alloc;
    }



   typedef float _front_type;
  _front_type front;

   typedef float _rear_type;
  _rear_type rear;




  typedef boost::shared_ptr< ::riki_msgs::Infrared_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::riki_msgs::Infrared_<ContainerAllocator> const> ConstPtr;

}; // struct Infrared_

typedef ::riki_msgs::Infrared_<std::allocator<void> > Infrared;

typedef boost::shared_ptr< ::riki_msgs::Infrared > InfraredPtr;
typedef boost::shared_ptr< ::riki_msgs::Infrared const> InfraredConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::riki_msgs::Infrared_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::riki_msgs::Infrared_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::riki_msgs::Infrared_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::riki_msgs::Infrared_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::riki_msgs::Infrared_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::riki_msgs::Infrared_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::riki_msgs::Infrared_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::riki_msgs::Infrared_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::riki_msgs::Infrared_<ContainerAllocator> >
{
  static const char* value()
  {
    return "25f4ca8647150542dc24ea09b80ff4f1";
  }

  static const char* value(const ::riki_msgs::Infrared_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x25f4ca8647150542ULL;
  static const uint64_t static_value2 = 0xdc24ea09b80ff4f1ULL;
};

template<class ContainerAllocator>
struct DataType< ::riki_msgs::Infrared_<ContainerAllocator> >
{
  static const char* value()
  {
    return "riki_msgs/Infrared";
  }

  static const char* value(const ::riki_msgs::Infrared_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::riki_msgs::Infrared_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 front\n\
float32 rear\n\
\n\
";
  }

  static const char* value(const ::riki_msgs::Infrared_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::riki_msgs::Infrared_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.front);
      stream.next(m.rear);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Infrared_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::riki_msgs::Infrared_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::riki_msgs::Infrared_<ContainerAllocator>& v)
  {
    s << indent << "front: ";
    Printer<float>::stream(s, indent + "  ", v.front);
    s << indent << "rear: ";
    Printer<float>::stream(s, indent + "  ", v.rear);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RIKI_MSGS_MESSAGE_INFRARED_H
