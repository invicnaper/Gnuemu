#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define couleur(param) printf("\033[$m",param)
void color(int couleurDuTexte,int couleurDeFond);
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
void set_color_to(int color){
    //for linux
	switch(color){
		case 34:
			printf("\033[34m",color);
			break;
		case 31:
			printf("\033[31m",color);
			break;
		case 32:
			printf("\033[32m",color);
			break;
		case 33:
			printf("\033[33m",color);
			break;
		case 36:
			printf("\033[36m",color);
			break;
		default:
			printf("\033[0m");
			break;
	}

}
void reintialise_color(){

	color(15,0);
}
void plugin(){
    printf("[");
	color(5,0);
	printf("Plugin");
	reintialise_color();
	printf("] : ");
}
void client_color(){
    printf("[");
	color(13,0);
	printf("Client");
	reintialise_color();
	printf("] : ");
}
void message_client(char the_message[]){
	printf("%s ...\n",the_message);
}
void message_server(char the_message[]){
    printf("[");
	color(14,0);
	printf("Server");
	reintialise_color();
	printf("] : ");
	printf("%s ...\n",the_message);
}
void message_info(char the_message[]){
	printf("[");
	color(11,0);
	printf("Info");
	reintialise_color();
	printf("] : ");
	printf("%s ...\n",the_message);
}
void ok(){
	printf("[");
	color(10,0);
	printf("OK");
	reintialise_color();
	printf("] : ");
}
void message_done(char the_message[]){
	ok();
	printf("%s .\n",the_message);
}
void message_error(char the_message[]){
	printf("[");
	color(12,0);
	printf("ERROR");
	reintialise_color();
	printf("] : ");
	printf("%s .\n",the_message);
}
void start_logs(){
	/*
	message_info("preparing the emu");
	message_info("Loading config");
	message_done("")
	*/
}
void console_header(){
    char console_gnu_version[] = "0.0.1";
    char console_gnu_type[] = "Windows";
	color(3,0);
	printf(" _____  _   _ _   _   _   ________  ____   _ \n");
	printf("|  __ \\| \\ | | | | | ( ) |  ___|  \\/  | | | |\n");
	printf("| |  \\/|  \\| | | | | |/  | |__ | .  . | | | |\n");
	printf("| | __ | . ` | | | |     |  __|| |\\/| | | | |\n");
	printf("| |_\\ \\| |\\  | |_| |     | |___| |  | | |_| |\n");
	printf(" \\____/\\_| \\_/\\___/      \\____/\\_|  |_/\\___/ \n");
	puts("");
	printf("[+]Author : naper\n");
	printf("[+]code in : C\n");
	printf("[+]Version %s For %s\n",console_gnu_version,console_gnu_type);
	reintialise_color();
	printf("---------------------------------------------\n");
	printf("---------------------------------------------\n");
}
void loading_emu(){
	console_header();

}
void color(int couleurDuTexte,int couleurDeFond)
{
        //for windows
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/*
colors Linux :

noir : 30

rouge : 31

vert : 32

jaune : 33

bleu : 34

magneta : 35

cyan : 36

blanc : 37

Colors windows:

0 : Noir
1 : Bleu foncé
2 : Vert foncé
3 : Turquoise
4 : Rouge foncé
5 : Violet
6 : Vert caca d'oie
7 : Gris clair
8 : Gris foncé
9 : Bleu fluo
10 : Vert fluo
11 : Turquoise
12 : Rouge fluo
13 : Violet 2
14 : Jaune
15 : Blanc


*/
