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

#include <stdio.h>
#include <stdlib.h>
#include "header/client-1_ins.h"
#include "header/mysql_ins.h"
#include "header/client_ins.h"
#include "header/others_ins.h"
#include "header/config_ins.h"
#include "header/server_ins.h"
#include "header/md5.h"

int main(int argc , char** argv){
    new_mysql newsql;
    loading_emu();
    message_info("preparing the emu");
    read_config();
    connect_to_mysql(); // nouvelle connetion à mysql
    load_accounts(); //chargement des comptes
    load_gameserver(); //chargement des gameservers
    recup_pc_name();
    check_sr_plugin();

    return 0;

	}

