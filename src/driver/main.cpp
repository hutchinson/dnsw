#include <iostream>
#include <memory>

#include "db/node.h"
#include "resolver/coopresolver.h"

int main(int argc, char **argv)
{
  std::cout << "dnsw!" << std::endl;

// TODO: Migrate to tests
//  dnsw::node_ptr root = dnsw::node::create_node("");
//  dnsw::node_ptr com = dnsw::node::create_node("com");
//  dnsw::node_ptr org = dnsw::node::create_node("org");
//  dnsw::node_ptr gov = dnsw::node::create_node("gov");
//  dnsw::node_ptr uk = dnsw::node::create_node("uk");
//  dnsw::node_ptr co = dnsw::node::create_node("co");
//  dnsw::node_ptr bbc = dnsw::node::create_node("bbc");
//
//  dnsw::node::add_child(root, com);
//  dnsw::node::add_child(root, org);
//  dnsw::node::add_child(root, gov);
//  dnsw::node::add_child(root, uk);
//
//  dnsw::node::add_child(uk, co);
//
//  dnsw::node::add_child(co, bbc);
//
//  // Not an efficient way to do this but just testing...
//  std::string domain_name;
//  dnsw::node_ptr p(bbc);
//  while(p.get())
//  {
//    domain_name += p->get_label();
//    if(p->get_parent().lock().get())
//      domain_name += '.';
//
//    p = p->get_parent().lock();
//  }
//
//  std::cout << "Domain name '" << domain_name << "'" << std::endl;

  // Build a 'resolver'.
  std::shared_ptr<dnsw::resolver> resolver(new dnsw::coopresolver());
  resolver->resolve("www.example.com", dnsw::A);

  return 0;
}
