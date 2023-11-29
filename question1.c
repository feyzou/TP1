#include "fonctions.h"

int main(int argc, char** argv) {
    write(1, "Bienvenue dans le shell ENSEA.\n",31);
    write(1, "Pour quitter, tapez 'exit'; \n", 28);
    scanf("%s",sString);
    if (strcmp(sString, "exit")== 0)
    {
        exit(0);
    }
    else {
        write(1, "Erreur :( \t Veuillez réessayer.\n",32);
    }
}