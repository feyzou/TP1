#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char sString [100];
#define WELCOME "$ ./enseash \nBienvenue dans le shell ENSEA.\n"
#define EXIT "Pour quitter, tapez 'exit'. \n"
#define enseash "$enseash %\n"
#define BYEBYE "Bye bye...\n"
#define BYEBYE_ctrl_plus_d "Bye bye Ctrl+d...\n"


#define BUF_SIZE 128
#define REGULAR_PROMPT "enseash % "

