/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Menus.c
    Déscription : Ici seront déclaré le corps des fonctions qui vont s'occupper de l'affichache des menus et sous menus.

    */



#include "Menus.h"


int AfficheMenuPrincipal(void)    // Menu Principal Affiché dans main.c : 4 choix possibles
{
    int choix;

    CLEAR_SCREEN

    printf("\t\033[94m*** Gestion d'une bibliothèque ***\033[0m\n");
    printf("\n\n##############################\n\n");
    printf("1-Gestion des livres.\n");
    printf("2-Gestion des abonnés.\n");
    printf("3-Gestion des emprunts.\n");
    printf("4-Gestion des Bugs.\n");
    printf("5-Quitter.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;

}

// Selon le choix de l'utilisateur on affiche l'un de ces 3 menus :


int AfficheMenuLivres(void)    //Premier sous menu : la gesion des livres 5 choix possibles; la valeur de retour est le choix de l'utilisateur
{
    int choix;

    CLEAR_SCREEN // on efface l'écran avant l'affichage du nouveau menu

    printf("\tGestion des livres\n");
    printf("\n\n##############################\n\n");
    printf("1-Ajouter un livre.\n");
    printf("2-Supprimer un livre.\n");
    printf("3-Infos sur un livre.\n");
    printf("4-Lister les livres.\n");
    printf("5-Retourner au menu principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// Deuxième sous menus : la gestion des abonnées, 5 choix possibles; la valeur de retour est le choix de l'utilisateur.

int AfficheMenuAbonnes(void)
{
    int choix;

    CLEAR_SCREEN

    printf("\tGestion des Abonnés\n");
    printf("\n\n##############################\n\n");
    printf("1-Ajouter un abonné.\n");
    printf("2-Supprimer un abonné.\n");
    printf("3-Infos sur un abonné.\n");
    printf("4-Mettre à jour un abonné.\n");
    printf("5-Lister les abonnés.\n");
    printf("6-Retourner au menu principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// troisième sous menu : La gestion des emprunts : 4 choix possibles; retourne le choix de l'utilisateur


int AfficheMenuEmprunts(void)
{
    int choix;

    CLEAR_SCREEN

    printf("\tGestion des Emprunts\n");
    printf("\n\n##############################\n\n");
    printf("1-Demande d'emprunt.\n");
    printf("2-Retour d'un livre.\n");
    printf("3-Infos sur les emprunts.\n");
    printf("4-Retournez au menu Principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// quatrième menu: La gestion des bugs : .... choix possibles; retourne le choix de l'utilisateur.


int AfficheMenuBugs(void)
{
    int choix;

    CLEAR_SCREEN

    printf("\tGestion des Bugs\n");
    printf("\n\n##############################\n\n");
    printf("1-Soumettre un bug à propos de la gestion des livres.\n");
    printf("2-Soumettre un bug à propos de la gestion des abonnés.\n");
    printf("3-Soumettre un bug à propos de la gestion des emprunts.\n");
    printf("4-Soumettre un bug : Autre.\n");
    printf("5-Retournez au menu Princpal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}

int AfficheMenuSeverty(void)
{
    int choix;

    CLEAR_SCREEN

    printf("\tQuel est le degré du bug ?\n");
    printf("1-Amélioration.\n");
    printf("2-Normal.\n");
    printf("3-Crituque.\n");
    printf("4-Retournez au menu Princpal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}
