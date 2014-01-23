#ifndef CLIENT_H_1
#define CLIENT_H_1

#ifdef WIN32

#include <winsock2.h>

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#else

#error not defined for this platform

#endif

#define CRLF	 "\r\n"
#define PORT	 5555

#define BUF_SIZE 1024

static void init_sr_plugin(void);
static void end_sr_plugin(void);
static void app_sr_plugin(const char *address, const char *name);
static int init_connection_sr_plugin(const char *address);
static void end_connection_sr_plugin(int sock);
static int read_server_sr_plugin(SOCKET sock, char *buffer);
static void write_server_sr_plugin(SOCKET sock, const char *buffer);

#endif /* guard */
