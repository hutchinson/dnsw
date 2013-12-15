#include "resolver/coopresolver.h"

#include "db/rr_printer.h"

#include <iostream>
#include <thread>
#include <utility>
#include <chrono>
#include <functional>
#include <vector>

namespace
{

}

dnsw::coopresolver::coopresolver()
  : m_root()
{
  // Create a root node which will have the label ''
  m_root = dnsw::node::create_node("");

  const char *root_ns_ip = "xxx.xxx.xxx.xxx";

  dnsw::rr_ptr root_ns = dnsw::rr::create_rr(dnsw::A,       // IP Address
                             dnsw::IN,
                             0,             // Nevere expire
                             strlen(root_ns_ip),
                             reinterpret_cast<const uint8_t*>(root_ns_ip));
  m_root->add_authorative_ns(root_ns);
}

dnsw::coopresolver::~coopresolver()
{
  std::cout << "~coopresovler" << std::endl;
}

const std::string dnsw::coopresolver::resolve(const std::string &name,
                                         dnsw::TYPE record_type)
{
  // The end goal is for n resolvers to each query simultaneously
  // one of the 14 root nameservers.
  //
  // To begin with we'll start with a coopresolver kicking off the resolution
  // to just one nameserver.
  
  // Starting at the root node, generate a query, and send to the name
  // server.
  // Process the response, based on answer return with answer, error or
  // re-query another nameserver.

  dnsw::rr_ptr root_ns = m_root->get_nameserver_by_index(0);

  dnsw::rr_printer_factory::get_factory().format_rr(root_ns, std::cout);
  std::cout << std::endl;
  
  return "";
}
