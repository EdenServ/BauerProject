#include "Livres.h"
#include <stdio.h>


void TraitementLivre(int choix)
{

    switch(choix)
    {
        case 1:
            AjouterLivre();
            break;
        case 2:
            //SupprimerLivre();
            break;
        case 3:
            break;
        default :
            printf("Ce choix n'existe pas\n");

    }
}

void AjouterLivre(void)
{
    LIVRE livre;
    int quantity=0;
    FILE  *fp=NULL;

    fp = fopen("livres.txt","a");
    if(fp != NULL)
    {
        printf("Donner l'identifiant du livre\n");
        scanf("%d",&livre.id);
        printf("Donner le nom du livre\n");
        scanf("%s",livre.titre);
        printf("Donner l'ISBN du livre\n");
        scanf("%s",livre.ISBN);
        printf("Donner la quantité de livres\n");
        scanf("%d",&quantity);

        fprintf(fp,"%d %s %s %d\n",livre.id,livre.titre,livre.ISBN,quantity);
        printf("Livre ajouté avec succès\n!");
        fclose(fp);
    }else
    {
        printf("Problème d'accès à la base de donnée\n");
    }


}
