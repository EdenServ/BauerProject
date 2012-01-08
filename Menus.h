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

#if defined (WIN32)             // Nettoyage de l'écran lors du passage d'un menu à l'autre selon l'os
    #define CLEAR_SCREEN system("cls");
#elif defined (linux)
    #define CLEAR_SCREEN system("clear");
#endif


int AfficheMenuPrincipal(void);
int AfficheMenuLivres(void);
int AfficheMenuAbonnes(void);
int AfficheMenuEmprunts(void);
int AfficheMenuBugs(void);
int AfficheMenuSeverty(void);

#endif
