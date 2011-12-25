/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Livres.c
    Déscription : Dans ce fichier seront déclaré les fonctions de la gestion des livres.

    */

#include "Livres.h"
#include "fonctions.h"



void TraitementLivre(int choix)
{

    switch(choix)
    {
        case 1:
            AjouterLivre();
            break;
        case 2:
            SupprimerLivre();
            break;
        case 3:
            break;
        default :
            printf("Ce choix n'existe pas\n");

    }
}

void AjouterLivre(void)
{
    LIVRE livre,aux;
    int quantity = 0;
    FILE  *fp=NULL;

    fp = fopen(DB_LIVRE,"ab");
    if(fp != NULL)
    {
        if(taille_fichier(fp)!=0)
        {
            fseek(fp,-sizeof(LIVRE),SEEK_CUR);
            fread(&aux,sizeof(LIVRE),1,fp);
            livre.id=aux.id+1;  //auto incrementation de l'id
        }
        else
            livre.id=1;

        printf("Donner le nom du livre\n");
        scanf("%s",livre.titre);
        printf("Donner l'ISBN du livre\n");
        scanf("%s",livre.ISBN);
        printf("Donner la quantité de livres\n");
        scanf("%d",&quantity);

        fwrite(&livre,sizeof(LIVRE),1,fp);   // ecriture binaire
        printf("Livre ajouté avec succès\n!");
        fclose(fp);
    }else
    {
        printf("Problème d'accès à la base de donnée\n");
    }


}



void SupprimerLivre(void)
{



}
