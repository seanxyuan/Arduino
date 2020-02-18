#ifndef _ROS_ros_essentials_cpp_Wetting_I_h
#define _ROS_ros_essentials_cpp_Wetting_I_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class Wetting_I : public ros::Msg
  {
    public:
      typedef bool _breaker_type;
      _breaker_type breaker;
      typedef int8_t _breakerPWM_type;
      _breakerPWM_type breakerPWM;
      typedef bool _doser_type;
      _doser_type doser;
      typedef int8_t _doserSpeed_type;
      _doserSpeed_type doserSpeed;
      typedef bool _agitator_type;
      _agitator_type agitator;
      typedef int8_t _agitatorPWM_type;
      _agitatorPWM_type agitatorPWM;
      typedef bool _water_type;
      _water_type water;
      typedef int8_t _waterSpeed_type;
      _waterSpeed_type waterSpeed;
      typedef bool _mixer_type;
      _mixer_type mixer;
      typedef int8_t _mixerSpeed_type;
      _mixerSpeed_type mixerSpeed;
      typedef bool _reservoir_type;
      _reservoir_type reservoir;
      typedef int8_t _reservoirSpeed_type;
      _reservoirSpeed_type reservoirSpeed;

    Wetting_I():
      breaker(0),
      breakerPWM(0),
      doser(0),
      doserSpeed(0),
      agitator(0),
      agitatorPWM(0),
      water(0),
      waterSpeed(0),
      mixer(0),
      mixerSpeed(0),
      reservoir(0),
      reservoirSpeed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_breaker;
      u_breaker.real = this->breaker;
      *(outbuffer + offset + 0) = (u_breaker.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->breaker);
      union {
        int8_t real;
        uint8_t base;
      } u_breakerPWM;
      u_breakerPWM.real = this->breakerPWM;
      *(outbuffer + offset + 0) = (u_breakerPWM.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->breakerPWM);
      union {
        bool real;
        uint8_t base;
      } u_doser;
      u_doser.real = this->doser;
      *(outbuffer + offset + 0) = (u_doser.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->doser);
      union {
        int8_t real;
        uint8_t base;
      } u_doserSpeed;
      u_doserSpeed.real = this->doserSpeed;
      *(outbuffer + offset + 0) = (u_doserSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->doserSpeed);
      union {
        bool real;
        uint8_t base;
      } u_agitator;
      u_agitator.real = this->agitator;
      *(outbuffer + offset + 0) = (u_agitator.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->agitator);
      union {
        int8_t real;
        uint8_t base;
      } u_agitatorPWM;
      u_agitatorPWM.real = this->agitatorPWM;
      *(outbuffer + offset + 0) = (u_agitatorPWM.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->agitatorPWM);
      union {
        bool real;
        uint8_t base;
      } u_water;
      u_water.real = this->water;
      *(outbuffer + offset + 0) = (u_water.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->water);
      union {
        int8_t real;
        uint8_t base;
      } u_waterSpeed;
      u_waterSpeed.real = this->waterSpeed;
      *(outbuffer + offset + 0) = (u_waterSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->waterSpeed);
      union {
        bool real;
        uint8_t base;
      } u_mixer;
      u_mixer.real = this->mixer;
      *(outbuffer + offset + 0) = (u_mixer.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mixer);
      union {
        int8_t real;
        uint8_t base;
      } u_mixerSpeed;
      u_mixerSpeed.real = this->mixerSpeed;
      *(outbuffer + offset + 0) = (u_mixerSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mixerSpeed);
      union {
        bool real;
        uint8_t base;
      } u_reservoir;
      u_reservoir.real = this->reservoir;
      *(outbuffer + offset + 0) = (u_reservoir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reservoir);
      union {
        int8_t real;
        uint8_t base;
      } u_reservoirSpeed;
      u_reservoirSpeed.real = this->reservoirSpeed;
      *(outbuffer + offset + 0) = (u_reservoirSpeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reservoirSpeed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_breaker;
      u_breaker.base = 0;
      u_breaker.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->breaker = u_breaker.real;
      offset += sizeof(this->breaker);
      union {
        int8_t real;
        uint8_t base;
      } u_breakerPWM;
      u_breakerPWM.base = 0;
      u_breakerPWM.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->breakerPWM = u_breakerPWM.real;
      offset += sizeof(this->breakerPWM);
      union {
        bool real;
        uint8_t base;
      } u_doser;
      u_doser.base = 0;
      u_doser.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->doser = u_doser.real;
      offset += sizeof(this->doser);
      union {
        int8_t real;
        uint8_t base;
      } u_doserSpeed;
      u_doserSpeed.base = 0;
      u_doserSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->doserSpeed = u_doserSpeed.real;
      offset += sizeof(this->doserSpeed);
      union {
        bool real;
        uint8_t base;
      } u_agitator;
      u_agitator.base = 0;
      u_agitator.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->agitator = u_agitator.real;
      offset += sizeof(this->agitator);
      union {
        int8_t real;
        uint8_t base;
      } u_agitatorPWM;
      u_agitatorPWM.base = 0;
      u_agitatorPWM.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->agitatorPWM = u_agitatorPWM.real;
      offset += sizeof(this->agitatorPWM);
      union {
        bool real;
        uint8_t base;
      } u_water;
      u_water.base = 0;
      u_water.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->water = u_water.real;
      offset += sizeof(this->water);
      union {
        int8_t real;
        uint8_t base;
      } u_waterSpeed;
      u_waterSpeed.base = 0;
      u_waterSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->waterSpeed = u_waterSpeed.real;
      offset += sizeof(this->waterSpeed);
      union {
        bool real;
        uint8_t base;
      } u_mixer;
      u_mixer.base = 0;
      u_mixer.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mixer = u_mixer.real;
      offset += sizeof(this->mixer);
      union {
        int8_t real;
        uint8_t base;
      } u_mixerSpeed;
      u_mixerSpeed.base = 0;
      u_mixerSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mixerSpeed = u_mixerSpeed.real;
      offset += sizeof(this->mixerSpeed);
      union {
        bool real;
        uint8_t base;
      } u_reservoir;
      u_reservoir.base = 0;
      u_reservoir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reservoir = u_reservoir.real;
      offset += sizeof(this->reservoir);
      union {
        int8_t real;
        uint8_t base;
      } u_reservoirSpeed;
      u_reservoirSpeed.base = 0;
      u_reservoirSpeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reservoirSpeed = u_reservoirSpeed.real;
      offset += sizeof(this->reservoirSpeed);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/Wetting_I"; };
    const char * getMD5(){ return "994ba9e46f8d4ab5f83461182b5fbeea"; };

  };

}
#endif
