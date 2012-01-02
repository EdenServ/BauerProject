/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : bugs.c
    Déscription : l'implémentation des fonctions d'intéraction avec bugzilla

    */


#include "bugs.h"
#include "Menus.h"
#include "fonctions.h"




void TraitementBugs(int choix)
{
    switch(choix)
    {

        case 1:
            SoumettreBugLivre(AfficheMenuSeverty());
            break;
        case 2:
            SoumettreBugAbonne(AfficheMenuSeverty());
            break;
        case 3:
            SoumettreBugEmprunts(AfficheMenuSeverty());
        case 4:
            SoumettreBugAutre(AfficheMenuSeverty());
            break;
        case 5:
            break;
        default:
            printf("Le choix que vous avez sais n'exite pas");
    }

    PAUSE

}


int bugzilla_connect(void)   // connexion à bugzilla
{
    CURL *session;
    char url[50], data[100];

    printf("%d",sizeof(BUGZILLA_URL)+sizeof(BUGZILLA_INDEX));
    printf("%d",sizeof(BUGZILLA_LOGIN)+sizeof(BUGZILLA_PASSW)+sizeof(BUGZILLA_GOAHEAD));

    printf("Trying to connect ...\n");
    session = curl_easy_init();
    if(session)
    {
        sprintf(url,"%s%s",BUGZILLA_URL,BUGZILLA_INDEX);  // On colle les mouceaux pour définir l'url à curl
        sprintf(data,"%s&%s&%s",BUGZILLA_LOGIN,BUGZILLA_PASSW,BUGZILLA_GOAHEAD);  // les donnée post regroupée
        curl_easy_setopt(session,CURLOPT_URL,url);
        curl_easy_setopt(session,CURLOPT_VERBOSE,1);
        curl_easy_setopt(session,CURLOPT_POSTFIELDS,data);
        curl_easy_setopt(session,CURLOPT_COOKIEJAR,BUGZILLA_COOKIE);
        curl_easy_perform(session);
        curl_easy_cleanup(session);
        printf("Connected !\n");
        return 0;
    }else
    {
        printf("Enable to connect to Bugzilla\n");
        return 1;
    }

    printf("Error here !");

}

void bugzilla_push(char *data)
{
    printf("Entrance to push\n");
    CURL *session;
    char url[50], aux[2000];
    char titre[50], desc[1000];
    int i=0;
    char c=' ';

        printf("Donner le titre du bug à soumettre:\n");

        while(getchar()!='\n');
        do
        {
            c = getchar();
            titre[i]=c;
            i++;

        }while(c!='\n');
        titre[i-1]='\0';
        i=0;

        printf("Donner une description du bug:\n");
        do
        {
            c=getchar();
            desc[i]=c;
            i++;
        }while(c!='\n');
        desc[i-1]='\0';
        printf("%s\n",desc);

        printf("%d",sizeof(BUGZILLA_PRODUCT)+sizeof(data)+sizeof(BUGZILLA_PLATFORM)+sizeof(BUGZILLA_OS)+sizeof(BUGZILLA_STATUS)+sizeof(BUGZILLA_ASSIGNEDTO)+sizeof(titre)+sizeof(BUGZILLA_COMMENT)+sizeof(desc));
        sprintf(aux,"%s&%s&%s&%s&%s&%s&%s%s&%s%s&%s%s",BUGZILLA_PRODUCT,data,BUGZILLA_PLATFORM,BUGZILLA_OS,BUGZILLA_STATUS,BUGZILLA_ASSIGNEDTO,BUGZILLA_SHORT,titre,BUGZILLA_COMMENT,desc,BUGZILLA_VERSION,VERSION);

        session = curl_easy_init();
        if(session)
        {
            sprintf(url,"%s%s",BUGZILLA_URL,BUGZILLA_BUGPOST);
            curl_easy_setopt(session,CURLOPT_URL,url);
            curl_easy_setopt(session,CURLOPT_POSTFIELDS,aux);
            curl_easy_setopt(session,CURLOPT_COOKIEFILE,BUGZILLA_COOKIE);
            curl_easy_perform(session);
            curl_easy_cleanup(session);

        }else
            printf("Error while posting the Bug ! Please try later");




}

void SoumettreBugLivre(int choix)
{
    printf("On entre dans la soumissionLivre\n");
    char data[70];
    int i=1;
    switch(choix)
    {
        case 1:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_LIVRE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_ENHANCEMENT);
            break;
        case 2:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_LIVRE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_NORMAL);
            break;
        case 3:
        sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_LIVRE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_CRITICAL);
            break;
        case 4:
            return;
        default:
            printf("Ce choix n'existe pas");
            return;
    }
    i = bugzilla_connect();
    if(i==0)
    {

        bugzilla_push(data);
    }


}

void SoumettreBugAbonne(int choix)
{
    char data[70];
    switch(choix)
    {
        case 1:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_ABONNE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_ENHANCEMENT);
            break;
        case 2:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_ABONNE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_NORMAL);
            break;
        case 3:
        sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_ABONNE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_CRITICAL);
            break;
        case 4:
            return;
        default:
            printf("Ce choix n'existe pas");
            return;
    }
    if(!bugzilla_connect())
    {
        bugzilla_push(data);
    }



}

void SoumettreBugEmprunts(int choix)
{
    char data[70];
    switch(choix)
    {
        case 1:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_EMRUNTS,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_ENHANCEMENT);
            break;
        case 2:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_EMRUNTS,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_NORMAL);
            break;
        case 3:
        sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_EMRUNTS,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_CRITICAL);
            break;
        case 4:
            return;
        default:
            printf("Ce choix n'existe pas");
            return;
    }
    if(!bugzilla_connect())
    {
        bugzilla_push(data);
    }



}

void SoumettreBugAutre(int choix)
{
    char data[70];
    switch(choix)
    {
        case 1:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_AUTRE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_ENHANCEMENT);
            break;
        case 2:
            sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_AUTRE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_NORMAL);
            break;
        case 3:
        sprintf(data,"%s%s&%s%s",BUGZILLA_COMPONENT,BUGZILLA_COMPONENT_AUTRE,BUGZILLA_SEVERTY,BUGZILLA_SEVERTY_CRITICAL);
            break;
        case 4:
            return;
        default:
            printf("Ce choix n'existe pas");
            return;
    }
    if(!bugzilla_connect())
    {
        bugzilla_push(data);
    }



}
