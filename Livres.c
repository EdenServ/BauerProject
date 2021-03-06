/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Livres.c
    Déscription : Dans ce fichier ont été implémenté les fonctions de la gestion des livres.

    */

/* TODO

    - Ajouter plus d'infros dans la strucutre du livre : maison d'édition, auteur
    - Recherche dans les livres plus précise.
    - Lecture des titres avec espaces

*/

#include "Livres.h"
#include "fonctions.h"



void TraitementLivres(int choix)
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

     PAUSE
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

        printf("Identifiant : %d \n",livre.id);
        FLUSHH
        printf("Donner le nom du livre\n");
        lire_espace(livre.titre,sizeof(livre.titre));
        printf("Donner le nom de l'auteur:\n");
        lire_espace(livre.auteur,sizeof(livre.auteur));
        printf("Donner la maison d'édition du livre :\n");
        lire_espace(livre.edition, sizeof(livre.edition));
        printf("Donner l'ISBN du livre\n");
        lire_espace(livre.ISBN,sizeof(livre.ISBN));
        printf("Donner la quantité de livres\n");
        lire_chiffre(&livre.quantity);
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
            if(possible_supp(id,1))
            {
                if(!supprimer_ligne(id,sizeof(LIVRE),DB_LIVRE,1))
                {
                    printf("Livre supprimé avec succès !\n");
                }
                else
                    printf("Erreur lors de la suppression du fichier !\n");
            }
        }else
            printf("Ce livre n'existe pas dans la base de donnée.\n");
       fclose(fp);
    }else
        printf("Erreur d'ouverture du fichier.\n");


}


void InfosLivre(void)
{
    FILE *f = NULL;
    LIVRE l,laux;

    f = fopen(DB_LIVRE,"rb");
    if(f != NULL)
    {
        printf("Entrez les informations du livre à rechercher:\n");
        printf("l'ID (sinon zéro): ");
        scanf("%d",&laux.id);
        printf("l'ISBN du livre (zéro sinon): ");
        lire_isbn(laux.ISBN);
        printf("Donner le titre (zéro sinon):\n");
        lire_espace(laux.titre,sizeof(l.titre));
        printf("Donner l'auteur du livre (zéro sinon):\n");
        lire_espace(laux.auteur,sizeof(l.auteur));
        printf("Donner la maison d'edition (zéro sinon):\n");
        lire_espace(laux.edition,sizeof(l.edition));

        while(fread(&l,sizeof(LIVRE),1,f)!=0)
        {
            if(l.id == laux.id || strcmp(l.ISBN,laux.ISBN)==0 || strcmp(l.titre,laux.titre) == 0 || strcmp(l.auteur,laux.auteur) == 0 || strcmp(l.edition,laux.edition) == 0 )
                printf("%d %s %s %s %s %d\n",l.id,l.titre,l.auteur,l.edition,l.ISBN,l.quantity);
        }

        fclose(f);
    }




}

void ListerLivres(void)
{

    FILE *f = NULL;

    f = fopen(DB_LIVRE,"rb");
    if(f != NULL)
    {   if(taille_fichier(f))
            lister_fichier(f,1);
        else
            printf("Fichier vide\n");
        fclose(f);
    }else
        printf("Erreur lors de l'ouverture de la base de donnée des livres !\n");
}
