/*
 * @param char*: le pointeur vers la chaine de caractère resprésentant le dernier mot lu dans le fichier
 * texte d'entrée.
 * @return Liste_t*: retourne un pointeur vers la structure crée représentant un maillon de la liste
 * chainée qui contient les mots uniques du fichier texte d'entrée.
 * 
 * Cette fonction alloue un espace mémoire pour la structure représentant un maillon de la liste
 * chainée.
 */
Liste_t* nouveauMaillonMot(char*);