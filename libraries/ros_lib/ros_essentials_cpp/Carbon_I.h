#ifndef _ROS_ros_essentials_cpp_Carbon_I_h
#define _ROS_ros_essentials_cpp_Carbon_I_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class Carbon_I : public ros::Msg
  {
    public:
      typedef int8_t _doserMotorRealSpeed_type;
      _doserMotorRealSpeed_type doserMotorRealSpeed;
      typedef bool _doserMotorStatus_type;
      _doserMotorStatus_type doserMotorStatus;

    Carbon_I():
      doserMotorRealSpeed(0),
      doserMotorStatus(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_doserMotorRealSpeed;
      u_doserMotorRealSpeed.real = this->doserMotorRealSpeed;
      *(outbuffer + offset + 0) = (u_doserMotorRealSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->doserMotorRealSpeed);
      union {
        bool real;
        uint8_t base;
      } u_doserMotorStatus;
      u_doserMotorStatus.real = this->doserMotorStatus;
      *(outbuffer + offset + 0) = (u_doserMotorStatus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->doserMotorStatus);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_doserMotorRealSpeed;
      u_doserMotorRealSpeed.base = 0;
      u_doserMotorRealSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->doserMotorRealSpeed = u_doserMotorRealSpeed.real;
      offset += sizeof(this->doserMotorRealSpeed);
      union {
        bool real;
        uint8_t base;
      } u_doserMotorStatus;
      u_doserMotorStatus.base = 0;
      u_doserMotorStatus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->doserMotorStatus = u_doserMotorStatus.real;
      offset += sizeof(this->doserMotorStatus);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/Carbon_I"; };
    const char * getMD5(){ return "67bfc5bd57e570cee832c7a31e5f6376"; };

  };

}
#endif
