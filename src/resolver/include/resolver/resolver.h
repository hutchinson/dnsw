#ifndef RESOLVER_H
#define RESOLVER_H

#include "db/rr.h"

namespace dnsw
{
  // resolver is the abstract base class from which concrete resovlers are derived. 
  class resolver
  {
    public:
      // Should resolve the resource name and type to a particular record type and return it as a string.
      virtual const std::string resolve(const std::string &name,
                                        dnsw::rr::TYPE record_type) = 0;
  };
}

#endif
