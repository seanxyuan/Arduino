#ifndef _ROS_ros_essentials_cpp_Silo_I_h
#define _ROS_ros_essentials_cpp_Silo_I_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class Silo_I : public ros::Msg
  {
    public:
      typedef bool _siloBreaker_type;
      _siloBreaker_type siloBreaker;
      typedef bool _siloDoser_type;
      _siloDoser_type siloDoser;

    Silo_I():
      siloBreaker(0),
      siloDoser(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_siloBreaker;
      u_siloBreaker.real = this->siloBreaker;
      *(outbuffer + offset + 0) = (u_siloBreaker.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloBreaker);
      union {
        bool real;
        uint8_t base;
      } u_siloDoser;
      u_siloDoser.real = this->siloDoser;
      *(outbuffer + offset + 0) = (u_siloDoser.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloDoser);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_siloBreaker;
      u_siloBreaker.base = 0;
      u_siloBreaker.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloBreaker = u_siloBreaker.real;
      offset += sizeof(this->siloBreaker);
      union {
        bool real;
        uint8_t base;
      } u_siloDoser;
      u_siloDoser.base = 0;
      u_siloDoser.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloDoser = u_siloDoser.real;
      offset += sizeof(this->siloDoser);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/Silo_I"; };
    const char * getMD5(){ return "c830830ac61f7f9ea0e60aa9148a432d"; };

  };

}
#endif
