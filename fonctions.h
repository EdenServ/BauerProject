/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : fonctions.h
    Déscription :

    */


#include <stdio.h>
#include <string.h>
#include <time.h>

#define TEMP_FILE ".tmp/.tmp.db"
#define LOG_FILE "log/journal.log"

unsigned long taille_fichier(FILE *f);    // une fonction qui détermine la taille d'un fichier le corps de la fonctio est dans fonctions.c
int supprimer_ligne(unsigned int ligne,size_t taille, FILE *f,int i);
void copie_fichier(FILE *f1, FILE *f2);
void reordonner_selon_id(FILE *f, int i);
void lister_fichier(FILE *f, int i);
void journaliser(char *s);
