#ifndef _ROS_SERVICE_AddFiducial_h
#define _ROS_SERVICE_AddFiducial_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fiducial_slam
{

static const char ADDFIDUCIAL[] = "fiducial_slam/AddFiducial";

  class AddFiducialRequest : public ros::Msg
  {
    public:
      typedef int32_t _fiducial_id_type;
      _fiducial_id_type fiducial_id;

    AddFiducialRequest():
      fiducial_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.real = this->fiducial_id;
      *(outbuffer + offset + 0) = (u_fiducial_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fiducial_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fiducial_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fiducial_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fiducial_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.base = 0;
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fiducial_id = u_fiducial_id.real;
      offset += sizeof(this->fiducial_id);
     return offset;
    }

    virtual const char * getType() override { return ADDFIDUCIAL; };
    virtual const char * getMD5() override { return "d6e0c5dec9dcac4f00b77e79be09ed60"; };

  };

  class AddFiducialResponse : public ros::Msg
  {
    public:

    AddFiducialResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return ADDFIDUCIAL; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddFiducial {
    public:
    typedef AddFiducialRequest Request;
    typedef AddFiducialResponse Response;
  };

}
#endif
