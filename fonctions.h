/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : fonctions.h
    Déscription :

    */


#include <stdio.h>

#define TEMP_F ".tmp/.tmp.db"

unsigned long taille_fichier(FILE *f);    // une fonction qui détermine la taille d'un fichier le corps de la fonctio est dans fonctions.c
int supprimer_ligne(unsigned int ligne,size_t taille, FILE *f);
void copie_fichier(FILE *f1, FILE *f2);
void reordonner_selon_id(FILE *f, int i);
void lister_fichier(FILE *f, int i);
