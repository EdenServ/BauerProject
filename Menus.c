/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Menus.c
    Déscription : Ici seront déclaré le corps des fonctions qui vont s'occupper de l'affichache des menus et sous menus.

    */



#include "Menus.h"
#include <stdio.h>
#include <stdlib.h>


int AfficheMenuPrincipal(void)    // Menu Principal Affiché dans main.c : 4 choix possibles
{
    int choix;
    printf("\t*** Gestion d'une bibliothèque ***\n");
    printf("\n\n##############################\n\n");
    printf("1-Gestion des livres.\n");
    printf("2-Gestion des abonnés.\n");
    printf("3-Gestion des emprunts.\n");
    printf("4-Quitter.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;

}

// Selon le choix de l'utilisateur on affiche l'un de ces 3 menus :


int AfficheMenuLivres(void)    //Premier sous menu : la gesion des livres 4 choix possibles; la valeur de retour est le choix de l'utilisateur
{
    int choix;
    system("clear");
    printf("\tGestion des livres\n");
    printf("\n\n##############################\n\n");
    printf("1-Ajouter un livre.\n");
    printf("2-Supprimer un livre.\n");
    printf("3-Infos sur un livre.\n");
    printf("4-Retourner au menu principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// Deuxième sous menus : la gestion des abonnées, 4 choix possibles; la valeur de retour est le choix de l'utilisateur.

int AfficheMenuAbonnes(void)
{
    int choix;
    printf("\tGestion des Abonnés\n");
    printf("\n\n##############################\n\n");
    printf("1-Ajouter un abonné.\n");
    printf("2-Supprimer un abonné.\n");
    printf("3-Infos sur un abonné.\n");
    printf("4-Retourner au menu principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// troisième sous menu : La gestion des emprunts : 4 choix possibles; retourne le choix de l'utilisateur


int AfficheMenuEmprunts(void)
{
    int choix;

    printf("\tGestion des Emprunts\n");
    printf("\n\n##############################\n\n");
    printf("1-Demande d'emprunt.\n");
    printf("2-Retour d'un livre.\n");
    printf("3-Infos sur les emprunts.\n");
    printf("4-Retournez au menu Principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
}
