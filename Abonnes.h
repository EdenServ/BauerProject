/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Abonnes.h
    Déscription :

    */

#include <stdio.h>
#include <time.h>

#define DB_ABONNE "db/abonnes.db"

typedef struct
{
    int id;
    char nom[10];
    char prenom[10];
    int cin;
    int telephone;
    char email[50];
    time_t date;

} ABONNE;

void TraitementAbonnes(int choix);
void AjouterAbonne(void);
void SupprimerAbonne(void);
void InfosAbonnes(void);
void ListerAbonnes(void);
