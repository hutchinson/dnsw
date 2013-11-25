/*
 * dnsw (Domain Name System Walker)
 *
 * dnsw is intended as an educational tool for understanding the DNS protocol
 * and walking the distributed tree structure maintained by nameservers
 * throughout the world
 */

#include <stdio.h>

#include "socket_utils.h"

int main(int argc, char **argv)
{
  printf("dnsw!\n");
  ENDPOINT dns_server;
  build_socket("127.0.0.1", 53, &dns_server);
  
  return 0;
}
