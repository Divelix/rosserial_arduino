#ifndef _ROS_nautilos_general_TaskCommand_h
#define _ROS_nautilos_general_TaskCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nautilos_general
{

  class TaskCommand : public ros::Msg
  {
    public:
      typedef const char* _goal_id_type;
      _goal_id_type goal_id;
      typedef const char* _user_id_type;
      _user_id_type user_id;
      typedef const char* _command_type;
      _command_type command;

    TaskCommand():
      goal_id(""),
      user_id(""),
      command("")
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
      uint32_t length_command = strlen(this->command);
      varToArr(outbuffer + offset, length_command);
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
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
      uint32_t length_command;
      arrToVar(length_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
     return offset;
    }

    virtual const char * getType() override { return "nautilos_general/TaskCommand"; };
    virtual const char * getMD5() override { return "3402561371f15d31d2678db5a9ef2f80"; };

  };

}
#endif
