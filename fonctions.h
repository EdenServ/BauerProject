/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : fonctions.h
    Déscription : Ici est déclaré tout ce qui peut être utilisé dans tout les modules.

    */



#ifndef H_FONCTIONS
#define H_FONCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TEMP_FILE ".tmp/.tmp.db"
#define LOG_FILE "log/journal.log"


#define ANNEE_SEC 31536000.000     // un année en seconde : 3600*24*365 . un abonnement n'est valable qu'un an.
#define DEUX_SEMAINES 1296000.000   // 15 jours en seconde : 3600*24*15   durée maximale d'un emprunt est 15 jours.



#if defined (WIN32)   // pour marquer une pause après chaque fin de traitement d'un menu
    #define PAUSE system("pause");
#elif defined (linux)
    #define PAUSE printf("\nAppouiez sur une touche pour continuler ...\n");while(getchar()!='\n');getchar();
#endif



unsigned long taille_fichier(FILE *f);    // une fonction qui détermine la taille d'un fichier le corps de la fonctio est dans fonctions.c
int supprimer_ligne(unsigned int ligne,size_t taille, char *nomFichier,int i);
void copie_fichier(FILE *f1, FILE *f2);
void reordonner_selon_id(FILE *f, int i);
void lister_fichier(FILE *f, int i);
void journaliser(char *s);
void lire_espace(char *s);  // permet une saisie avec espaces;
void lire_chiffre(int *a);  // permet un controle au saisie des chiffres;


#endif
