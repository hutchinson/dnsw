SET(DB_HEADERS "include/db/node.h"
                     "include/db/rr.h"
                     "include/db/rr_printer.h")

SET(DB_SOURCE "src/rr_printer.cpp")

INCLUDE_DIRECTORIES(${DNSW_INCLUDES})

ADD_LIBRARY(db ${DB_HEADERS} ${DB_SOURCE})
