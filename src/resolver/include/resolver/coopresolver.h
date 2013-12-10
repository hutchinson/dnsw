#ifndef COOPRESOLVER_H
#define COOPRESOVLER_H

#include "resolver/resolver.h"

namespace dnsw
{
  class coopresolver : public dnsw::resolver
  {
    public:
      coopresolver();
      ~coopresolver();
      const std::string resolve(const std::string &name,
                                dnsw::rr::TYPE record_type);
  };
}

#endif
