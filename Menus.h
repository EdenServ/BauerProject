/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Menus.h
    Déscription : Ici On trouvera les prototypes des fonctions de menus.

    */


#ifndef H_MENUS
#define H_MENUS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined (WIN32)             // Nettoyage de l'écran lors du passage d'un menu à l'autre selon l'os
    #define CLEAR_SCREEN system("cls");
#elif defined (linux)
    #define CLEAR_SCREEN system("clear");
#endif

#define BLEU printf("\033[94m");
#define BLANC printf("\033[47m");
#define ROUGE printf("\033[91m");
#define CYAN printf("\033[96m");
#define DARKCYAN printf("\033[36m");
#define B_MAGENTA printf("\033[46m");
#define JAUNE printf("\033[93m");
#define VERT printf("\033[92m");
#define ENDC printf("\033[0m");
#define BOLD "\033[1m"
#define ENDC_S "\033[0m"
#define UNDL "\033[4m"


void AfficheMenuAcceuil(void);
int AfficheMenuPrincipal(void);
int AfficheMenuLivres(void);
int AfficheMenuAbonnes(void);
int AfficheMenuEmprunts(void);
int AfficheMenuBugs(void);
int AfficheMenuSeverty(void);

#endif
