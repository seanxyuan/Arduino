#ifndef _ROS_ros_essentials_cpp_Silo_O_h
#define _ROS_ros_essentials_cpp_Silo_O_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class Silo_O : public ros::Msg
  {
    public:
      typedef bool _siloSensor1_type;
      _siloSensor1_type siloSensor1;
      typedef bool _siloSensor2_type;
      _siloSensor2_type siloSensor2;

    Silo_O():
      siloSensor1(0),
      siloSensor2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_siloSensor1;
      u_siloSensor1.real = this->siloSensor1;
      *(outbuffer + offset + 0) = (u_siloSensor1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloSensor1);
      union {
        bool real;
        uint8_t base;
      } u_siloSensor2;
      u_siloSensor2.real = this->siloSensor2;
      *(outbuffer + offset + 0) = (u_siloSensor2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloSensor2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_siloSensor1;
      u_siloSensor1.base = 0;
      u_siloSensor1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloSensor1 = u_siloSensor1.real;
      offset += sizeof(this->siloSensor1);
      union {
        bool real;
        uint8_t base;
      } u_siloSensor2;
      u_siloSensor2.base = 0;
      u_siloSensor2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloSensor2 = u_siloSensor2.real;
      offset += sizeof(this->siloSensor2);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/Silo_O"; };
    const char * getMD5(){ return "e103f2520684ffa397e7eed84fbbd529"; };

  };

}
#endif
