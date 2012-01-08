/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Emprunts.h
    Déscription :

    */



#ifndef H_EMPRUNTS
#define H_EMPRUNTS

#include <stdio.h>
#include <time.h>
#include "fonctions.h"
#include "Abonnes.h"
#include "Livres.h"


#define DB_EMPRUNT "db/emprunts.db"


typedef struct {

    int id;         // l'identifiant de l'emprunt
    int idL;        // l'identifiant du livre emprunté
    int idA;        // l'identifiant de l'abonné qui a emprunté
    int etat;       // l'état de l'emprunt  1 actif, 0 non
    time_t date;    // la date de l'emprunt

} EMPRUNT;


void TraitementEmprunts(int choix);
void DemandeEmprunts(void);
void RetourEmprunts(void);
void InfoEmprunts(void);
void lier_abonne(ABONNE a, int i);
void decrementer_quantity(LIVRE l);
void retirer_abonne(int id, int idE);
void incrementer_quantity(int id);
int emprunt_possible(ABONNE a,LIVRE l);
ABONNE  obtenir_Abonne(int id);
LIVRE obtenir_Livre(int id);




#endif
