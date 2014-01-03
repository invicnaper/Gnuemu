/*

---------------------------------------------------------------
---------------------------------------------------------------
 _____  _   _ _   _   _   ________  ____   _
|  __ \| \ | | | | | ( ) |  ___|  \/  | | | |
| |  \/|  \| | | | | |/  | |__ | .  . | | | |
| | __ | . ` | | | |     |  __|| |\/| | | | |
| |_\ \| |\  | |_| |     | |___| |  | | |_| |
 \____/\_| \_/\___/      \____/\_|  |_/\___/


#Author : Naper
#Code in : C
#Under GPL

---------------------------------------------------------------
---------------------------------------------------------------
*/
#include <errno.h>
#include "../header/client-1_ins.h"
#define _WIN32_WINNT 0x0500

static void initt(void)
{
#ifdef WIN32
   WSADATA wsa;
   int err = WSAStartup(MAKEWORD(2, 2), &wsa);
   if(err < 0)
   {
      puts("WSAStartup failed !");
      exit(EXIT_FAILURE);
   }
#endif
}

static void endd(void)
{
#ifdef WIN32
   WSACleanup();
#endif
}

int plugin_sendpackets_status = 0; // closed

void recup_pc_name()
{
    char lpBuffer[256];
    DWORD dwBufLength = sizeof(lpBuffer);
    if (GetComputerNameEx(ComputerNameDnsFullyQualified, lpBuffer, &dwBufLength))
    {

    }//printf("%s\n", lpBuffer);
    else
    {
        fprintf(stderr, "La fonction GetComputerNameEx a echoue.\n");
    }
    recup_ip(lpBuffer);
    return ;
}
void recup_ip(const char * HostName){
    struct hostent * host;
    struct in_addr addr;

    if ((host = gethostbyname(HostName)) != NULL)
    {
       int i;
       //ip_add = inet_ntoa(addr);
    }
    else
    {
         printf("La fonction gethostbyname a echoue.\n");
    }

    return;
}

static void appp(const char *address, const char *name)
{
   SOCKET sock = init_connectionn(address);
   char buffer[BUF_SIZE];

   fd_set rdfs;

   /* send our name */
   write_serverr(sock, name);
   plugin();
   puts("Sr plugin connected");
   start_server();
   while(1)
   {
      FD_ZERO(&rdfs);
      /* add the socket */
      FD_SET(sock, &rdfs);

      if(select(sock + 1, &rdfs, NULL, NULL, NULL) == -1)
      {
         message_error("Can't creat login server if sr plugin is not lunched");
         exit(1);
      }

      /* something from standard input : i.e keyboard */
      if(FD_ISSET(STDIN_FILENO, &rdfs))
      {
         fgets(buffer, BUF_SIZE - 1, stdin);
         {
            char *p = NULL;
            p = strstr(buffer, "\n");
            if(p != NULL)
            {
               *p = 0;
            }
            else
            {
               /* fclean */
               buffer[BUF_SIZE - 1] = 0;
            }
         }
         write_serverr(sock, buffer);
      }
      else if(FD_ISSET(sock, &rdfs))
      {
         int n = read_serverr(sock, buffer);
         /* server down */
         if(n == 0)
         {
            plugin_sendpackets_status = 0;
            while(1){
            plugin();
            puts("Sr plugin is disconected");
            }
         }
         plugin_sendpackets_status = 1;
         new_console(0);
         data_arrived(sock,buffer);
      }
   }

   end_connectionn(sock);
}

void wait_for_plugin(){

    while(plugin_sendpackets_status = 0){
        plugin();
        printf("Waiting for the send packets plugin _n");
    }
    return ;
}

int init_connectionn(const char *address)
{
   SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
   SOCKADDR_IN sin = { 0 };
   struct hostent *hostinfo;

   if(sock == INVALID_SOCKET)
   {
      message_error("Can't creat login server if sr plugin is not lunched");
      exit(1);
   }

   hostinfo = gethostbyname(address);
   if (hostinfo == NULL)
   {
      fprintf (stderr, "Unknown host %s.\n", address);
      exit(EXIT_FAILURE);
   }

   sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
   sin.sin_port = htons(5555);
   sin.sin_family = AF_INET;

   if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
   {
      message_error("Can't creat login server if sr plugin is not lunched");
      exit(1);
   }

   return sock;
}

 void end_connectionn(int sock)
{
   closesocket(sock);
}

int read_serverr(SOCKET sock, char *buffer)
{
   int n = 0;

   if((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
   {
      while(1){
      plugin();
      puts("Sr plugin is disconected");
      }

   }

   buffer[n] = 0;
   return n;
}

void write_serverr(SOCKET sock, const char *buffer)
{
   if(send(sock, buffer, strlen(buffer), 0) < 0)
   {
      message_error("Can't creat login server if sr plugin is not lunched");
      exit(1);
   }
}

int check_sr_plugin()
{
   initt();

   appp(ip_srv, "gnuemu");

   endd();

   return EXIT_SUCCESS;
}
