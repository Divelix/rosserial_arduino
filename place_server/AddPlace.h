#ifndef _ROS_SERVICE_AddPlace_h
#define _ROS_SERVICE_AddPlace_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "place_server/Place.h"

namespace place_server
{

static const char ADDPLACE[] = "place_server/AddPlace";

  class AddPlaceRequest : public ros::Msg
  {
    public:
      typedef place_server::Place _place_type;
      _place_type place;

    AddPlaceRequest():
      place()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->place.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->place.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ADDPLACE; };
    virtual const char * getMD5() override { return "9cb05dd195b618f53909c2f833867f65"; };

  };

  class AddPlaceResponse : public ros::Msg
  {
    public:

    AddPlaceResponse()
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

    virtual const char * getType() override { return ADDPLACE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddPlace {
    public:
    typedef AddPlaceRequest Request;
    typedef AddPlaceResponse Response;
  };

}
#endif
