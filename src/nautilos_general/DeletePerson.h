#ifndef _ROS_SERVICE_DeletePerson_h
#define _ROS_SERVICE_DeletePerson_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nautilos_general
{

static const char DELETEPERSON[] = "nautilos_general/DeletePerson";

  class DeletePersonRequest : public ros::Msg
  {
    public:
      typedef const char* _person_id_type;
      _person_id_type person_id;

    DeletePersonRequest():
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

    virtual const char * getType() override { return DELETEPERSON; };
    virtual const char * getMD5() override { return "1b0179d1c2d646b3a6474f7a14b08c62"; };

  };

  class DeletePersonResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_type;
      _status_type status;

    DeletePersonResponse():
      success(0),
      status("")
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
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
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
      uint32_t length_status;
      arrToVar(length_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
     return offset;
    }

    virtual const char * getType() override { return DELETEPERSON; };
    virtual const char * getMD5() override { return "38b8954d32a849f31d78416b12bff5d1"; };

  };

  class DeletePerson {
    public:
    typedef DeletePersonRequest Request;
    typedef DeletePersonResponse Response;
  };

}
#endif
