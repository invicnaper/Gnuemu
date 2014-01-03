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
//----------------------------
int load_all = 0;
char gnu_version [] = "0.0.1";
int args_enabled = 1;
//----------------------------
void help_command(){
	console_header();
	puts("~~commands for Gnu'emu : \n");
	puts("[+] -start : Starting the emu");
	puts("[+] -config : check if the config exist");
	puts("[+] -mysql : check if the mysql db exist");
	puts("[+] -testenv : test the environement , to load the emu");
	puts("[+] -man - command : show informations about the command");
	puts("------------------------------------------------------");
	printf("                 GNU EMU VERSION %s               \n",gnu_version);
	puts("------------------------------------------------------");
	puts("~~Sub command :");
	puts("[+] -start -debug : start on debug mode");
	puts("[+] -config -show : read and show the config");
	puts("[+] -mysql -newtable -[name of the table] : create new table");
	puts("[+] -mysql -list : list all informations about tables and DB");
	puts("[+] -testenv -send : send packets");
	puts("------------------------------------------------------");
	printf("                 GNU EMU VERSION %s               \n",gnu_version);
	puts("------------------------------------------------------");
}
void config_command(){
	console_header();
	read_config();
}
void type_command(int argc, char** argv){
	//printf("your argv is %s : ",argv[1]);
	int cmd_exist = 0;
	switch(argc){
		case 2:
			if (strcmp(argv[1],"-start")==0){
			cmd_exist = 1;
			load_all = 1;
			}
			if (strcmp(argv[1],"--help")==0){
			cmd_exist = 1;
			help_command();
			}
			if (strcmp(argv[1],"-config")==0){
			cmd_exist = 1;
			config_command();

			}
			if (!cmd_exist){
			console_header();
			message_error("Command doesn't exist");
			printf("[%s] is not a valid command , --help for help\n",argv[1]);
			}
		break;
}

}
void check_args(int argc, char** argv){

	if (argc < 2){
		console_header();
		message_error("Gnu emu need arguments");
		exit(1);
	}
	else {
		type_command(argc,argv);
	}

}
void do_args(int argc , char** argv){
    if (!args_enabled){
        load_all = 1;
    }
    else{
        check_args(argc, argv);
    }


}
