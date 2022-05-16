#ifndef _ROS_SERVICE_MoveToPlace_h
#define _ROS_SERVICE_MoveToPlace_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace place_server
{

static const char MOVETOPLACE[] = "place_server/MoveToPlace";

  class MoveToPlaceRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;

    MoveToPlaceRequest():
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    virtual const char * getType() override { return MOVETOPLACE; };
    virtual const char * getMD5() override { return "c1f3d28f1b044c871e6eff2e9fc3c667"; };

  };

  class MoveToPlaceResponse : public ros::Msg
  {
    public:

    MoveToPlaceResponse()
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

    virtual const char * getType() override { return MOVETOPLACE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class MoveToPlace {
    public:
    typedef MoveToPlaceRequest Request;
    typedef MoveToPlaceResponse Response;
  };

}
#endif
