#ifndef _ROS_nautilos_general_PersonInfo_h
#define _ROS_nautilos_general_PersonInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nautilos_general
{

  class PersonInfo : public ros::Msg
  {
    public:
      typedef const char* _first_name_type;
      _first_name_type first_name;
      typedef const char* _second_name_type;
      _second_name_type second_name;

    PersonInfo():
      first_name(""),
      second_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_first_name = strlen(this->first_name);
      varToArr(outbuffer + offset, length_first_name);
      offset += 4;
      memcpy(outbuffer + offset, this->first_name, length_first_name);
      offset += length_first_name;
      uint32_t length_second_name = strlen(this->second_name);
      varToArr(outbuffer + offset, length_second_name);
      offset += 4;
      memcpy(outbuffer + offset, this->second_name, length_second_name);
      offset += length_second_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_first_name;
      arrToVar(length_first_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_first_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_first_name-1]=0;
      this->first_name = (char *)(inbuffer + offset-1);
      offset += length_first_name;
      uint32_t length_second_name;
      arrToVar(length_second_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_second_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_second_name-1]=0;
      this->second_name = (char *)(inbuffer + offset-1);
      offset += length_second_name;
     return offset;
    }

    virtual const char * getType() override { return "nautilos_general/PersonInfo"; };
    virtual const char * getMD5() override { return "791db522555c41acfa43b679d4cb29a4"; };

  };

}
#endif
