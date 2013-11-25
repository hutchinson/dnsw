/* socket_utils.h provides a few simple wrapper functions around standard BSD socket
 * functions.
 */

#include <stdint.h>
#include <netinet/in.h>

/***************************************************************************************
 * Definitions
 ***************************************************************************************/
#define SOCKET int
#define ENDPOINT struct sockaddr_in

typedef uint16_t PORT;

SOCKET build_socket(const char *ip_address, PORT port, ENDPOINT *endpoint);