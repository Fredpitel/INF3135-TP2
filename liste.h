typedef struct Liste
{
  char mot[82];
  struct Liste* motSuivant;
} Liste_t;

/*
 * @param char*: le pointeur vers la chaine de caractère resprésentant le dernier mot lu dans le fichier 
 * texte d'entrée.
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction ajoute un nouveau mot à la fin de la liste chainée.
 */
Variables_t* ajouterMot(char*, Variables_t*);

/*
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction trie les mots de la liste chainée en ordre alphabétique.
 */
void trierListe(Variables_t*);

/*
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction affiche les mots de la liste chainée à la console en ordre alphabétique.
 */
void afficherListe(Variables_t*);