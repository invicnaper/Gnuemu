#ifndef MYSQL_INS_H_INCLUDED
#define MYSQL_INS_H_INCLUDED
#include <winsock.h>
#include <MYSQL/mysql.h>
const char * sql_ip;
const char * sql_user;
const char * sql_pass;
const char * sql_db;
struct MYSQL_n{

    MYSQL mysql;
    char ip_srv[100];
    const char* port_srv;

}MYSQL_n;
typedef struct MYSQL_n new_mysql;

#endif // MYSQL_INS_H_INCLUDED
