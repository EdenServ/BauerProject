/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Abonnes.c
    Déscription : L'impémentation des fonctions relatives la gestion des Abonnés.

    */


/* TODO :

    - Ajouter plus d'informations concernant les abonnés
    - Controle saisie : numéro de téléphone, cin


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
            MiseAJourAbonne();
            break;
        case 5:
            ListerAbonnes();
            break;
        case 6:
            break;
        default :
            printf("Ce choix n'existe pas");
    }

    PAUSE
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
        {
            abonne.id=1;
        }

            // Initialisation
            abonne.emprunts[0]=0;
            abonne.emprunts[1]=0;
            abonne.etat=1;

        printf("Identifiant : %d \n",abonne.id);
        while(getchar()!='\n');
        printf("Donner le nom de l'abonné\n");
        lire_espace(abonne.nom,sizeof(abonne.nom));
        printf("Donner le prénom de l'abonné\n");
        lire_espace(abonne.prenom,sizeof(abonne.prenom));
        printf("Donner le num de téléphone de l'abonné\n");
        lire_chiffre(&abonne.telephone);
        printf("Donner l'email de l'abonné\n");
        lire_email(abonne.email);
        printf("Donner le num de CIN de l'abonné\n");
        lire_cin(abonne.cin);

        printf("%d %s  %s %s %d  %s %d %d %d\n",abonne.id,abonne.nom,abonne.prenom,abonne.cin,abonne.telephone,abonne.email,abonne.emprunts[0],abonne.emprunts[1],abonne.etat);

        time(&abonne.date);
        fwrite(&abonne,sizeof(abonne),1,fp);   // ecriture binaire
        printf("Abonné ajouté avec succès\n!");
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
            if(possible_supp(id,2))
            {
                if(!supprimer_ligne(id,sizeof(ABONNE),DB_ABONNE,2))
                {
                    printf("Abonné supprimé avec succès !\n");
                }
                else
                printf("Erreur lors de la suppression de l'abonnée !\n");
            }
        }else
            printf("Cet abonné n'existe pas dans la base de donnée.\n");
        //fclose(fp);
    }else
        printf("Erreur d'ouverture du fichier.\n");


}


void InfosAbonnes(void)
{
    FILE *f = NULL;
    ABONNE a;
    int id;
    char cin[8];


    f = fopen(DB_ABONNE,"rb");
    if(f != NULL)
    {
        printf("Donner l'id ou le numéro de CIN de l'abonné à rechercher:\n");
        printf("l'ID (sinon zéro): ");
        scanf("%d",&id);
        printf("l'CIN de l'abonné (zéro sinon): ");
        lire_cin(cin);

        while(fread(&a,sizeof(ABONNE),1,f)!=0)
        {
            if(a.id == id || strcmp(a.cin,cin) == 0)
                printf("%d %s  %s %s %d %s  %s %d %d\n",a.id,a.nom,a.prenom,a.cin,a.telephone,a.email,ctime(&a.date),a.emprunts[0],a.emprunts[1]);
        }
        fclose(f);
    }else
    {
        printf("Problème d'accès à la base de donnée.\n");
    }



}


void ListerAbonnes(void)
{
    FILE *f = NULL;


    f = fopen(DB_ABONNE,"rb");
    if(f != NULL)
    {


        if(taille_fichier(f))
            lister_fichier(f,2); //  2 c'est pour les abonnés !
        else
            printf("Fichier vide\n");
        fclose(f);
    }else
        printf("Erreur lors de l'ouverture de la base de donnée des abonnés !\n");

}

void MiseAJourAbonne(void)    // cette fonction met à jour un abonnée en cas de renouvellement d'abonnement.
{
    FILE *f = NULL;
    int id = 0,d=0;
    ABONNE a,aux;
    time_t now;
    f = fopen(DB_ABONNE,"rb+");
    if(f != NULL)
    {
        printf("Donner l'identifiant de l'abonné :");
        scanf("%d",&id);
        d=taille_fichier(f)-id*sizeof(ABONNE);
        if(d<0)
        {
            printf("Aucun abonné avec cet id.\n");
        }else
        {
            fseek(f,sizeof(ABONNE)*(id-1),SEEK_SET);
            fread(&a,sizeof(ABONNE),1,f);
            fseek(f,-sizeof(ABONNE),SEEK_CUR);
            time(&now);
            if(difftime(now,a.date) <= ANNEE_SEC)
            {
                printf("L'abonnement n'est pas encore fini !\n");
            }else
            {
                    printf("Voulez vous mettre à jour l'email actuel? (%s): (zéro sinon)\n",a.email);
                    lire_email(aux.email);
                    printf("Voulez vous mettre à jour le numéro de téléphone ? (%d) : (zéro sinon)\n",a.telephone);
                    lire_chiffre(&aux.telephone);
                    if(strcmp(aux.cin,"0")!=0)
                        strcpy(a.cin,aux.cin);
                    if(aux.telephone != 0)
                        a.telephone = aux.telephone;
                    time(&a.date);
                    fwrite(&a,sizeof(ABONNE),1,f);
                    printf("Abonnement mis à jour.\n");
            }
        }
        fclose(f);
    }else
        printf("Erreur lors de l'ouverture de la base de donnée des abonnés");
}
