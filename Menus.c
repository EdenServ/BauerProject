#include "Menus.h"
#include<stdio.h>
#include <stdlib.h>




int AfficheMenuPrincipal(void)
{
    int choix;
    printf("\t*** Gestion d'une bibliothèque ***\n");
    printf("\n\n##############################\n\n");
    printf("1-Gestion des livres.\n");
    printf("2-Gestion des abonnés.\n");
    printf("3-Quitter.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;

}

int AfficheMenuLivres(void)
{
    int choix;
    system("clear");
    printf("\tGestion des livres\n");
    printf("\n\n##############################\n\n");
    printf("1-Ajouter un livre.\n");
    printf("2-Supprimer un livre.\n");
    printf("3-Retourner au menu principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}

int AfficheMenuAbonnes(void)
{
    int choix;
    printf("\tGestion des Abonnés\n");
    printf("\n\n##############################\n\n");
    printf("1-Ajouter un abonné.\n");
    printf("2-Supprimer un abonné.\n");
    printf("3-Retourner au menu principal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}

