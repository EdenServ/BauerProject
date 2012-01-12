/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : fonctions.c
    Déscription : l'implémentation des fonctions

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


int supprimer_ligne(unsigned int ligne,size_t taille, char *nomFichier, int m)
{
    char p[taille];
    FILE *f = NULL,*f1 = NULL;
    int i=1;
    f = fopen(nomFichier,"rb");
    f1 = fopen(TEMP_FILE,"wb+");
    if(f1 != NULL && f != NULL)
    {
        copie_fichier(f,f1);     // copier f dans le fichier temporaire f1
        fseek(f1,0,SEEK_SET);
        fclose(f);
        f = fopen(nomFichier,"wb+");
        if(f != NULL)
        {
            while(fread(p,taille,1,f1)!=0)
            {
                if(i!=ligne)
                    fwrite(p,taille,1,f);
                i++;
                }
        //fputc(EOF,f);
        reordonner_selon_id(f,m);
        fclose(f);
        fclose(f1);
        }
        remove(TEMP_FILE);
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
            livre2.id=0;
            if(fread(&livre1,sizeof(LIVRE),1,f)!=0)
            {
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

                }else if(livre2.id == 0)  // au cas où il n'y a qu'une seule ligne :
                {
                    fseek(f,-sizeof(LIVRE),SEEK_CUR);
                    livre1.id--;
                    fwrite(&livre1,sizeof(LIVRE),1,f);

                }
            }
                break;
        case 2: // réordonner la base de donnée des abonnés selon l'id

            abonne2.id=0;
            if(fread(&abonne1,sizeof(ABONNE),1,f)!=0)
            {
                while(fread(&abonne2,sizeof(ABONNE),1,f)!=0)
                {
                    if(abonne1.id-abonne2.id!=1)  // on vérifie que c'est bien ordonné sinon on sort de la boucle et on corrige
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
                    }while(fread(&abonne2,sizeof(ABONNE),1,f)!=0);

                }else if( abonne2.id ==0)
                {
                    fseek(f,-sizeof(ABONNE),SEEK_CUR);
                    abonne1.id--;
                    fwrite(&abonne1,sizeof(ABONNE),1,f);
                }
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
                printf("i:%d t:%s a:%s e:%s is:%s q:%d\n",l.id,l.titre,l.auteur,l.edition,l.ISBN,l.quantity);
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
            while(fread(&a,sizeof(ABONNE),1,f)!=0)
            {
                printf("%d %s %s %s %s %d %s %s %d %d\n",a.id,a.nom,a.prenom,a.cin,a.email,a.telephone,a.addresse,ctime(&a.date),a.emprunts[0],a.emprunts[1]);
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

void journaliser(char *s)
{
    time_t temps;
    char date[24];
    FILE *f=NULL;

    time(&temps);
    sprintf(date,"%.24s",ctime(&temps));
    f = fopen(LOG_FILE,"a");
    if(f != NULL)
    {
        fprintf(f,"[%s] %s\n",date,s);
        fclose(f);
    }else
        printf("Erreur lors de l'ouverture du fichier journal\n");

}


void lire_espace(char *s, int size)
{

    char c;
    int i=0;
    do
    {
        if(i> size)
            printf("Erreur de saisie, chaine trop longue\n");
        i = 0;
        do
        {
        c=getchar();
        s[i]=c;
        i++;
    }while(c!='\n');
    s[i-1]='\0';
    }while(i>size);
}

void lire_cin(char cin[8])
{
    int i=0, ok = 1, j=0;;
    char c;

    do
    {
        if((i!=8 || ok == 0)&& j !=0)
            printf("CIN invalide !\n");
        j++;
        i = 0;
        ok = 1;
    do
    {
        c = getchar();
        if(c<='9' && c>='0')
        {
            cin[i]=c;
            i++;
        }
        else if(c != '\n')
        {
          ok = 0;
         break;
        }
    }while(c != '\n');
    cin[i] = '\0';
    printf("\nDebug i %d | ok %d\n",i,ok);
    printf("DEBUG2 : %s",cin);
    if(i==1 && cin[0] == '0')
        break;

}while(  i!=8 || ok == 0);

}

void lire_chiffre(int *a)
{

    char e[16],aux[16];
    int ok=0;
    do
    {
        lire_espace(e,sizeof(e));
        if(e[0]=='0')
            sprintf(aux,"0%d",atoi(e));
        else
            sprintf(aux,"%d",atoi(e));

        if(strcmp(aux,e))
        {
            printf("Erreur ! Vous devez entrer un chiffre !\n");
            ok = 0;
        }
        else
            ok = 1;
    }while(!ok);
    *a = atoi(e);


}

void lire_email(char email[50])
{


    char c;
    int i=0,k=0,ok = 1,j=0;
    do
    {
        if(i> 50)
            printf("Erreur de saisie, chaine trop longue\n");
        printf("DEBUG : k:%d ok:%d j:%d\n",k,ok,j);
        i = 0;
        if((k != 1 || ok == 0)&& j!=0)
            printf("Email invalide !\n");
        k = 0;
        j++;
        ok = 1;

        do
        {
        c=getchar();
        if(c == '@')
            k++;
        if (c == ' ')
            ok = 0;
        email[i]=c;
        i++;
    }while(c!='\n');
    email[i-1]='\0';
    }while(i>50 || k != 1 || ok == 0);

}
