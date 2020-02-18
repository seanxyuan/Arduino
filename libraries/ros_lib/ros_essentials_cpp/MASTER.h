#ifndef _ROS_ros_essentials_cpp_MASTER_h
#define _ROS_ros_essentials_cpp_MASTER_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class MASTER : public ros::Msg
  {
    public:
      typedef bool _eStop_type;
      _eStop_type eStop;
      typedef bool _siloOn_type;
      _siloOn_type siloOn;
      typedef bool _siloAllOn_type;
      _siloAllOn_type siloAllOn;
      typedef bool _wetOn_type;
      _wetOn_type wetOn;
      typedef bool _wetAllOn_type;
      _wetAllOn_type wetAllOn;
      typedef bool _deliveryOn_type;
      _deliveryOn_type deliveryOn;
      typedef bool _deliveryAllOn_type;
      _deliveryAllOn_type deliveryAllOn;
      typedef bool _cartOn_type;
      _cartOn_type cartOn;
      typedef bool _cartAllOn_type;
      _cartAllOn_type cartAllOn;
      typedef bool _carbonOn_type;
      _carbonOn_type carbonOn;
      typedef bool _carbonAllOn_type;
      _carbonAllOn_type carbonAllOn;

    MASTER():
      eStop(0),
      siloOn(0),
      siloAllOn(0),
      wetOn(0),
      wetAllOn(0),
      deliveryOn(0),
      deliveryAllOn(0),
      cartOn(0),
      cartAllOn(0),
      carbonOn(0),
      carbonAllOn(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_eStop;
      u_eStop.real = this->eStop;
      *(outbuffer + offset + 0) = (u_eStop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eStop);
      union {
        bool real;
        uint8_t base;
      } u_siloOn;
      u_siloOn.real = this->siloOn;
      *(outbuffer + offset + 0) = (u_siloOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloOn);
      union {
        bool real;
        uint8_t base;
      } u_siloAllOn;
      u_siloAllOn.real = this->siloAllOn;
      *(outbuffer + offset + 0) = (u_siloAllOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloAllOn);
      union {
        bool real;
        uint8_t base;
      } u_wetOn;
      u_wetOn.real = this->wetOn;
      *(outbuffer + offset + 0) = (u_wetOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wetOn);
      union {
        bool real;
        uint8_t base;
      } u_wetAllOn;
      u_wetAllOn.real = this->wetAllOn;
      *(outbuffer + offset + 0) = (u_wetAllOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wetAllOn);
      union {
        bool real;
        uint8_t base;
      } u_deliveryOn;
      u_deliveryOn.real = this->deliveryOn;
      *(outbuffer + offset + 0) = (u_deliveryOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deliveryOn);
      union {
        bool real;
        uint8_t base;
      } u_deliveryAllOn;
      u_deliveryAllOn.real = this->deliveryAllOn;
      *(outbuffer + offset + 0) = (u_deliveryAllOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deliveryAllOn);
      union {
        bool real;
        uint8_t base;
      } u_cartOn;
      u_cartOn.real = this->cartOn;
      *(outbuffer + offset + 0) = (u_cartOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cartOn);
      union {
        bool real;
        uint8_t base;
      } u_cartAllOn;
      u_cartAllOn.real = this->cartAllOn;
      *(outbuffer + offset + 0) = (u_cartAllOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cartAllOn);
      union {
        bool real;
        uint8_t base;
      } u_carbonOn;
      u_carbonOn.real = this->carbonOn;
      *(outbuffer + offset + 0) = (u_carbonOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->carbonOn);
      union {
        bool real;
        uint8_t base;
      } u_carbonAllOn;
      u_carbonAllOn.real = this->carbonAllOn;
      *(outbuffer + offset + 0) = (u_carbonAllOn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->carbonAllOn);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_eStop;
      u_eStop.base = 0;
      u_eStop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->eStop = u_eStop.real;
      offset += sizeof(this->eStop);
      union {
        bool real;
        uint8_t base;
      } u_siloOn;
      u_siloOn.base = 0;
      u_siloOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloOn = u_siloOn.real;
      offset += sizeof(this->siloOn);
      union {
        bool real;
        uint8_t base;
      } u_siloAllOn;
      u_siloAllOn.base = 0;
      u_siloAllOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloAllOn = u_siloAllOn.real;
      offset += sizeof(this->siloAllOn);
      union {
        bool real;
        uint8_t base;
      } u_wetOn;
      u_wetOn.base = 0;
      u_wetOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wetOn = u_wetOn.real;
      offset += sizeof(this->wetOn);
      union {
        bool real;
        uint8_t base;
      } u_wetAllOn;
      u_wetAllOn.base = 0;
      u_wetAllOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wetAllOn = u_wetAllOn.real;
      offset += sizeof(this->wetAllOn);
      union {
        bool real;
        uint8_t base;
      } u_deliveryOn;
      u_deliveryOn.base = 0;
      u_deliveryOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->deliveryOn = u_deliveryOn.real;
      offset += sizeof(this->deliveryOn);
      union {
        bool real;
        uint8_t base;
      } u_deliveryAllOn;
      u_deliveryAllOn.base = 0;
      u_deliveryAllOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->deliveryAllOn = u_deliveryAllOn.real;
      offset += sizeof(this->deliveryAllOn);
      union {
        bool real;
        uint8_t base;
      } u_cartOn;
      u_cartOn.base = 0;
      u_cartOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cartOn = u_cartOn.real;
      offset += sizeof(this->cartOn);
      union {
        bool real;
        uint8_t base;
      } u_cartAllOn;
      u_cartAllOn.base = 0;
      u_cartAllOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cartAllOn = u_cartAllOn.real;
      offset += sizeof(this->cartAllOn);
      union {
        bool real;
        uint8_t base;
      } u_carbonOn;
      u_carbonOn.base = 0;
      u_carbonOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->carbonOn = u_carbonOn.real;
      offset += sizeof(this->carbonOn);
      union {
        bool real;
        uint8_t base;
      } u_carbonAllOn;
      u_carbonAllOn.base = 0;
      u_carbonAllOn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->carbonAllOn = u_carbonAllOn.real;
      offset += sizeof(this->carbonAllOn);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/MASTER"; };
    const char * getMD5(){ return "781ecf7e7e5c21871e9fcdfbde9ac340"; };

  };

}
#endif
