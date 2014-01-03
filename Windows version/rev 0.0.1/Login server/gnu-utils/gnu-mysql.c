//for linux
/*
#include <my_global.h>
#include <mysql.h>
*/
//for windows
#include <winsock.h>
#include <MYSQL/mysql.h>

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
MYSQL mysql;
int nb_account = 0, nb_gs = 0;
void mysql_version()
{
    //for linux
    //  printf("MySQL client version: %s\n", mysql_get_client_info());
    //for windows

}
void load_gameserver(MYSQL mysql){

    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    message_info("Loading GameServer");
    if(mysql_real_connect(&mysql,sql_ip,sql_user,sql_pass,sql_db,0,NULL,0))
    {

        mysql_query(&mysql, "SELECT * FROM gnu_servers_list");
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;

        result = mysql_use_result(&mysql);

        num_champs = mysql_num_fields(result);

        while ((row = mysql_fetch_row(result)))
        {
            unsigned long *lengths;
            lengths = mysql_fetch_lengths(result);
            int nb_accounts_load = 0;
            ok();
            printf("`%d` gameserver loaded\n",mysql_num_rows(result));
            nb_gs = mysql_num_rows(result);
        }
        mysql_free_result(result);
        mysql_close(&mysql);

    }
    else
    {
        message_error("Can't load gameserver");
        exit(1);
    }

    return;

}

void load_accounts(MYSQL mysql){
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    message_info("Loading accounts");
    if(mysql_real_connect(&mysql,sql_ip,sql_user,sql_pass,sql_db,0,NULL,0))
    {

        mysql_query(&mysql, "SELECT * FROM gnu_accounts");
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;

        result = mysql_use_result(&mysql);

        num_champs = mysql_num_fields(result);

        while ((row = mysql_fetch_row(result)))
        {
            unsigned long *lengths;
            lengths = mysql_fetch_lengths(result);
            int nb_accounts_load = 0;
            for(i = 0; i < num_champs; i++)
            {
            //http://nsa34.casimages.com/img/2013/12/21/131221031054385470.png
            }
            ok();
            printf("`%d` accounts loaded\n",mysql_num_rows(result));
            nb_account = mysql_num_rows(result);
        }

        mysql_free_result(result);
        mysql_close(&mysql);

    }
    else
    {
        message_error("Can't load accounts");
        exit(1);
    }

    return;


}
int connect_to_mysql(){
    message_info("Connecting to mysql server");
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(&mysql,sql_ip,sql_user,sql_pass,sql_db,0,NULL,0))
    {
        message_done("Connected to mysql server");
        load_accounts(mysql);
        load_gameserver(mysql);
    }
    else
    {
        message_error("Can't connect to mysql server");
        exit(1);
    }

   return 0;

}
