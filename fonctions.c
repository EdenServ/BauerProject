/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : fonctions.c
    Déscription :

    */


#include "fonctions.h"




unsigned long taille_fichier(FILE *f)
{
    fseek(f,0,SEEK_END);
    return ftell(f);
}
