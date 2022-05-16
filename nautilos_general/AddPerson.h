#ifndef _ROS_SERVICE_AddPerson_h
#define _ROS_SERVICE_AddPerson_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nautilos_general/Person.h"

namespace nautilos_general
{

static const char ADDPERSON[] = "nautilos_general/AddPerson";

  class AddPersonRequest : public ros::Msg
  {
    public:
      typedef nautilos_general::Person _person_type;
      _person_type person;

    AddPersonRequest():
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

    virtual const char * getType() override { return ADDPERSON; };
    virtual const char * getMD5() override { return "23ed806c1626bc1f721eed6b242492ce"; };

  };

  class AddPersonResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_message_type;
      _status_message_type status_message;
      typedef const char* _person_id_type;
      _person_id_type person_id;

    AddPersonResponse():
      success(0),
      status_message(""),
      person_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status_message = strlen(this->status_message);
      varToArr(outbuffer + offset, length_status_message);
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_status_message);
      offset += length_status_message;
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
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      arrToVar(length_status_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
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

    virtual const char * getType() override { return ADDPERSON; };
    virtual const char * getMD5() override { return "d0c6748026a2a5b26e8c93f910dc4041"; };

  };

  class AddPerson {
    public:
    typedef AddPersonRequest Request;
    typedef AddPersonResponse Response;
  };

}
#endif
