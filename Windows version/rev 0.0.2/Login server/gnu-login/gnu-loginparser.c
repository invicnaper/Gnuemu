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
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "../header/mysql_ins.h"
//----------------------------

int nb_send_packets = 0, nb_rcv_packets = 0, nb_client = -1, errors = 0;
//----------------------------

void funct_remove_packet(char* str, char c) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = '\0';

    return ;
}
void remove_packet_account(SOCKET sock, char packet [1024]){
    funct_remove_packet(packet, '#');
    funct_remove_packet(packet, '1');
    //printf("'%s'\n", packet);
    check_account(sock,"hamza","hamza",NULL);
    return ;
}
void check_account(SOCKET sock, const char* client_account, const char* client_password, const char* client_crypted_password){
    const char* row_account = NULL;
    const char* row_password = NULL;
    new_mysql sql;
    mysql_init(&sql.mysql);
    mysql_options(&sql.mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&sql.mysql,sql_ip,sql_user,sql_pass,sql_db,0,NULL,0))
    {
            const char* query = "SELECT user, password FROM gnu_accounts";
            mysql_query(&sql.mysql, query);
            MYSQL_RES *result = NULL;
            MYSQL_ROW row;
            unsigned int i = 0;
            unsigned int num_champs = 0;
            int j =1;
            result = mysql_use_result(&sql.mysql);
            num_champs = mysql_num_fields(result);
            while ( ( row = mysql_fetch_row(result)) != NULL ) {
                row_account = row[0];
                row_password = row[1];
                if ((row_account == client_account) && (row_password == client_password)){
                    account_ok(sock, client_account);
                }
                else{
                    account_incorrect(sock);
                }

            }

            mysql_free_result(result);
            mysql_close(&sql.mysql);

    }
    else
    {
        message_error("Can't connect to mysql");
        exit(1);
    }

    return;

}
void account_ok(SOCKET sock, const char* client_account){
    write_serverr(sock, "Af0");
    nb_send_packets = nb_send_packets + 1;
    //write_serverr(sock, "Ad" && client_account);
    write_serverr(sock, "Ac0");
    nb_send_packets = nb_send_packets + 1;
    write_serverr(sock, "AH1");
    nb_send_packets = nb_send_packets + 1;
    write_serverr(sock, "AlK1");
    nb_send_packets = nb_send_packets + 1;
    write_serverr(sock, "AQ");
    nb_send_packets = nb_send_packets + 1;
    new_console(0);
    return ;
}
void account_incorrect(SOCKET sock){
    write_serverr(sock, "AlEf");
    nb_send_packets = nb_send_packets + 1;
    new_console(0);
    return ;
}
void account_banned(SOCKET sock){
    write_serverr(sock, "AlEb");
    nb_send_packets = nb_send_packets + 1;
    new_console(0);
    return ;
}
void account_connected(SOCKET sock){
    nb_send_packets = nb_send_packets + 1;
    new_console(0);
    return ;
}
