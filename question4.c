#include "fonctions.h"

int main() {
    char cmd[256];
    char prompt[] = "enseash % ";
    char exitPrompt[] = "enseash [exit:";
    char signPrompt[] = "enseash [sign:";
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
        if (strcmp(cmd,"exit") == 0) { //corresponds to exit command
            write(STDOUT_FILENO, BYEBYE, strlen(BYEBYE));
            break;
        }
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

        while (1) {

            ssize_t bytesRead = read(STDIN_FILENO, cmd, sizeof(cmd) - 1);
            cmd[bytesRead - 1] = '\0';  // Remove newline character

            // If the commande typed by the user is equal to "exit", we exit the programm
            if (strcmp(cmd, "exit") == 0) {
                exit(0);
            }

            pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                // Child process
                execlp(cmd, cmd, (char *)NULL);
                perror("execlp");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                waitpid(pid, &status, 0);
                if (WIFEXITED(status)) {
                    write(STDOUT_FILENO, exitPrompt, sizeof(exitPrompt) - 1);
                    dprintf(STDOUT_FILENO, "%d", WEXITSTATUS(status));
                    write(STDOUT_FILENO, "] %% ", 5);
                } else if (WIFSIGNALED(status)) {
                    write(STDOUT_FILENO, signPrompt, sizeof(signPrompt) - 1);
                    dprintf(STDOUT_FILENO, "%d", WTERMSIG(status));
                    write(STDOUT_FILENO, "] %% ", 5);
                }
            }
        }


    }
    return 0;
    }

