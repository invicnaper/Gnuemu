#ifndef OTHERS_INS_H_INCLUDED
#define OTHERS_INS_H_INCLUDED

int nb_gs ;
int nb_client;
int nb_rcv_packets;
int nb_send_packets;
int plugin_sendpackets_status;
int errors;
struct OTHERS_n{

    char port_srv[10];
    /*
    +++++++ GNU VERSION ++++++
    */
    const char * gnu_version;
    /*
    +++++++ GNU VERSION ++++++
    */


}OTHERS_n;
typedef struct OTHERS_n oth;

#endif // OTHERS_INS_H_INCLUDED
