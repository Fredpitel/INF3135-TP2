#include "main.h"
#include "liste.h"
#include "stats.h"

int main(int argc, char** argv) 
{
  FILE* fichier;
  boolean_t ecrireStats;
  Variables_t* pointeurVar = NULL;
  
  ecrireStats = validerParam(argc, argv[2]);
  fichier = ouvrirFichier(argv);
  pointeurVar = initialiserVariables(pointeurVar);
  pointeurVar = lireFichier(fichier, pointeurVar);
  trierListe(pointeurVar);
  afficherListe(pointeurVar);
  
  if(ecrireStats == TRUE)
  {
    pointeurVar = fichierStats(pointeurVar, argv);
  }
  
  libererVariables(pointeurVar);
  fermerFichier(fichier);
  
  return 0;
}

boolean_t validerParam(int argc, char* option) 
{
  boolean_t ecrireStats;
  
  if (argc < 2 || argc > 4 || argc == 3) {
    printf("Utilisation:\n./tp2 [nom du fichier à lire]\nOU\n./tp2 [nom du fichier à lire] [-S] [nom du fichier des stats]\nsi vous voulez obenir les statistiques d'exécution.\n");
    exit(1);
  }

  if(argc == 4)
  {
    if (strcmp(option, "-S") == 0)
    {
      ecrireStats = TRUE;
    } else {
      printf("Veuillez utiliser l'option -S pour obtenir les statistiques.\n");
      exit(1);
    }
  }
  
  return ecrireStats;
}

FILE* ouvrirFichier(char** argv) 
{
  FILE* fichier;
  
  fichier = fopen(argv[1], "r");

  if (fichier == NULL) {
    printf("Erreur #%d lors de l'ouverture du fichier d'entrée\n", errno);
    exit(1);
  }
  
  return fichier;
}

Variables_t* initialiserVariables(Variables_t* pointeurVar)
{
  Stats_t* stats;  
  
  pointeurVar = malloc(sizeof(Variables_t));
  if (pointeurVar == NULL)
  {
    erreurMemoire();
  }
  
  stats = malloc(sizeof(Stats_t));
  if (stats == NULL)
  {
    erreurMemoire();
  }
  
  pointeurVar->stats = stats;
  return pointeurVar;
}

void erreurMemoire()
{
  printf("Erreur d'allocation de mémoire");
  exit(1);
}

Variables_t* lireFichier(FILE* fichier, Variables_t* pointeurVar)
{
  char carac;
  char* buffer;
  char debutBuffer[82];
  
  buffer = debutBuffer;
  carac = fgetc(fichier);
  
  while (carac != EOF)
  {
    pointeurVar = ajouterCarac(carac, buffer, pointeurVar);
    if (carac == ' ' || carac == '\n')
    {
      if(*debutBuffer != '\0' && validerUnique(buffer, pointeurVar))
      {
        pointeurVar = ajouterMot(buffer, pointeurVar);  
      }
      buffer = debutBuffer;
    }
    carac = fgetc(fichier);
    buffer++;
  }
  return pointeurVar;
}

Variables_t* ajouterCarac(char carac, char* buffer, Variables_t* pointeurVar)
{
  if(carac == ' ' || carac == '\n')
  {
    if (carac == '\n')
    {
      (pointeurVar->stats->lignes)++;
    }
    *buffer = '\0';
  } else {
    *buffer = carac;
  }
  
  return pointeurVar;
}

void libererVariables(Variables_t* pointeurVar)
{
  Liste_t* prochainMot;
  Lettre_t* prochaineLettre;
  
  while(pointeurVar->liste != NULL)
  {
    prochainMot = pointeurVar->liste->motSuivant;
    free(pointeurVar->liste);
    pointeurVar->liste = prochainMot;
  }
  
  while(pointeurVar->stats->lettre != NULL)
  {
    prochaineLettre = pointeurVar->stats->lettre->lettreSuivante;
    free(pointeurVar->stats->lettre);
    pointeurVar->stats->lettre = prochaineLettre;
  }
  
  free(pointeurVar->stats);
  free(pointeurVar);
}

void fermerFichier(FILE* fichier) 
{
  if (fclose(fichier) == EOF) {
    printf("Erreur lors de la fermeture du fichier d'entrée.\n");
    exit(1);
  }
}
