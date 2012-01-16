/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Abonnes.h
    Déscription : Les prototypes de fonctions, Maccros et définition des structures concernant la gesiont des abonnés.

    */

#ifndef H_ABONNES
#define H_ABONNES

#include <stdio.h>
#include <time.h>

#define DB_ABONNE "db/abonnes.db"

typedef struct
{
    int id;
    char nom[10];
    char prenom[10];
    char cin[8];
    int telephone;
    char email[50];
    int etat;
    time_t date;
    int emprunts[2];

} ABONNE;

void TraitementAbonnes(int choix);
void AjouterAbonne(void);
void SupprimerAbonne(void);
void InfosAbonnes(void);
void ListerAbonnes(void);
void MiseAJourAbonne(void);

#endif
