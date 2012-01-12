/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Menus.c
    Déscription : Ici seront déclaré le corps des fonctions qui vont s'occupper de l'affichache des menus et sous menus.

    */



#include "Menus.h"

void AfficheMenuAcceuil(void)
{
    time_t now;

    CLEAR_SCREEN
    time(&now);

    BLEU printf("%.24s\t Bauer Project",ctime(&now)); ENDC
    printf("\n\n\n");

    ROUGE
    printf("\t\t _______  _______  _______  ______   ___   _______ \n\
\t\t|       ||       ||       ||    _ | |   | |       |\n\
\t\t|    ___||  _____||    _  ||   | || |   | |_     _|\n\
\t\t|   |___ | |_____ |   |_| ||   |_|| |   |   |   |  \n\
\t\t|    ___||_____  ||    ___||    __ ||   |   |   |  \n\
\t\t|   |___  _____| ||   |    |   |  |||   |   |   |  \n\
\t\t|_______||_______||___|    |___|  |||___|   |___|  \n\
");ENDC
printf("\n\n\t\t%s    Appuiez sur une touche pour continuer ... %s",BOLD,ENDC_S);
    getchar();


    }

int AfficheMenuPrincipal(void)    // Menu Principal Affiché dans main.c : 4 choix possibles
{
    int choix;

    CLEAR_SCREEN

    time_t now;

    CLEAR_SCREEN
    time(&now);

    BLEU printf("%.24s\t Bauer Project",ctime(&now)); ENDC
    printf("\n\n\n");

    BLEU printf("\t#############################################################\n\n");
    CYAN printf("\t\t       *** Gestion d'une bibliothèque ***");
    BLEU printf("\n\n\t#############################################################\n\n"); ENDC
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 1  - Gestion des Livres.  %s|\t",BOLD,ENDC_S);
    printf("|%s 2  - Gestion des Abonnes. %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);

    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 3  - Gestion des Emprunts.%s|\t",BOLD,ENDC_S);
    printf("|%s 4  - Gestion des Bugs.    %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);


    printf("\t\t %s                           %s\n",UNDL,ENDC_S);
    printf("\t\t|%s 5  - Quittez.             %s|\n",BOLD,ENDC_S);
    printf("\t\t|%s                           %s|\n",UNDL,ENDC_S);


    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;

}

// Selon le choix de l'utilisateur on affiche l'un de ces 3 menus :


int AfficheMenuLivres(void)    //Premier sous menu : la gesion des livres 5 choix possibles; la valeur de retour est le choix de l'utilisateur
{
    int choix;

    CLEAR_SCREEN // on efface l'écran avant l'affichage du nouveau menu

    time_t now;

    CLEAR_SCREEN
    time(&now);

    BLEU printf("%.24s\t Bauer Project",ctime(&now)); ENDC
    printf("\n\n\n");

    BLEU printf("\t#############################################################\n\n");
    CYAN printf("\t\t       *** Gestion des livres ***");
    BLEU printf("\n\n\t#############################################################\n\n"); ENDC
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 1  - Ajouter un livre.    %s|\t",BOLD,ENDC_S);
    printf("|%s 2  - Supprimer un livre.  %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 3  - Infos sur les livres.%s|\t",BOLD,ENDC_S);
    printf("|%s 4  - Lister les livres.   %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);

    printf("\t\t %s                       %s\n",UNDL,ENDC_S);
    printf("\t\t|%s 5- Menu principal     %s|\n",BOLD,ENDC_S);
    printf("\t\t|%s                       %s|\n",UNDL,ENDC_S);

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// Deuxième sous menus : la gestion des abonnées, 5 choix possibles; la valeur de retour est le choix de l'utilisateur.

int AfficheMenuAbonnes(void)
{
    int choix;
    time_t now;

    CLEAR_SCREEN



    CLEAR_SCREEN
    time(&now);

    BLEU printf("%.24s\t Bauer Project",ctime(&now)); ENDC
    printf("\n\n\n");

    BLEU printf("\t#############################################################\n\n");
    CYAN printf("\t\t       *** Gestion des Abonnés ***");
    BLEU printf("\n\n\t#############################################################\n\n"); ENDC
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 1 - Ajouter un abonné.    %s|\t",BOLD,ENDC_S);
    printf("|%s 2 - Supprimer un abonné.  %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 3 - Infos sur les abonnés.%s|\t",BOLD,ENDC_S);
    printf("|%s 4 - Mettre à jour abonnés.%s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 5 -  Lister les abonnés.  %s|\t",BOLD,ENDC_S);
    printf("|%s 6 - Menu Principal.       %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);


    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// troisième sous menu : La gestion des emprunts : 4 choix possibles; retourne le choix de l'utilisateur


int AfficheMenuEmprunts(void)
{
    int choix;

    CLEAR_SCREEN

    BLEU printf("\t#############################################################\n\n");
    CYAN printf("\t\t       *** Gestion des Emprunts ***");
    BLEU printf("\n\n\t#############################################################\n\n"); ENDC
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 1- Demande d'emprunt.     %s|\t",BOLD,ENDC_S);
    printf("|%s 2- Retour d'un livre.     %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);
    printf(" %s                           %s\t",UNDL,ENDC_S);
    printf(" %s                           %s\n",UNDL,ENDC_S);
    printf("|%s 3- Infos sur les emprunts.%s|\t",BOLD,ENDC_S);
    printf("|%s 4- Menu Principal.        %s|\n",BOLD,ENDC_S);
    printf("|%s                           %s|\t",UNDL,ENDC_S);
    printf("|%s                           %s|\n",UNDL,ENDC_S);

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}


// quatrième menu: La gestion des bugs : .... choix possibles; retourne le choix de l'utilisateur.


int AfficheMenuBugs(void)
{
    int choix;

    CLEAR_SCREEN
    BLEU printf("\t#############################################################\n\n");
    CYAN printf("\t\t       *** Gestion de Bugs ***");
    BLEU printf("\n\n\t#############################################################\n\n"); ENDC
    printf(" %s                                          %s\t",UNDL,ENDC_S);
    printf(" %s                                          %s\n",UNDL,ENDC_S);
    printf("|%s 1- À propos de la gestion des livres.    %s|\t",BOLD,ENDC_S);
    printf("|%s 2- À propos de la gestion des abonnés.   %s|\n",BOLD,ENDC_S);
    printf("|%s                                          %s|\t",UNDL,ENDC_S);
    printf("|%s                                          %s|\n",UNDL,ENDC_S);
    printf(" %s                                          %s\t",UNDL,ENDC_S);
    printf(" %s                                          %s\n",UNDL,ENDC_S);
    printf("|%s 3- À propos de la gestion des emprunts.  %s|\t",BOLD,ENDC_S);
    printf("|%s 4  - Autre.                              %s|\n",BOLD,ENDC_S);
    printf("|%s                                          %s|\t",UNDL,ENDC_S);
    printf("|%s                                          %s|\n",UNDL,ENDC_S);

    printf("\t\t %s                                      %s\n",UNDL,ENDC_S);
    printf("\t\t|%s 5- Menu principal                    %s|\n",BOLD,ENDC_S);
    printf("\t\t|%s                                      %s|\n",UNDL,ENDC_S);


    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}

int AfficheMenuSeverty(void)
{
    int choix;

    CLEAR_SCREEN

    printf("\tQuel est le degré du bug ?\n");
    VERT printf("1-Amélioration.\n");
    JAUNE printf("2-Normal.\n");
    ROUGE printf("3-Crituque.\n");ENDC
    printf("4-Retournez au menu Princpal.\n");

    printf("\nTapez votre choix:\n");
    scanf("%d",&choix);
    return choix;
}
