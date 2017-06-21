#include "main.h"
#include "stats.h"
#include "stats-prive.h"
#include "liste.h"

boolean_t validerUnique(char* buffer, Variables_t* pointeurVar)
{
  Liste_t* prochain;
  boolean_t unique = TRUE;
  
  prochain = pointeurVar->liste;
  
  while (prochain != NULL && unique == TRUE)
  {
    if (strcmp(buffer, prochain->mot) == 0)
    {
      unique = FALSE;
    }
    prochain = prochain->motSuivant;
  }
  
  if (unique == TRUE)
  {
      (pointeurVar->stats->nonDoublons)++;
  }
  
  (pointeurVar->stats->nbMots)++;
  
  return unique;
}

Variables_t* fichierStats(Variables_t* pointeurVar, char** argv)
{
  FILE* fichier;
  int lettres;
  Lettre_t* carac;
  
  fichier = ouvrirFichierStats(argv);
  fprintf(fichier, "Statistiques d'exécution:\n");
  fprintf(fichier, "Nombre de mots sans doublons: %d\n", pointeurVar->stats->nonDoublons);
  fprintf(fichier, "Nombre de mots avec doublons: %d\n", pointeurVar->stats->nbMots);
  fprintf(fichier, "Nombre de lignes: %d\n", pointeurVar->stats->lignes);
  lettres = compterLettres(pointeurVar);
  fprintf(fichier, "Nombre de lettres dans la liste sans doublons: %d\n", lettres);
  if (lettres > 0)
  {
    carac = plusFrequente(pointeurVar);
    fprintf(fichier, "La lettre la plus fréquente est %c avec %d occurence(s).\n", carac->carac, carac->nombre);
  } else {
      fprintf(fichier, "Il n'y pas de lettre plus fréquente car le fichier ne contient aucune lettre.\n");
  } 
  fermerFichierStats(fichier);
  
  return pointeurVar;
}

FILE* ouvrirFichierStats(char** argv)
{
  FILE* fichier;
  
  fichier = fopen(argv[3], "w");

  if (fichier == NULL) 
  {
    printf("Erreur #%d lors de l'ouverture du fichier de sortie\n", errno);
    exit(1);
  }
  
  return fichier;    
}
  
int compterLettres(Variables_t* pointeurVar)
{
  int lettres = 0;
  Liste_t* prochain;
  
  prochain = pointeurVar->liste;
  
  while (prochain != NULL)
  {
    lettres = lettres + (strlen(prochain->mot));
    prochain = prochain->motSuivant;
  }
  
  return lettres;
}

Lettre_t* plusFrequente(Variables_t* pointeurVar)
{
  Lettre_t* carac;
  Lettre_t* prochain;
  
  pointeurVar = creerListeLettres(pointeurVar);
  
  carac = pointeurVar->stats->lettre;
  prochain = carac;
  
  while (prochain != NULL)
  {
    if (prochain->nombre > carac->nombre)
    {
      carac = prochain;
    }
    
    prochain = prochain->lettreSuivante;
  }
  
  return carac;
}

Variables_t* creerListeLettres(Variables_t* pointeurVar)
{
  Liste_t* prochain;
  char* carac;
  
  prochain = pointeurVar->liste;
  
  while (prochain != NULL)
  {
    carac = prochain->mot;
    
    do
    {
      pointeurVar = verifierLettre(*carac, pointeurVar);
      carac++;
    } while (*carac != '\0');
    
    prochain = prochain->motSuivant;
  }

  return pointeurVar;
}

Variables_t* verifierLettre(char carac, Variables_t* pointeurVar)
{
  Lettre_t* prochain;
  
  prochain = pointeurVar->stats->lettre;

  while(prochain != NULL)
  {
    if (prochain->carac == carac)
    {
      prochain->nombre++;
      return pointeurVar;
    }
   prochain = prochain->lettreSuivante;
  }
  
  pointeurVar = nouvelleLettre(carac, pointeurVar);
  
  return pointeurVar;
}

Variables_t* nouvelleLettre(char carac, Variables_t* pointeurVar)
{
  Lettre_t* maillon;
  Lettre_t* prochain;
  
  maillon = nouveauMaillonLettre(carac);
  prochain = pointeurVar->stats->lettre;
  
  if (prochain == NULL)
  {
    pointeurVar->stats->lettre = maillon;
  } else {
    while(prochain->lettreSuivante != NULL)
    {
      prochain = prochain->lettreSuivante;
    }
    
    prochain->lettreSuivante = maillon;
  }
  
  return pointeurVar;
}

Lettre_t* nouveauMaillonLettre(char carac)
{
  Lettre_t* maillon;
  
  maillon = malloc(sizeof(Lettre_t));
  if (maillon == NULL)
  {
    erreurMemoire();
  }
  
  maillon->carac = carac;
  maillon->nombre = 1;
  
  return maillon;
}

void fermerFichierStats(FILE* fichier)
{
  if (fclose(fichier) == EOF) {
    printf("Erreur lors de la fermeture du fichier de sortie\n");
    exit(1);
  }
}
