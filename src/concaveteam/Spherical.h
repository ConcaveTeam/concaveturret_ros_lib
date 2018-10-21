#ifndef _ROS_concaveteam_Spherical_h
#define _ROS_concaveteam_Spherical_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concaveteam
{

  class Spherical : public ros::Msg
  {
    public:
      typedef int16_t _polar_type;
      _polar_type polar;
      typedef int16_t _azimuth_type;
      _azimuth_type azimuth;

    Spherical():
      polar(0),
      azimuth(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_polar;
      u_polar.real = this->polar;
      *(outbuffer + offset + 0) = (u_polar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_polar.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->polar);
      union {
        int16_t real;
        uint16_t base;
      } u_azimuth;
      u_azimuth.real = this->azimuth;
      *(outbuffer + offset + 0) = (u_azimuth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_azimuth.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->azimuth);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_polar;
      u_polar.base = 0;
      u_polar.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_polar.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->polar = u_polar.real;
      offset += sizeof(this->polar);
      union {
        int16_t real;
        uint16_t base;
      } u_azimuth;
      u_azimuth.base = 0;
      u_azimuth.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_azimuth.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->azimuth = u_azimuth.real;
      offset += sizeof(this->azimuth);
     return offset;
    }

    const char * getType(){ return "concaveteam/Spherical"; };
    const char * getMD5(){ return "8946f0f9ae8db407d471d7845d52df9c"; };

  };

}
#endif
