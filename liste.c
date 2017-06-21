#include "main.h"
#include "liste.h"
#include "liste-prive.h"

Variables_t* ajouterMot(char* buffer, Variables_t* pointeurVar)
{
  Liste_t* maillon;
  Liste_t* prochain;
  
  prochain = pointeurVar->liste;  
  maillon = nouveauMaillonMot(buffer);
  
  if (prochain == NULL)
  {
    pointeurVar->liste = maillon;
  } else {
    while (prochain->motSuivant != NULL)
    {
      prochain = prochain->motSuivant;
    }
    
    prochain->motSuivant = maillon;
  }
  return pointeurVar;
}

Liste_t* nouveauMaillonMot(char* buffer)
{
  Liste_t* maillon;
  
  maillon = (Liste_t*)malloc(sizeof(Liste_t));
  if (maillon == NULL)
  {
    erreurMemoire();
  }
  
  strcpy(maillon->mot, buffer);
  
  return maillon;
}

void trierListe(Variables_t* pointeurVar)
{
  char mot[82];
  Liste_t* motInitial;
  Liste_t* motCompare;
  
  motInitial = pointeurVar->liste;
  
  while (motInitial != NULL)
  {
    motCompare = motInitial->motSuivant;
    while (motCompare != NULL)
    {
      if (strcmp(motInitial->mot, motCompare->mot) > 0)
      {
        strcpy(mot, motInitial->mot);
        strcpy(motInitial->mot, motCompare->mot);
        strcpy(motCompare->mot, mot);
      }
      
      motCompare = motCompare->motSuivant;
    }
    motInitial = motInitial->motSuivant;
  }
}

void afficherListe(Variables_t* pointeurVar)
{
  Liste_t* prochain;
  
  prochain = pointeurVar->liste;
  
  while (prochain != NULL)
  {
    printf("%s\n", prochain->mot);
    prochain = prochain->motSuivant;
  }
}
