// Generated by gencpp from file riki_lidar_follower/position.msg
// DO NOT EDIT!


#ifndef RIKI_LIDAR_FOLLOWER_MESSAGE_POSITION_H
#define RIKI_LIDAR_FOLLOWER_MESSAGE_POSITION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace riki_lidar_follower
{
template <class ContainerAllocator>
struct position_
{
  typedef position_<ContainerAllocator> Type;

  position_()
    : angleX(0.0)
    , angleY(0.0)
    , distance(0.0)  {
    }
  position_(const ContainerAllocator& _alloc)
    : angleX(0.0)
    , angleY(0.0)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef float _angleX_type;
  _angleX_type angleX;

   typedef float _angleY_type;
  _angleY_type angleY;

   typedef float _distance_type;
  _distance_type distance;




  typedef boost::shared_ptr< ::riki_lidar_follower::position_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::riki_lidar_follower::position_<ContainerAllocator> const> ConstPtr;

}; // struct position_

typedef ::riki_lidar_follower::position_<std::allocator<void> > position;

typedef boost::shared_ptr< ::riki_lidar_follower::position > positionPtr;
typedef boost::shared_ptr< ::riki_lidar_follower::position const> positionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::riki_lidar_follower::position_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::riki_lidar_follower::position_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace riki_lidar_follower

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'riki_lidar_follower': ['/home/riki/catkin_ws/src/rikirobot_project/riki_lidar_follower/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::riki_lidar_follower::position_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::riki_lidar_follower::position_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::riki_lidar_follower::position_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::riki_lidar_follower::position_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::riki_lidar_follower::position_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::riki_lidar_follower::position_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::riki_lidar_follower::position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e4df5e09e92d9d2b4758c9aab7a9ebeb";
  }

  static const char* value(const ::riki_lidar_follower::position_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe4df5e09e92d9d2bULL;
  static const uint64_t static_value2 = 0x4758c9aab7a9ebebULL;
};

template<class ContainerAllocator>
struct DataType< ::riki_lidar_follower::position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "riki_lidar_follower/position";
  }

  static const char* value(const ::riki_lidar_follower::position_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::riki_lidar_follower::position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 angleX\n\
float32 angleY\n\
float32 distance\n\
";
  }

  static const char* value(const ::riki_lidar_follower::position_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::riki_lidar_follower::position_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.angleX);
      stream.next(m.angleY);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct position_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::riki_lidar_follower::position_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::riki_lidar_follower::position_<ContainerAllocator>& v)
  {
    s << indent << "angleX: ";
    Printer<float>::stream(s, indent + "  ", v.angleX);
    s << indent << "angleY: ";
    Printer<float>::stream(s, indent + "  ", v.angleY);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RIKI_LIDAR_FOLLOWER_MESSAGE_POSITION_H
