#ifndef _ROS_ros_essentials_cpp_Delivery_I_h
#define _ROS_ros_essentials_cpp_Delivery_I_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class Delivery_I : public ros::Msg
  {
    public:
      typedef bool _siloInputDoor_type;
      _siloInputDoor_type siloInputDoor;
      typedef int8_t _siloConcreteLevel1_type;
      _siloConcreteLevel1_type siloConcreteLevel1;
      typedef int8_t _siloConcreteLevel2_type;
      _siloConcreteLevel2_type siloConcreteLevel2;
      typedef bool _siloBreaker_type;
      _siloBreaker_type siloBreaker;
      typedef bool _siloDoser_type;
      _siloDoser_type siloDoser;
      typedef bool _siloHopperLevel_type;
      _siloHopperLevel_type siloHopperLevel;
      typedef bool _siloTrasmit_type;
      _siloTrasmit_type siloTrasmit;
      typedef int8_t _towerLifting_type;
      _towerLifting_type towerLifting;
      typedef bool _towerLiftError_type;
      _towerLiftError_type towerLiftError;
      typedef bool _towerFunnelBreaker_type;
      _towerFunnelBreaker_type towerFunnelBreaker;
      typedef bool _towerFunnelBreakerError_type;
      _towerFunnelBreakerError_type towerFunnelBreakerError;
      typedef bool _towerAugerMotor1_type;
      _towerAugerMotor1_type towerAugerMotor1;
      typedef int8_t _towerAugerMotor1Speed_type;
      _towerAugerMotor1Speed_type towerAugerMotor1Speed;
      typedef int8_t _towerAugerMotor1Current_type;
      _towerAugerMotor1Current_type towerAugerMotor1Current;
      typedef int8_t _towerAugerMotor1Torque_type;
      _towerAugerMotor1Torque_type towerAugerMotor1Torque;
      typedef bool _towerAugerMotor2_type;
      _towerAugerMotor2_type towerAugerMotor2;
      typedef int8_t _towerAugerMotor2Speed_type;
      _towerAugerMotor2Speed_type towerAugerMotor2Speed;
      typedef int8_t _towerAugerMotor2Current_type;
      _towerAugerMotor2Current_type towerAugerMotor2Current;
      typedef int8_t _towerAugerMotor2Torque_type;
      _towerAugerMotor2Torque_type towerAugerMotor2Torque;

    Delivery_I():
      siloInputDoor(0),
      siloConcreteLevel1(0),
      siloConcreteLevel2(0),
      siloBreaker(0),
      siloDoser(0),
      siloHopperLevel(0),
      siloTrasmit(0),
      towerLifting(0),
      towerLiftError(0),
      towerFunnelBreaker(0),
      towerFunnelBreakerError(0),
      towerAugerMotor1(0),
      towerAugerMotor1Speed(0),
      towerAugerMotor1Current(0),
      towerAugerMotor1Torque(0),
      towerAugerMotor2(0),
      towerAugerMotor2Speed(0),
      towerAugerMotor2Current(0),
      towerAugerMotor2Torque(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_siloInputDoor;
      u_siloInputDoor.real = this->siloInputDoor;
      *(outbuffer + offset + 0) = (u_siloInputDoor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloInputDoor);
      union {
        int8_t real;
        uint8_t base;
      } u_siloConcreteLevel1;
      u_siloConcreteLevel1.real = this->siloConcreteLevel1;
      *(outbuffer + offset + 0) = (u_siloConcreteLevel1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloConcreteLevel1);
      union {
        int8_t real;
        uint8_t base;
      } u_siloConcreteLevel2;
      u_siloConcreteLevel2.real = this->siloConcreteLevel2;
      *(outbuffer + offset + 0) = (u_siloConcreteLevel2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloConcreteLevel2);
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
      union {
        bool real;
        uint8_t base;
      } u_siloHopperLevel;
      u_siloHopperLevel.real = this->siloHopperLevel;
      *(outbuffer + offset + 0) = (u_siloHopperLevel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloHopperLevel);
      union {
        bool real;
        uint8_t base;
      } u_siloTrasmit;
      u_siloTrasmit.real = this->siloTrasmit;
      *(outbuffer + offset + 0) = (u_siloTrasmit.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->siloTrasmit);
      union {
        int8_t real;
        uint8_t base;
      } u_towerLifting;
      u_towerLifting.real = this->towerLifting;
      *(outbuffer + offset + 0) = (u_towerLifting.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerLifting);
      union {
        bool real;
        uint8_t base;
      } u_towerLiftError;
      u_towerLiftError.real = this->towerLiftError;
      *(outbuffer + offset + 0) = (u_towerLiftError.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerLiftError);
      union {
        bool real;
        uint8_t base;
      } u_towerFunnelBreaker;
      u_towerFunnelBreaker.real = this->towerFunnelBreaker;
      *(outbuffer + offset + 0) = (u_towerFunnelBreaker.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerFunnelBreaker);
      union {
        bool real;
        uint8_t base;
      } u_towerFunnelBreakerError;
      u_towerFunnelBreakerError.real = this->towerFunnelBreakerError;
      *(outbuffer + offset + 0) = (u_towerFunnelBreakerError.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerFunnelBreakerError);
      union {
        bool real;
        uint8_t base;
      } u_towerAugerMotor1;
      u_towerAugerMotor1.real = this->towerAugerMotor1;
      *(outbuffer + offset + 0) = (u_towerAugerMotor1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor1);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor1Speed;
      u_towerAugerMotor1Speed.real = this->towerAugerMotor1Speed;
      *(outbuffer + offset + 0) = (u_towerAugerMotor1Speed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor1Speed);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor1Current;
      u_towerAugerMotor1Current.real = this->towerAugerMotor1Current;
      *(outbuffer + offset + 0) = (u_towerAugerMotor1Current.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor1Current);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor1Torque;
      u_towerAugerMotor1Torque.real = this->towerAugerMotor1Torque;
      *(outbuffer + offset + 0) = (u_towerAugerMotor1Torque.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor1Torque);
      union {
        bool real;
        uint8_t base;
      } u_towerAugerMotor2;
      u_towerAugerMotor2.real = this->towerAugerMotor2;
      *(outbuffer + offset + 0) = (u_towerAugerMotor2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor2);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor2Speed;
      u_towerAugerMotor2Speed.real = this->towerAugerMotor2Speed;
      *(outbuffer + offset + 0) = (u_towerAugerMotor2Speed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor2Speed);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor2Current;
      u_towerAugerMotor2Current.real = this->towerAugerMotor2Current;
      *(outbuffer + offset + 0) = (u_towerAugerMotor2Current.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor2Current);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor2Torque;
      u_towerAugerMotor2Torque.real = this->towerAugerMotor2Torque;
      *(outbuffer + offset + 0) = (u_towerAugerMotor2Torque.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->towerAugerMotor2Torque);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_siloInputDoor;
      u_siloInputDoor.base = 0;
      u_siloInputDoor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloInputDoor = u_siloInputDoor.real;
      offset += sizeof(this->siloInputDoor);
      union {
        int8_t real;
        uint8_t base;
      } u_siloConcreteLevel1;
      u_siloConcreteLevel1.base = 0;
      u_siloConcreteLevel1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloConcreteLevel1 = u_siloConcreteLevel1.real;
      offset += sizeof(this->siloConcreteLevel1);
      union {
        int8_t real;
        uint8_t base;
      } u_siloConcreteLevel2;
      u_siloConcreteLevel2.base = 0;
      u_siloConcreteLevel2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloConcreteLevel2 = u_siloConcreteLevel2.real;
      offset += sizeof(this->siloConcreteLevel2);
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
      union {
        bool real;
        uint8_t base;
      } u_siloHopperLevel;
      u_siloHopperLevel.base = 0;
      u_siloHopperLevel.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloHopperLevel = u_siloHopperLevel.real;
      offset += sizeof(this->siloHopperLevel);
      union {
        bool real;
        uint8_t base;
      } u_siloTrasmit;
      u_siloTrasmit.base = 0;
      u_siloTrasmit.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->siloTrasmit = u_siloTrasmit.real;
      offset += sizeof(this->siloTrasmit);
      union {
        int8_t real;
        uint8_t base;
      } u_towerLifting;
      u_towerLifting.base = 0;
      u_towerLifting.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerLifting = u_towerLifting.real;
      offset += sizeof(this->towerLifting);
      union {
        bool real;
        uint8_t base;
      } u_towerLiftError;
      u_towerLiftError.base = 0;
      u_towerLiftError.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerLiftError = u_towerLiftError.real;
      offset += sizeof(this->towerLiftError);
      union {
        bool real;
        uint8_t base;
      } u_towerFunnelBreaker;
      u_towerFunnelBreaker.base = 0;
      u_towerFunnelBreaker.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerFunnelBreaker = u_towerFunnelBreaker.real;
      offset += sizeof(this->towerFunnelBreaker);
      union {
        bool real;
        uint8_t base;
      } u_towerFunnelBreakerError;
      u_towerFunnelBreakerError.base = 0;
      u_towerFunnelBreakerError.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerFunnelBreakerError = u_towerFunnelBreakerError.real;
      offset += sizeof(this->towerFunnelBreakerError);
      union {
        bool real;
        uint8_t base;
      } u_towerAugerMotor1;
      u_towerAugerMotor1.base = 0;
      u_towerAugerMotor1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor1 = u_towerAugerMotor1.real;
      offset += sizeof(this->towerAugerMotor1);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor1Speed;
      u_towerAugerMotor1Speed.base = 0;
      u_towerAugerMotor1Speed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor1Speed = u_towerAugerMotor1Speed.real;
      offset += sizeof(this->towerAugerMotor1Speed);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor1Current;
      u_towerAugerMotor1Current.base = 0;
      u_towerAugerMotor1Current.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor1Current = u_towerAugerMotor1Current.real;
      offset += sizeof(this->towerAugerMotor1Current);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor1Torque;
      u_towerAugerMotor1Torque.base = 0;
      u_towerAugerMotor1Torque.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor1Torque = u_towerAugerMotor1Torque.real;
      offset += sizeof(this->towerAugerMotor1Torque);
      union {
        bool real;
        uint8_t base;
      } u_towerAugerMotor2;
      u_towerAugerMotor2.base = 0;
      u_towerAugerMotor2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor2 = u_towerAugerMotor2.real;
      offset += sizeof(this->towerAugerMotor2);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor2Speed;
      u_towerAugerMotor2Speed.base = 0;
      u_towerAugerMotor2Speed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor2Speed = u_towerAugerMotor2Speed.real;
      offset += sizeof(this->towerAugerMotor2Speed);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor2Current;
      u_towerAugerMotor2Current.base = 0;
      u_towerAugerMotor2Current.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor2Current = u_towerAugerMotor2Current.real;
      offset += sizeof(this->towerAugerMotor2Current);
      union {
        int8_t real;
        uint8_t base;
      } u_towerAugerMotor2Torque;
      u_towerAugerMotor2Torque.base = 0;
      u_towerAugerMotor2Torque.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->towerAugerMotor2Torque = u_towerAugerMotor2Torque.real;
      offset += sizeof(this->towerAugerMotor2Torque);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/Delivery_I"; };
    const char * getMD5(){ return "7a84d7280a0d3509a502794110897fa1"; };

  };

}
#endif
