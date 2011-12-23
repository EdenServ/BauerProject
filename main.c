/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : main.c
    Déscription : Le fichier principal qui va contenir notre programme principal.

    */

#include <stdio.h>
#include <stdlib.h>
#include "Menus.h"
#include "Livres.h"
#include "Abonnes.h"

int main()
{
    int choix;
    choix = AfficheMenuPrincipal();
    switch(choix)
    {
        case 1:
            TraitementLivre(AfficheMenuLivres());  // Déclaré dans  Livres.h
            break;
        case 2:
            TraitementAbonnes(AfficheMenuAbonnes());
            break;
        case 3:
            printf("Bye bye :)\n");
            return 0;
        default :
            printf("Ce choix n'existe pas\n");


    }
    return 0;
}
