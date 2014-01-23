#include <stdio.h>
#include <stdlib.h>

/*

---------------------------------------------------------------
---------------------------------------------------------------

 _____  _   _ _   _   _   ________  ____   _
|  __ \| \ | | | | | ( ) |  ___|  \/  | | | |
| |  \/|  \| | | | | |/  | |__ | .  . | | | |
| | __ | . ` | | | |     |  __|| |\/| | | | |
| |_\ \| |\  | |_| |     | |___| |  | | |_| |
 \____/\_| \_/\___/      \____/\_|  |_/\___/


[+] Header Files

---------------------------------------------------------------
---------------------------------------------------------------
*/
#define NB_MAX 100
#define CONFIGNAME "config.ini.txt" // nom de la config
#define MAXBUF 1024 // maximum de la chaine
#define DELIM "="

struct configg
{
   	/*
	--------------------------------
			SERVER INFO
	--------------------------------
	*/
	char ip_server[MAXBUF];
    char port[MAXBUF];
    /*
	--------------------------------
			MYSQL INFO
	--------------------------------
	*/
	char sqlip[MAXBUF];
    char sqluser[MAXBUF];
    char sqlpass[MAXBUF];

    char accounts[MAXBUF];
    char characters[MAXBUF];
    char others[MAXBUF];

    /*
	--------------------------------
			 INFO
	--------------------------------
	*/
	char login_version[MAXBUF];
	char max_player[MAXBUF];

};
typedef struct config{

	FILE * gnu_config;


}config;
struct config cn;
