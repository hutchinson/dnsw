SET(RESOLVER_HEADERS "include/resolver/resolver.h"
                     "include/resolver/coopresolver.h")

SET(RESOLVER_SOURCE "src/coopresolver.cpp")

INCLUDE_DIRECTORIES(${DNSW_INCLUDES})

ADD_LIBRARY(resolver ${RESOLVER_HEADERS} ${RESOLVER_SOURCE})
