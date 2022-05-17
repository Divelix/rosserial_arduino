#ifndef _ROS_nautilos_general_TaskStatus_h
#define _ROS_nautilos_general_TaskStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nautilos_general
{

  class TaskStatus : public ros::Msg
  {
    public:
      typedef const char* _goal_id_type;
      _goal_id_type goal_id;
      typedef const char* _user_id_type;
      _user_id_type user_id;
      typedef const char* _status_type;
      _status_type status;

    TaskStatus():
      goal_id(""),
      user_id(""),
      status("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_goal_id = strlen(this->goal_id);
      varToArr(outbuffer + offset, length_goal_id);
      offset += 4;
      memcpy(outbuffer + offset, this->goal_id, length_goal_id);
      offset += length_goal_id;
      uint32_t length_user_id = strlen(this->user_id);
      varToArr(outbuffer + offset, length_user_id);
      offset += 4;
      memcpy(outbuffer + offset, this->user_id, length_user_id);
      offset += length_user_id;
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
      uint32_t length_goal_id;
      arrToVar(length_goal_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_goal_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_goal_id-1]=0;
      this->goal_id = (char *)(inbuffer + offset-1);
      offset += length_goal_id;
      uint32_t length_user_id;
      arrToVar(length_user_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_id-1]=0;
      this->user_id = (char *)(inbuffer + offset-1);
      offset += length_user_id;
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

    virtual const char * getType() override { return "nautilos_general/TaskStatus"; };
    virtual const char * getMD5() override { return "925e52346cd5c54ca42c1f03f00b6539"; };

  };

}
#endif
