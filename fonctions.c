/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : fonctions.c
    Déscription :

    */


#include "fonctions.h"
#include "Abonnes.h"
#include "Livres.h"




unsigned long taille_fichier(FILE *f)
{
    unsigned long taille = 0;
    fseek(f,0,SEEK_END);
    taille = ftell(f);
    fseek(f,0,SEEK_SET);
    return taille;
}


int supprimer_ligne(unsigned int ligne,size_t taille, FILE *f)
{
    char p[taille];
    FILE *f1 = NULL;

    f1 = fopen(TEMP_F,"w+");
    if(f1 != NULL)
    {
        copie_fichier(f,f1);
        fseek(f,taille*(ligne-1),SEEK_SET);
        fseek(f1,taille*ligne,SEEK_SET);
        while(fread(p,taille,1,f1)!=0)
        {
            fwrite(p,taille,1,f);
        }
        fputc(EOF,f);
        reordonner_selon_id(f,1);
        fclose(f1);
        remove(TEMP_F);
        return 0;
    }else
    {
        printf("Erreur lors de la création du fichier temp\n");
        return 1;
    }
}


void copie_fichier(FILE *f1, FILE *f2)
{
    char c;
    c = fgetc(f1);
    while(c != EOF)
    {
        fputc(c,f2);
        c = fgetc(f1);
    }

}


void reordonner_selon_id(FILE *f, int i)
{
    LIVRE livre1, livre2;
    ABONNE abonne1,abonne2;
    int r = 0;

    fseek(f,0,SEEK_SET);

    switch(i)
    {
        case 1: // réordonner la base de donnée des livres selong l'id
            fread(&livre1,sizeof(LIVRE),1,f);
            while(fread(&livre2,sizeof(LIVRE),1,f)!=0)
            {
                if(livre1.id-livre2.id!=1)
                {
                    r = 1;
                    break;
                }

                fread(&livre1,sizeof(LIVRE),1,f);

            }

            if(r)
            {
                do
                {
                    fseek(f,-sizeof(LIVRE),SEEK_CUR);
                    livre2.id--;
                    fwrite(&livre2,sizeof(LIVRE),1,f);
                }while(fread(&livre2,sizeof(LIVRE),1,f)!=0);

            }
            break;
        case 2: // réordonner la base de donnée des abonnés selon l'id

            fread(&abonne1,sizeof(ABONNE),1,f);
            while(fread(&abonne2,sizeof(ABONNE),1,f)!=0)
            {
                if(livre1.id-livre2.id!=1)
                {
                    r = 1;
                    break;
                }

                fread(&abonne1,sizeof(ABONNE),1,f);

            }

            if(r)
            {
                do
                {
                    fseek(f,-sizeof(ABONNE),SEEK_CUR);
                    abonne2.id--;
                    fwrite(&abonne2,sizeof(ABONNE),1,f);
                }while(fread(&abonne2,sizeof(LIVRE),1,f)!=0);

            }
            break;

    }
}

void lister_fichier(FILE *f, int i)
{


    char c = ' ';
    int j=0;
    LIVRE l;
    ABONNE a;

    switch(i)
    {
        case 1:     //lister la base de donnés des livres
            while(fread(&l,sizeof(l),1,f)!=0)
            {
                printf("%d %s %s %d\n",l.id,l.titre,l.ISBN,l.quantity);
                j++;
                if(j%10 == 0)
                {
                    c = ' ';
                    while(c!= 'o' && c !='O' && c != 'n' && c != 'N')
                    {
                        printf("Voulez vous voir plus ? (O/n) :\n");
                        scanf("%c",&c);
                    }
                    if(c == 'n' || c == 'N')
                        break;

                }
            }
            break;
        case 2:
            j=0;
            while(fread(&a,sizeof(a),1,f)!=0)
            {
                printf("%d %s %s\n",a.id,a.nom,a.prenom);
                j++;
                if(j%10 == 0)
                {
                    c = ' ';
                    while(c!= 'o' && c !='O' && c != 'n' && c != 'N')
                    {
                        printf("Voulez vous voir plus ? (O/n) :\n");
                        scanf("%c",&c);
                    }
                    if(c == 'o' || c == 'O')
                        break;

                }
            }
            break;
    }



}
