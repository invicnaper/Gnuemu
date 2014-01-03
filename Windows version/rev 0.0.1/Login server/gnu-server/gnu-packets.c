
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
#include <pcap.h>
#define MAX_ADAPTER 1024
void send_packet(){
     HINSTANCE DLLHandle;
     typedef int(*lib)(char [MAX_ADAPTER]);
     lib libgnuemu_packet;
     DLLHandle = LoadLibrary("libgnuemu_packets.dll");

     libgnuemu_packet = (lib)GetProcAddress(DLLHandle,"send_test_packets");
     libgnuemu_packet("YOUR_ADAPTER");

     FreeLibrary(DLLHandle);

     return;


}
void data_arrived(SOCKET sock, char buffer[BUF_SIZE]){
    if (strcmp(buffer, "new") == 0){
        nb_client = nb_client + 1;
        new_console(0);
        if (nb_client){
            new_console(0);
            }
         }
    if (strcmp(buffer, "del") == 0){
        nb_client = nb_client - 1;
        new_console(0);
         }
    if (strstr(buffer, "#1")){
            nb_rcv_packets = nb_rcv_packets +1;
            remove_packet_account(sock, buffer);
         }
    if (nb_client == -1){
        nb_client = 0;
        new_console(0);
        }
    if (!nb_client){
        message_info("Waiting for first client");
        }


    return ;

}

