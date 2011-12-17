



typedef struct livre {
  int id;
  char titre[50];
  char ISBN[13];
} LIVRE;

void TraitementLivre(int choix);
void AjouterLivre(void);
void SupprimerLivre(void);
