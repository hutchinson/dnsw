#ifndef RR_H
#define RR_H

// rr.h
// 
// The rr class represents a Resource Record on a particular node in the
// DNS tree.
// 
// An rr has an owner name (the node this rr belongs)
// type - the type of the record.
// class - the class
// ttl - 32 bit signed in. how long it can be cached.
// rdlength - length of the rdata field.
// rdata - variable length string that describes the resource. The format of
// this field depends on the type and class fields.

#include <memory>
#include <csdint>

#include "node.h"

namespace dnws
{
  namespace rr
  {
    class rr;
    typedef std::shared_ptr<rr> rr_ptr;

    typedef uint16_t TYPE;
    typedef uint16_t CLASS;
    typedef int32_t TTL;
    typedef uint16_t RDLENGTH;
    typedef std::shared_ptr<uint8_t*> RDATA;

    const TYPE A = 1;
    const TYPE AAAA = 28;
    const TYPE NS = 2;
    const TYPE MD = 3;
    const TYPE MF = 4;
    const TYPE CNAME = 5;
    const TYPE SOA = 6;
    const TYPE MB = 7;
    const TYPE MG = 8;
    const TYPE MR = 9;
    const TYPE NULL_TYPE = 10;
    const TYPE WKS = 11;
    const TYPE PTR = 12;
    const TYPE HINFO = 13;
    const TYPE MINFO = 14;
    const TYPE MX = 15;
    const TYPE TXT 16;

    const CLASS IN = 1;
    const CLASS CS = 2;
    const CLASS CH = 3;
    const CLASS HS = 4;

    class rr
    {
      public:
        static rr_ptr create_rr(const weak_node_ptr owner,
                                TYPE type,
                                CLASS in_class,
                                TTL ttl,
                                RDLENGTH length,
                                RDATA data)
        {

        }
                                

      private:
        rr(const weak_node_ptr owner,
           TYPE type,
           CLASS in_class,
           TTL ttl,
           RDLENGTH length,
           RDATA data):
          m_owner(owner), m_type(type), m_in_class(in_class),
          m_ttl(ttl), m_length(length), m_data(data)
        { }

        // Private members
        const weak_node_ptr m_owner;
        const TYPE m_type;
        const CLASS m_in_class;
        const TTL m_ttl;
        const RDLENGTH m_length;
        const RDATA m_data;
    };
  }
}

#endif
