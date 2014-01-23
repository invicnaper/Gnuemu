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
#include "../header/others_ins.h"
void new_console(int nb_Gameserver){
    oth OTHERS;
    OTHERS.gnu_version = "0.0.2";
    system("cls");
    console_header();
    color(13,0);
    printf("\nClient :");
    reintialise_color();
    printf(" %d \t \t",nb_client);
    color(3,0);
    printf("GameServer :");
    reintialise_color();
    printf(" %d/%d\n\n",nb_Gameserver,nb_gs);
    color(6,0);
    printf("GnuEmu :");
    reintialise_color();
    printf(" version %s for windows \t \t",OTHERS.gnu_version);
    color(4,0);
    printf("Errors :");
    reintialise_color();
    printf(" %d\n\n",errors);
    color(2, 0);
    printf("Packets sent :");
    reintialise_color();
    printf(" %d \t \t",nb_send_packets);
    color(14,0);
    printf("Packets received :");
    reintialise_color();
    printf(" %d\n\n",nb_rcv_packets);
    color(5,0);
    printf("Plugins :");
    reintialise_color();
    if (plugin_sendpackets_status == 1){
        printf(" SR plugin is connected\n\n");
    }
    else {
        printf(" SR plugin is Disconnected\n\n");
    }
    printf("---------------------------------------------\n");
	printf("---------------------------------------------\n\n");



}
