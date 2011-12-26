/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Abonnes.h
    Déscription :

    */

#include <stdio.h>

#define DB_ABONNE "db/abonnes.db"

typedef struct
{
    char nom[10];
    char prenom[10];
    unsigned int id;
} ABONNE;

void TraitementAbonnes(int choix);
void AjouterAbonne(void);
void SupprimerAbonne(void);
void InfosAbonnes(void);
void ListerAbonnes(void);
