//
// Created by jeanthom88 on 06/12/23.
//
#include "fonctions.h"

int main(void){
    char cmd[BUF_SIZE];
    int cmd_size;
    int pid;
    int status;

    write(1, WELCOME,strlen(WELCOME));
    write(1, EXIT, strlen(EXIT));
    write(1, enseash, strlen(enseash));

    while (1) {
        cmd_size = read(STDIN_FILENO, cmd, BUF_SIZE - 1); //reading entered command
        write(STDOUT_FILENO, cmd, strlen((cmd) - 1)); //printing entered command
        cmd[cmd_size - 1] = 0; //end of message
        pid = fork();
        if (pid != 0) {
            wait(&status);

        } else {
            execlp(cmd, cmd, (char *) NULL);
        }
        write(STDOUT_FILENO, enseash, strlen(enseash));
    }
    return 0;

        }