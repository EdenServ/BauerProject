/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : Emprunts.c
    Déscription :

    */


#include "Emprunts.h"
#include "fonctions.h"
#include "Abonnes.h"
#include "Livres.h"



void TraitementEmprunts(int choix)
{
    switch(choix)
    {
        case 1:
            DemandeEmprunts();
            break;
        case 2:
            RetourEmprunts();
            break;
        case 3:
            InfoEmprunts();
            break;
        case 4:
            ListerEmprunts();
            break;
        case 5:
            break;
        default:
            printf("Ce choix n'existe pas");
    }

    PAUSE


}


void DemandeEmprunts(void)
{
    FILE *f=NULL;
    ABONNE ab;
    LIVRE li;
    EMPRUNT em;
    int ida,idl;

    f = fopen(DB_EMPRUNT,"ab");
    if(f != NULL)
    {
        fseek(f,-sizeof(EMPRUNT),SEEK_END);
        fread(&em,sizeof(EMPRUNT),1,f);
        if(em.id != 0)
        {
            em.id++;
        }else
            em.id = 1;

        printf("Donner l'identifiant de l'abonné qui demande l'emprunt :\n");
        scanf("%d",&ida);
        printf("Donner l'identifiant du livre à emprunter :\n");
        scanf("%d",&idl);
        ab = obtenir_Abonne(ida);
        li = obtenir_Livre(idl);
        if(!ab.id)
        {
            printf("Aucun abonné avec ce nom n'existe !\n");
            return;
        }else if(!li.id)
        {
            printf("Aucun livre avec cet identifiant\n");
            return;
        }
         printf("OK\n");
         printf("%d %s | %d %s\n",ab.id,ab.nom,li.id,li.titre);
         if(!emprunt_possible(ab,li))
         {
             lier_abonne(ab,em.id);
             decrementer_quantity(li);
             em.idA = ab.id;
             em.idL = li.id;
             em.etat = 1;
             time(&em.date);
             fwrite(&em,sizeof(EMPRUNT),1,f);

             printf("Emprunt ajouté avec succès !\n");
         }
    }
         fclose(f);



}


void RetourEmprunts(void)
{
    FILE *f = NULL;
    EMPRUNT e;
    int id,idA,idL;

    f = fopen(DB_EMPRUNT,"rb+");




    if(f != NULL)
    {
        printf("Donner l'identifiant de l'emprunt\n");
        lire_chiffre(&id);


            if(sizeof(EMPRUNT)*id<taille_fichier(f))
            {
                fseek(f,sizeof(EMPRUNT)*(id-1),SEEK_SET);
                fread(&e,sizeof(EMPRUNT),1,f);
                idA = e.idA;
                idL = e.idL;
                e.etat = 0;
                retirer_abonne(idA,id);       // TODO
                incrementer_quantity(idL);  // TODO
                fseek(f,-sizeof(EMPRUNT),SEEK_CUR);
                fwrite(&e,sizeof(EMPRUNT),1,f);
                printf("Emprunt retiré avec succès !\n");
            }else
            {
                printf("Aucun emprunt n'exite sous cet identifiant !");
            }


        fclose(f);
    }else
        printf("Erreur lors de l'ouverture de la base de donnée !\n");


}

void InfoEmprunts(void)
{
    FILE *f = NULL;
    EMPRUNT em;

    f = fopen(DB_EMPRUNT,"rb");
    if(f != NULL)
    {
        while(fread(&em,sizeof(EMPRUNT),1,f)!=0)
        {
            printf("%d %d %d %d %s\n",em.id,em.idL,em.idA,em.etat,ctime(&em.date));
        }

        fclose(f);
    }else
        printf("Proclème lors de l'accès à la base de données des emprunts\n");


}

void ListerEmprunts(void)
{

    FILE *f = NULL;

    f = fopen(DB_EMPRUNT,"rb");
    if(f != NULL)
    {   if(taille_fichier(f))
            lister_fichier(f,3);
        else
            printf("Fichier vide\n");
        fclose(f);
    }else
        printf("Erreur lors de l'ouverture de la base de donnée des livres !\n");



}

ABONNE  obtenir_Abonne(int id)
{
    FILE *f = NULL;
    ABONNE a;
    int t;
    f = fopen(DB_ABONNE,"rb");
    if(f!= NULL)
    {
        t = taille_fichier(f)-sizeof(ABONNE)*id;
        if(t<0)
        {
            fclose(f);
            a.id = 0;


        }else
        {
            fseek(f,sizeof(ABONNE)*(id-1),SEEK_SET);
            fread(&a,sizeof(ABONNE),1,f);
            fclose(f);
        }

    }else
        {
            printf("Erreur lors de l'accès à la base de données \n");
            a.id=0;
        }
    return a;

}

LIVRE   obtenir_Livre(int id)
{
    FILE *f = NULL;
    LIVRE l;
    int t;
    f = fopen(DB_LIVRE,"rb");
    if(f!= NULL)
    {
        t = taille_fichier(f)-sizeof(LIVRE)*id;
        if(t<0)
        {
            fclose(f);
            l.id = 0;


        }else
        {
            fseek(f,sizeof(LIVRE)*(id-1),SEEK_SET);
            fread(&l,sizeof(LIVRE),1,f);
            fclose(f);
        }

    }else
        {
            printf("Erreur lors de l'accès à la base de données \n");
            l.id=0;
        }
    return l;
}


int emprunt_possible(ABONNE a,LIVRE l)
{
    if((!a.emprunts[0] || !a.emprunts[1]) && l.quantity)
        return 0;
    else if(a.emprunts[0] && a.emprunts[1])
        printf("Cet abonné a atteint son quota maximal, il a déjà deux livres réservés\n");
    else
        printf("Ce livre n'est plus disponible\n");

    return 1;   // On retourne 1 si les conditions necessaires ne sont pas réunies

}

void lier_abonne(ABONNE a, int ide)
{
    FILE *f=NULL;
    int i;

    f = fopen(DB_ABONNE,"rb+");
    if(f != NULL)
    {

        for(i=0;i<2;i++)
        {
            if(!a.emprunts[i])
            {
                a.emprunts[i]=ide;
                break;
            }

        }

        fseek(f,sizeof(ABONNE)*(a.id-1),SEEK_SET);
        fwrite(&a,sizeof(ABONNE),1,f);
        fclose(f);

    }else
        printf("Erreur d'ouverture de la base de donnée des abonnés\n");  // TODO ajouter un retour


}

void decrementer_quantity(LIVRE l)
{
    FILE *f = NULL;

    f = fopen(DB_LIVRE,"rb+");

    if(f != NULL)
    {
        l.quantity--;
        fseek(f,sizeof(LIVRE)*(l.id-1),SEEK_SET);
        fwrite(&l,sizeof(LIVRE),1,f);
        fclose(f);
    }
    else
        printf("Erreur lors de l'ouverture de la base de donnée des livres\n");  // TODO : ajouter un retour aussi

}

void incrementer_quantity(int id)
{
    FILE *f = NULL;
    LIVRE l;

    f = fopen(DB_LIVRE,"rb+");
    if(f != NULL)
    {
        fseek(f,sizeof(LIVRE)*(id-1),SEEK_SET);
        fread(&l,sizeof(LIVRE),1,f);
        l.quantity++;
        fseek(f,-sizeof(LIVRE),SEEK_CUR);
        fwrite(&f,sizeof(LIVRE),1,f);
        //return 1;
        fclose(f);

    }

}

void retirer_abonne(int id, int idE)
{

    FILE *f = NULL;
    ABONNE a;
    int i;


    f = fopen(DB_ABONNE,"rb+");

    if(f != NULL)
    {
        fseek(f,sizeof(ABONNE)*(id-1),SEEK_SET);
        fread(&a,sizeof(ABONNE),1,f);

        for(i=0;i<2;i++)
        {
            if(a.emprunts[i] == idE)
                a.emprunts[i] = 0;
        }

        fseek(f,-sizeof(ABONNE),SEEK_CUR);
        fwrite(&a,sizeof(ABONNE),1,f);


        //return 1;

        fclose(f);
    }


}
