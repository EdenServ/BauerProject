/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Emprunts.c
    Déscription :

    */


#include "Emprunts.h"
#include <stdio.h>


void TraitementEmprunts(int choix)
{
    switch(choix)
    {
        case 1:
            DemandeEmprunts();
            break;
        case 2:
            RetourEmprunts();
            break;
        case 3:
            InfoEmprunts();
            break;
        case 4:
            break;
        default:
            printf("Ce choix n'existe pas");
    }

    PAUSE


}


void DemandeEmprunts(void)
{


}


void RetourEmprunts(void)
{


}

void InfoEmprunts(void)
{



}
