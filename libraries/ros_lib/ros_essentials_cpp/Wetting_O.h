#ifndef _ROS_ros_essentials_cpp_Wetting_O_h
#define _ROS_ros_essentials_cpp_Wetting_O_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class Wetting_O : public ros::Msg
  {
    public:
      typedef bool _levelBreaker_type;
      _levelBreaker_type levelBreaker;
      typedef int8_t _breakerCurrent_type;
      _breakerCurrent_type breakerCurrent;
      typedef int8_t _doserRSpeed_type;
      _doserRSpeed_type doserRSpeed;
      typedef int8_t _doserCurrent_type;
      _doserCurrent_type doserCurrent;
      typedef int8_t _agitatorCurrent_type;
      _agitatorCurrent_type agitatorCurrent;
      typedef int8_t _waterRSpeed_type;
      _waterRSpeed_type waterRSpeed;
      typedef int8_t _mixerRSpeed_type;
      _mixerRSpeed_type mixerRSpeed;
      typedef bool _levelReservoir_type;
      _levelReservoir_type levelReservoir;

    Wetting_O():
      levelBreaker(0),
      breakerCurrent(0),
      doserRSpeed(0),
      doserCurrent(0),
      agitatorCurrent(0),
      waterRSpeed(0),
      mixerRSpeed(0),
      levelReservoir(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_levelBreaker;
      u_levelBreaker.real = this->levelBreaker;
      *(outbuffer + offset + 0) = (u_levelBreaker.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->levelBreaker);
      union {
        int8_t real;
        uint8_t base;
      } u_breakerCurrent;
      u_breakerCurrent.real = this->breakerCurrent;
      *(outbuffer + offset + 0) = (u_breakerCurrent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->breakerCurrent);
      union {
        int8_t real;
        uint8_t base;
      } u_doserRSpeed;
      u_doserRSpeed.real = this->doserRSpeed;
      *(outbuffer + offset + 0) = (u_doserRSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->doserRSpeed);
      union {
        int8_t real;
        uint8_t base;
      } u_doserCurrent;
      u_doserCurrent.real = this->doserCurrent;
      *(outbuffer + offset + 0) = (u_doserCurrent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->doserCurrent);
      union {
        int8_t real;
        uint8_t base;
      } u_agitatorCurrent;
      u_agitatorCurrent.real = this->agitatorCurrent;
      *(outbuffer + offset + 0) = (u_agitatorCurrent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->agitatorCurrent);
      union {
        int8_t real;
        uint8_t base;
      } u_waterRSpeed;
      u_waterRSpeed.real = this->waterRSpeed;
      *(outbuffer + offset + 0) = (u_waterRSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->waterRSpeed);
      union {
        int8_t real;
        uint8_t base;
      } u_mixerRSpeed;
      u_mixerRSpeed.real = this->mixerRSpeed;
      *(outbuffer + offset + 0) = (u_mixerRSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mixerRSpeed);
      union {
        bool real;
        uint8_t base;
      } u_levelReservoir;
      u_levelReservoir.real = this->levelReservoir;
      *(outbuffer + offset + 0) = (u_levelReservoir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->levelReservoir);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_levelBreaker;
      u_levelBreaker.base = 0;
      u_levelBreaker.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->levelBreaker = u_levelBreaker.real;
      offset += sizeof(this->levelBreaker);
      union {
        int8_t real;
        uint8_t base;
      } u_breakerCurrent;
      u_breakerCurrent.base = 0;
      u_breakerCurrent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->breakerCurrent = u_breakerCurrent.real;
      offset += sizeof(this->breakerCurrent);
      union {
        int8_t real;
        uint8_t base;
      } u_doserRSpeed;
      u_doserRSpeed.base = 0;
      u_doserRSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->doserRSpeed = u_doserRSpeed.real;
      offset += sizeof(this->doserRSpeed);
      union {
        int8_t real;
        uint8_t base;
      } u_doserCurrent;
      u_doserCurrent.base = 0;
      u_doserCurrent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->doserCurrent = u_doserCurrent.real;
      offset += sizeof(this->doserCurrent);
      union {
        int8_t real;
        uint8_t base;
      } u_agitatorCurrent;
      u_agitatorCurrent.base = 0;
      u_agitatorCurrent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->agitatorCurrent = u_agitatorCurrent.real;
      offset += sizeof(this->agitatorCurrent);
      union {
        int8_t real;
        uint8_t base;
      } u_waterRSpeed;
      u_waterRSpeed.base = 0;
      u_waterRSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->waterRSpeed = u_waterRSpeed.real;
      offset += sizeof(this->waterRSpeed);
      union {
        int8_t real;
        uint8_t base;
      } u_mixerRSpeed;
      u_mixerRSpeed.base = 0;
      u_mixerRSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mixerRSpeed = u_mixerRSpeed.real;
      offset += sizeof(this->mixerRSpeed);
      union {
        bool real;
        uint8_t base;
      } u_levelReservoir;
      u_levelReservoir.base = 0;
      u_levelReservoir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->levelReservoir = u_levelReservoir.real;
      offset += sizeof(this->levelReservoir);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/Wetting_O"; };
    const char * getMD5(){ return "0974af3e779c43ff67110157bb740dc4"; };

  };

}
#endif
