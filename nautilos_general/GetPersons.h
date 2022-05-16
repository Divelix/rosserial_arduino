#ifndef _ROS_SERVICE_GetPersons_h
#define _ROS_SERVICE_GetPersons_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nautilos_general/PersonInfo.h"

namespace nautilos_general
{

static const char GETPERSONS[] = "nautilos_general/GetPersons";

  class GetPersonsRequest : public ros::Msg
  {
    public:
      typedef nautilos_general::PersonInfo _info_type;
      _info_type info;

    GetPersonsRequest():
      info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETPERSONS; };
    virtual const char * getMD5() override { return "8220590adc3024bc5b934f5c3f4dd5f9"; };

  };

  class GetPersonsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_type;
      _status_type status;
      uint32_t person_ids_length;
      typedef char* _person_ids_type;
      _person_ids_type st_person_ids;
      _person_ids_type * person_ids;
      uint32_t persons_info_length;
      typedef nautilos_general::PersonInfo _persons_info_type;
      _persons_info_type st_persons_info;
      _persons_info_type * persons_info;

    GetPersonsResponse():
      success(0),
      status(""),
      person_ids_length(0), st_person_ids(), person_ids(nullptr),
      persons_info_length(0), st_persons_info(), persons_info(nullptr)
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
      *(outbuffer + offset + 0) = (this->person_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_ids_length);
      for( uint32_t i = 0; i < person_ids_length; i++){
      uint32_t length_person_idsi = strlen(this->person_ids[i]);
      varToArr(outbuffer + offset, length_person_idsi);
      offset += 4;
      memcpy(outbuffer + offset, this->person_ids[i], length_person_idsi);
      offset += length_person_idsi;
      }
      *(outbuffer + offset + 0) = (this->persons_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->persons_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->persons_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->persons_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->persons_info_length);
      for( uint32_t i = 0; i < persons_info_length; i++){
      offset += this->persons_info[i].serialize(outbuffer + offset);
      }
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
      uint32_t person_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      person_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      person_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      person_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->person_ids_length);
      if(person_ids_lengthT > person_ids_length)
        this->person_ids = (char**)realloc(this->person_ids, person_ids_lengthT * sizeof(char*));
      person_ids_length = person_ids_lengthT;
      for( uint32_t i = 0; i < person_ids_length; i++){
      uint32_t length_st_person_ids;
      arrToVar(length_st_person_ids, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_person_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_person_ids-1]=0;
      this->st_person_ids = (char *)(inbuffer + offset-1);
      offset += length_st_person_ids;
        memcpy( &(this->person_ids[i]), &(this->st_person_ids), sizeof(char*));
      }
      uint32_t persons_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      persons_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      persons_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      persons_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->persons_info_length);
      if(persons_info_lengthT > persons_info_length)
        this->persons_info = (nautilos_general::PersonInfo*)realloc(this->persons_info, persons_info_lengthT * sizeof(nautilos_general::PersonInfo));
      persons_info_length = persons_info_lengthT;
      for( uint32_t i = 0; i < persons_info_length; i++){
      offset += this->st_persons_info.deserialize(inbuffer + offset);
        memcpy( &(this->persons_info[i]), &(this->st_persons_info), sizeof(nautilos_general::PersonInfo));
      }
     return offset;
    }

    virtual const char * getType() override { return GETPERSONS; };
    virtual const char * getMD5() override { return "d78fc739aeaecc62928b58febcfb9883"; };

  };

  class GetPersons {
    public:
    typedef GetPersonsRequest Request;
    typedef GetPersonsResponse Response;
  };

}
#endif
