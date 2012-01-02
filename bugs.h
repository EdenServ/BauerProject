/*

    Nom du projet : Gestion d'une bibliothèque
    Nom de code : BauerProject
    Codé par  : Skander Ben Mahmoud et Mones Ben Jmâa.
    Fichier courant : bugs.h
    Déscription : Toutes les information necessaire au bon fonctionnement de ce module et son interaction avec bugzilla

    */

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>  // ;)
#include "version.h"


//Informations pour bugzilla

#define BUGZILLA_URL "rednaks.alwaysdata.net/"
#define BUGZILLA_INDEX "index.cgi"         //utile pour la connexion
#define BUGZILLA_BUGPOST "post_bug.cgi"  // soumission du bug
// informations pour la connexion :

#define BUGZILLA_LOGIN "Bugzilla_login=user@edenserv.com"
#define BUGZILLA_PASSW "Bugzilla_password=userpwd"
#define BUGZILLA_GOAHEAD "GoAheadAndLogIn=1"

//informations utiles pour la soumission du bug

#define BUGZILLA_PRODUCT "product=BauerProject"
#define BUGZILLA_COMPONENT "component="
#define BUGZILLA_VERSION "version="
#define BUGZILLA_SEVERTY "bug_serverity="
#define BUGZILLA_PLATFORM "rep_platform=PC"

#if defined (WIN32)
   #define BUGZILLA_OS "op_sys=Windows"
#elif defined (linux)

    #define BUGZILLA_OS "op_sys=Linux"
#endif

#define BUGZILLA_STATUS "bug_status=CONFIRMED"
#define BUGZILLA_ASSIGNEDTO "assigned_to=salexandre.bm@gmail.com"
#define BUGZILLA_SHORT "short_desc="
#define BUGZILLA_COMMENT "comment="


// BUG_SERVERTY choices :
#define BUGZILLA_SEVERTY_CRITICAL "critical"         // pour les bugs critiques
#define BUGZILLA_SEVERTY_ENHANCEMENT "enhancement"   //pour l'amélioration
#define BUGZILLA_SEVERTY_NORMAL "normal"            // un bug normal




// BUG_COMPONENT

#define BUGZILLA_COMPONENT_LIVRE "Gestion des livres"
#define BUGZILLA_COMPONENT_ABONNE "Gestionn des abonnés"
#define BUGZILLA_COMPONENT_EMRUNTS "Gestion des emprunts"
#define BUGZILLA_COMPONENT_AUTRE "Autre"


// Les constantes session
#define BUGZILLA_COOKIE ".cookie.txt"


int bugzilla_connect(void);
void bugzilla_push(char *);
void TraitementBugs(int);
void SoumettreBugLivre(int);
void SoumettreBugAbonne(int);
void SoumettreBugEmprunts(int);
void SoumettreBugAutre(int);


