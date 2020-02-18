#ifndef _ROS_ros_essentials_cpp_Cart_O_h
#define _ROS_ros_essentials_cpp_Cart_O_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class Cart_O : public ros::Msg
  {
    public:
      typedef int8_t _freshConcreteLevel_type;
      _freshConcreteLevel_type freshConcreteLevel;
      typedef bool _rotaryError_type;
      _rotaryError_type rotaryError;
      typedef bool _upDownError_type;
      _upDownError_type upDownError;

    Cart_O():
      freshConcreteLevel(0),
      rotaryError(0),
      upDownError(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_freshConcreteLevel;
      u_freshConcreteLevel.real = this->freshConcreteLevel;
      *(outbuffer + offset + 0) = (u_freshConcreteLevel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->freshConcreteLevel);
      union {
        bool real;
        uint8_t base;
      } u_rotaryError;
      u_rotaryError.real = this->rotaryError;
      *(outbuffer + offset + 0) = (u_rotaryError.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rotaryError);
      union {
        bool real;
        uint8_t base;
      } u_upDownError;
      u_upDownError.real = this->upDownError;
      *(outbuffer + offset + 0) = (u_upDownError.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->upDownError);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_freshConcreteLevel;
      u_freshConcreteLevel.base = 0;
      u_freshConcreteLevel.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->freshConcreteLevel = u_freshConcreteLevel.real;
      offset += sizeof(this->freshConcreteLevel);
      union {
        bool real;
        uint8_t base;
      } u_rotaryError;
      u_rotaryError.base = 0;
      u_rotaryError.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rotaryError = u_rotaryError.real;
      offset += sizeof(this->rotaryError);
      union {
        bool real;
        uint8_t base;
      } u_upDownError;
      u_upDownError.base = 0;
      u_upDownError.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->upDownError = u_upDownError.real;
      offset += sizeof(this->upDownError);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/Cart_O"; };
    const char * getMD5(){ return "ce610b23c5e92af396a4558395a1815b"; };

  };

}
#endif
