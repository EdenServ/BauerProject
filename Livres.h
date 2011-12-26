/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Livres.h
    Déscription : Les prototypes de fonctions, Maccros et définition des structures concernant la gesiont des livres.

    */


#include <stdio.h>

#define DB_LIVRE "db/livres.db"    // on définit le nom du fichier où seront mis les informations concernant les livres.


typedef struct livre {
  int id;
  int quantity;
  char titre[50];
  char ISBN[13];
} LIVRE;

void TraitementLivre(int choix);
void AjouterLivre(void);
void SupprimerLivre(void);
void InfosLivre(void);
void ListerLivres(void);
