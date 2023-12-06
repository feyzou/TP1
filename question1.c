#include "fonctions.h"

int main(int argc, char** argv) {
    write(1, WELCOME,strlen(WELCOME));
    write(1, EXIT, strlen(EXIT));
    scanf("%s",sString);
    if (strcmp(sString, "exit")== 0)
    {
        exit(0);
    }
    else {
        write(1, "Erreur :( \t Veuillez réessayer.\n",32);
    }
}