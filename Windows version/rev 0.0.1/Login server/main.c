#include "gnu-utils/gnu-console.c"
#include "gnu-utils/gnu-config.c"
#include "gnu-other/gnu-arg.c"
#include "gnu-utils/gnu-mysql.c"
#include "gnu-login/gnu-loginparser.c"
#include "gnu-server/gnu-sockets.c"
#include "gnu-server/gnu-sockets-1.c"
#include "gnu-server/gnu-packets.c"
#include "gnu-utils/gnu-show-info.c"
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
int main(int argc , char** argv){

    args_enabled =0;
	do_args(argc, argv);
	if (load_all == 1){
		loading_emu();
		message_info("preparing the emu");
		read_config();
        connect_to_mysql();
        recup_pc_name();
        check_sr_plugin();
        //start_server();

	}
    return 0;

}
