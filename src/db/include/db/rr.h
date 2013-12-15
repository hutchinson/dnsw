#ifndef RR_H
#define RR_H

// rr.h
// 
// The rr class represents a Resource Record on a particular node in the
// DNS tree.
// 
// An rr has an owner (implicit as it is owned by a node)
// type - the type of the record.
// class - the class
// ttl - 32 bit signed in. how long it can be cached.
// rdlength - length of the rdata field.
// rdata - variable length string that describes the resource. The format of
// this field depends on the type and class fields.

#include <new>
#include <memory>
#include <cstdint>
#include <cstring>

namespace dnsw
{
  class rr;
  typedef std::shared_ptr<rr> rr_ptr;

  typedef uint16_t TYPE;
  typedef uint16_t CLASS;
  typedef int32_t TTL;
  typedef uint16_t RDLENGTH;
  typedef std::shared_ptr<uint8_t> RDATA;

  const TYPE A = 1;
  const TYPE AAAA = 28;
  const TYPE NS = 2;
  const TYPE CNAME = 5;
  const TYPE SOA = 6;
  const TYPE NULL_TYPE = 10;
  const TYPE PTR = 12;
  const TYPE MX = 15;
  const TYPE TXT = 16;

  const CLASS IN = 1;
  const CLASS CS = 2;
  const CLASS CH = 3;
  const CLASS HS = 4;

  class rr
  {
    public:
      // Creates a new resource record with the specified type,
      // class, time to live and associated data.
      // A copy of the data will be taken.
      static rr_ptr create_rr(TYPE type,
                              CLASS in_class,
                              TTL ttl,
                              RDLENGTH length,
                              const uint8_t *data)
      {
        // Copy the data
        uint8_t *data_copy = static_cast<uint8_t*>(operator new(length));
        RDATA data_under_ownership(data_copy);
        memcpy(data_copy, data, length);

        return rr_ptr(new rr(type,
                             in_class,
                             ttl,
                             length,
                             data_under_ownership));
                             
      }
                              
      // Private members
      const TYPE type;
      const CLASS in_class;
      const TTL ttl;
      const RDLENGTH length;
      const RDATA data;
  
    private:
      rr(TYPE type,
         CLASS in_class,
         TTL ttl,
         RDLENGTH length,
         RDATA data):
        type(type), in_class(in_class),
        ttl(ttl), length(length), data(data) {}
  };
}

#endif
