#ifndef _ROS_place_server_PlaceStamped_h
#define _ROS_place_server_PlaceStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "place_server/Place.h"

namespace place_server
{

  class PlaceStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef place_server::Place _place_type;
      _place_type place;

    PlaceStamped():
      header(),
      place()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->place.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->place.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "place_server/PlaceStamped"; };
    virtual const char * getMD5() override { return "0a318c471cd54e6b9107edbf409446b6"; };

  };

}
#endif
