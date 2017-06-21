typedef struct Stats
{
  int nonDoublons;
  int nbMots;
  int lignes;
  struct Lettre* lettre;
} Stats_t;

typedef struct Lettre
{
  char carac;
  int nombre;
  struct Lettre* lettreSuivante;
} Lettre_t;

/*
 * @param char*: la chaine de caractère contenant le mot lu dans le fichier texte d'entrée.
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return boolean_t: retourne TRUE si c'est la première occurence du mot lu dans le fichier texte
 * d'entrée et FALSE s'il s'agit d'un doublon.
 * 
 * Cette fonction vérifie si le dernier mot lu est déjà dans la liste chainée.
 */
boolean_t validerUnique(char*, Variables_t*);

/*
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @param char**: le tableau de pointeur de chaines de caractères correspondant aux paramètres
 * entrés à l'exécution du programme.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction permet de populer le fichier texte contenant toutes les statistiques d'exécution du programme.
 */
Variables_t* fichierStats(Variables_t*, char**);