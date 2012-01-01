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
            InfosLivre();
            break;
        case 4:
            ListerLivres();
            break;
        case 5:
            break;
        default :
            printf("Ce choix n'existe pas\n");

    }
}

void AjouterLivre(void)
{
    LIVRE livre,aux;
    FILE  *fp=NULL;
    fp = fopen(DB_LIVRE,"ab+");
    if(fp != NULL)
    {
        fseek(fp,0,SEEK_END);
        if(ftell(fp)!=0)
        {
            fseek(fp,-sizeof(LIVRE),SEEK_CUR);
            fread(&aux,sizeof(LIVRE),1,fp);
            livre.id=aux.id+1;  //auto incrementation de l'id
        }
        else
            livre.id=1;

        printf("%d \n",livre.id);
        printf("Donner le nom du livre\n");
        scanf("%s",livre.titre);
        printf("Donner l'ISBN du livre\n");
        scanf("%s",livre.ISBN);
        printf("Donner la quantité de livres\n");
        scanf("%d",&livre.quantity);
        fwrite(&livre,sizeof(livre),1,fp);   // ecriture binaire
        printf("Livre ajouté avec succès\n!");
        fclose(fp);
    }else
    {
        printf("Problème d'accès à la base de donnée\n");
    }


}



void SupprimerLivre(void)
{


    unsigned int id;
    FILE *fp=NULL;
    long taille=0;

    printf("Donner l'id du livre à effacer de la base de donnée:\n");
    scanf("%u",&id);

    fp = fopen(DB_LIVRE,"rb");
    if(fp != NULL)
    {
        taille = taille_fichier(fp);
        fclose(fp);
        if(taille>= sizeof(LIVRE)*id)
        {
            if(!supprimer_ligne(id,sizeof(LIVRE),DB_LIVRE,1))
            {
                printf("Livre supprimé avec succès !\n");
            }
            else
                printf("Erreur lors de la suppression du fichier !\n");
        }else
            printf("Ce livre n'existe pas dans la base de donnée.\n");
    }else
        printf("Erreur d'ouverture du fichier.\n");


}


void InfosLivre(void)
{




}

void ListerLivres(void)
{

    FILE *f = NULL;

    f = fopen(DB_LIVRE,"rb");
    if(f != NULL)
    {
        lister_fichier(f,1);
        fclose(f);
    }else
        printf("Erreur lors de l'ouverture de la base de donnée des livres !\n");
}
