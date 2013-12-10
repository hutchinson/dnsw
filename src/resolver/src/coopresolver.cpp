#include "resolver/coopresolver.h"

#include <iostream>

dnsw::coopresolver::coopresolver()
{
  std::cout << "coopresolver!" << std::endl;
}

dnsw::coopresolver::~coopresolver()
{
  std::cout << "~coopresolver" << std::endl;
}

const std::string dnsw::coopresolver::resolve(const std::string &name,
                                         dnsw::rr::TYPE record_type)
{
  return "";
}
