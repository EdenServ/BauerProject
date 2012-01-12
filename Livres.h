/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Livres.h
    Déscription : Les prototypes de fonctions, Maccros et définition des structures concernant la gesiont des livres.

    */


#ifndef H_LIVRES
#define H_LIVRES

#include <stdio.h>

#define DB_LIVRE "db/livres.db"    // on définit le nom du fichier où seront mis les informations concernant les livres.


typedef struct {
  int id;
  int quantity;
  char titre[50];
  char ISBN[17];
  char edition[20];
  char auteur[20];
} LIVRE;

void TraitementLivres(int choix);
void AjouterLivre(void);
void SupprimerLivre(void);
void InfosLivre(void);
void ListerLivres(void);

#endif
