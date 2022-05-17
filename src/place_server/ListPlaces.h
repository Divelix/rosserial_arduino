#ifndef _ROS_SERVICE_ListPlaces_h
#define _ROS_SERVICE_ListPlaces_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "place_server/Place.h"

namespace place_server
{

static const char LISTPLACES[] = "place_server/ListPlaces";

  class ListPlacesRequest : public ros::Msg
  {
    public:

    ListPlacesRequest()
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

    virtual const char * getType() override { return LISTPLACES; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListPlacesResponse : public ros::Msg
  {
    public:
      uint32_t places_length;
      typedef place_server::Place _places_type;
      _places_type st_places;
      _places_type * places;

    ListPlacesResponse():
      places_length(0), st_places(), places(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->places_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->places_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->places_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->places_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->places_length);
      for( uint32_t i = 0; i < places_length; i++){
      offset += this->places[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t places_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      places_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      places_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      places_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->places_length);
      if(places_lengthT > places_length)
        this->places = (place_server::Place*)realloc(this->places, places_lengthT * sizeof(place_server::Place));
      places_length = places_lengthT;
      for( uint32_t i = 0; i < places_length; i++){
      offset += this->st_places.deserialize(inbuffer + offset);
        memcpy( &(this->places[i]), &(this->st_places), sizeof(place_server::Place));
      }
     return offset;
    }

    virtual const char * getType() override { return LISTPLACES; };
    virtual const char * getMD5() override { return "73d2bd959132b011ac438eeb32d02970"; };

  };

  class ListPlaces {
    public:
    typedef ListPlacesRequest Request;
    typedef ListPlacesResponse Response;
  };

}
#endif
