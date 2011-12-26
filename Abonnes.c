/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Abonnes.c
    Déscription : Les prototypes de fonctions, Maccros et définition des structures relatives la gestion des Abonnés.

    */


#include "Abonnes.h"



void TraitementAbonnes(int choix)
{
    switch(choix)
    {
        case 1:
            AjouterAbonne();
            break;
        case 2:
            SupprimerAbonne();
            break;
        case 3:
            InfosAbonnes();
            break;
        case 4:
            ListerAbonnes();
            break;
        case 5:
            break;
        default :
            printf("Ce choix n'existe pas");
    }
}


void AjouterAbonne(void)
{


}

void SupprimerAbonne(void)
{



}


void InfosAbonnes(void)
{


}


void ListerAbonnes(void)
{


}
