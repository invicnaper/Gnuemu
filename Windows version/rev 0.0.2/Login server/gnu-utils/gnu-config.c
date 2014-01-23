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
#include <string.h>
#include "../header/config_ins.h"
#include "../header/mysql_ins.h"
struct configg read_all_item(char *filename){
	message_info("Check if config exist");
	struct configg configstruct;
	cn.gnu_config = NULL;
	cn.gnu_config = fopen(filename,"r");
	 char line[MAXBUF];
                int i = 0;
                while(fgets(line, sizeof(line), cn.gnu_config) != NULL)
                {
                        char *cfline;
                        cfline = strstr((char *)line,DELIM);
                        cfline = cfline + strlen(DELIM);

                        if (i == 0){
                                memcpy(configstruct.login_version,cfline,strlen(cfline));

                                //printf("%s",configstruct.imgserver);
                        } else if (i == 1){
                                memcpy(configstruct.port,cfline,strlen(cfline));
                                //printf("%s",configstruct.ccserver);
                        } else if (i == 2){
                                memcpy(configstruct.sqlip,cfline,strlen(cfline));
                                //printf("%s",configstruct.port);
                        } else if (i == 3){
                                memcpy(configstruct.sqluser,cfline,strlen(cfline));

                                //printf("%s",configstruct.imagename);
                        } else if (i == 4){
                                memcpy(configstruct.sqlpass,cfline,strlen(cfline));
                                //printf("%s",configstruct.getcmd);
                        }
                        else if (i == 5){
                                memcpy(configstruct.accounts,cfline,strlen(cfline));
                                //printf("%s",configstruct.getcmd);
                        }
                        else if (i == 6){
                                memcpy(configstruct.characters,cfline,strlen(cfline));
                                //printf("%s",configstruct.getcmd);
                        }
                        else if (i == 7){
                                memcpy(configstruct.others,cfline,strlen(cfline));
                                //printf("%s",configstruct.getcmd);
                        }
                        else if (i == 8){
                                memcpy(configstruct.max_player,cfline,strlen(cfline));
                                //printf("%s",configstruct.getcmd);
                        }
                        else if (i == 9){
                                memcpy(configstruct.ip_server,cfline,strlen(cfline));
                                //printf("%s",configstruct.getcmd);
                        }

                        i++;
                } // End while
                 fclose(cn.gnu_config);

        return configstruct;
}

int check_if_config_exist(int tableau[NB_MAX]){

	int i = 0;
	/*
	message_info("Check if config exist");
	cn.gnu_config = NULL;
	cn.gnu_config = fopen(cn.CONFIGNAME,"r");
	if (!cn.gnu_config){
		message_error("Config doesn't exist .. Exit");
		exit(1);
	}
	else {
		message_done("Config exist");

	}
	while(i < NB_MAX && fscanf(cn.gnu_config, "%d", &tableau[i])==1){
		i++;
	*/
	return i ;


}
void read_config_content(int tableau[], int n){
	int i;
	if (n){
		for (i = 0; i<n;i++){
			printf("tab(%d) = %d\n",i,tableau[i]);
		}
	}
	else {
		message_error("Can't find any item in config");
	}
}
int read_config(){
//	int tab[NB_MAX],n;
	message_info("Loading config");
	//check_if_config_exist();
	//n = check_if_config_exist(tab);
    //read_config_content(tab,n);
    new_mysql sql;
	struct configg configstruct;
	configstruct = read_all_item(CONFIGNAME);

     /* Struct members */
	 message_info("Reading items , and showing them");
     ok();
     printf("LOGIN_VERSION = %s",configstruct.login_version);
	 ok();
     printf("IP_SERVER = %s",configstruct.ip_server);
     ok();
     printf("IP = %s",configstruct.sqlip);
     ok();
     printf("PORT = %s",configstruct.port);
     ok();
     printf("ACOOUNTS = %s",configstruct.accounts);
     ok();
     printf("CHARACTERS = %s",configstruct.characters);
     ok();
     printf("OTHERS = %s",configstruct.others);
     ok();
     printf("MAX_PLAYER = %s",configstruct.max_player);

    sql.ip_srv[100] = configstruct.ip_server;
    sql_ip = "Localhost";
    sql_pass = "";
    sql_db = "gnuemu";
    sql_user = "root";
    sql.port_srv = configstruct.port;

    return 0;
}
