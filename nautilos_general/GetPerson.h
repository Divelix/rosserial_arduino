#ifndef _ROS_SERVICE_GetPerson_h
#define _ROS_SERVICE_GetPerson_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nautilos_general/Person.h"

namespace nautilos_general
{

static const char GETPERSON[] = "nautilos_general/GetPerson";

  class GetPersonRequest : public ros::Msg
  {
    public:
      typedef const char* _person_id_type;
      _person_id_type person_id;

    GetPersonRequest():
      person_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_person_id = strlen(this->person_id);
      varToArr(outbuffer + offset, length_person_id);
      offset += 4;
      memcpy(outbuffer + offset, this->person_id, length_person_id);
      offset += length_person_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_person_id;
      arrToVar(length_person_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_person_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_person_id-1]=0;
      this->person_id = (char *)(inbuffer + offset-1);
      offset += length_person_id;
     return offset;
    }

    virtual const char * getType() override { return GETPERSON; };
    virtual const char * getMD5() override { return "1b0179d1c2d646b3a6474f7a14b08c62"; };

  };

  class GetPersonResponse : public ros::Msg
  {
    public:
      typedef nautilos_general::Person _person_type;
      _person_type person;

    GetPersonResponse():
      person()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->person.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->person.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPERSON; };
    virtual const char * getMD5() override { return "23ed806c1626bc1f721eed6b242492ce"; };

  };

  class GetPerson {
    public:
    typedef GetPersonRequest Request;
    typedef GetPersonResponse Response;
  };

}
#endif
