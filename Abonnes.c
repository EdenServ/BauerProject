/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Abonnes.c
    Déscription : Les prototypes de fonctions, Maccros et définition des structures relatives la gestion des Abonnés.

    */


#include "Abonnes.h"
#include "fonctions.h"


void TraitementAbonnes(int choix)
{
    switch(choix)
    {
        case 1:
            AjouterAbonne();
            break;
        case 2:
            SupprimerAbonne();
            break;
        case 3:
            InfosAbonnes();
            break;
        case 4:
            ListerAbonnes();
            break;
        case 5:
            break;
        default :
            printf("Ce choix n'existe pas");
    }
}


void AjouterAbonne(void)
{
ABONNE abonne,aux;
    FILE  *fp=NULL;
    fp = fopen(DB_ABONNE,"ab+");
    if(fp != NULL)
    {
        fseek(fp,0,SEEK_END);
        if(ftell(fp)!=0)
        {
            fseek(fp,-sizeof(ABONNE),SEEK_CUR);
            fread(&aux,sizeof(ABONNE),1,fp);
            abonne.id=aux.id+1;  //auto incrementation de l'id
        }
        else
            abonne.id=1;

        //printf("%d \n",abonne.id);
        printf("Donner le nom de l'abonné\n");
        scanf("%s",abonne.nom);
        printf("Donner le prénom de l'abonné\n");
        scanf("%s",abonne.prenom);
        printf("Donner le num de CIN de l'abonné\n");
        scanf("%d",&abonne.cin);
        printf("Donner le num de téléphone de l'abonné\n");
        scanf("%d",&abonne.telephone);
        printf("Donner l'email de l'abonné\n");
        scanf("%s",abonne.email);
        time(&abonne.date);
        fwrite(&abonne,sizeof(abonne),1,fp);   // ecriture binaire
        printf("Livre ajouté avec succès\n!");
        fclose(fp);
    }else
    {
        printf("Problème d'accès à la base de donnée\n");
    }


}

void SupprimerAbonne(void)
{
    unsigned int id;
    FILE *fp=NULL;
    long taille=0;

    printf("Donner l'id de l'abonné à effacer de la base de donnée:\n");
    scanf("%u",&id);

    fp = fopen(DB_ABONNE,"rb");
    if(fp != NULL)
    {
        taille = taille_fichier(fp);
        fclose(fp);
        if(taille>= sizeof(ABONNE)*id)
        {
            if(!supprimer_ligne(id,sizeof(ABONNE),DB_ABONNE,2))
            {
                printf("Livre supprimé avec succès !\n");
            }
            else
                printf("Erreur lors de la suppression de l'abonnée !\n");
        }else
            printf("Cet abonné n'existe pas dans la base de donnée.\n");
    }else
        printf("Erreur d'ouverture du fichier.\n");


}


void InfosAbonnes(void)
{


}


void ListerAbonnes(void)
{
FILE *f = NULL;

    f = fopen(DB_ABONNE,"rb");
    if(f != NULL)
    {
        lister_fichier(f,2); //  2 c'est pour les abonnés !
        fclose(f);
    }else
        printf("Erreur lors de l'ouverture de la base de donnée des livres !\n");

}
