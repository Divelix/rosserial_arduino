#ifndef _ROS_nautilos_general_Person_h
#define _ROS_nautilos_general_Person_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nautilos_general/PersonInfo.h"
#include "sensor_msgs/Image.h"

namespace nautilos_general
{

  class Person : public ros::Msg
  {
    public:
      typedef nautilos_general::PersonInfo _info_type;
      _info_type info;
      typedef sensor_msgs::Image _photo_type;
      _photo_type photo;

    Person():
      info(),
      photo()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
      offset += this->photo.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
      offset += this->photo.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "nautilos_general/Person"; };
    virtual const char * getMD5() override { return "dc7f2d6969521774358f6aeaab9aaa04"; };

  };

}
#endif
