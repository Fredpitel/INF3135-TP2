/* 
 * @param char**: le tableau de pointeur de chaines de caractères correspondant aux paramètres
 * entrés au lancement du programme.
 * @return FILE*: retourne un pointeur vers le stream correspondant au fichier texte de sortie.
 * 
 * Cette fonction ouvre le stream correspondant au fichier texte dans lequel s'inscriera les statistiques.
 */
FILE* ouvrirFichierStats(char**);

/*
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return int: retourne le nombre de caractères dans la liste de mots uniques du fichier texte d'entrée.
 * 
 * Cette fonction compte le nombre de caractères dans la liste de mots uniques.
 */
int compterLettres(Variables_t*);

/* @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Stats_t*: retourne un pointeur vers la structure représentant le maillon de la liste
 * chainée qui contient le caractère du fichier texte d'entrée qui le plus fréquent.
 * 
 * Cette fonction vérifie quel caractère est le plus fréquent dans la liste de mots uniques.
 */
Lettre_t* plusFrequente(Variables_t*);

/*
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction crée une liste chainée qui contient les caractères de la liste de mots uniques et le nombre
 * de fois que ceux-ci apparaissent.
 */
Variables_t* creerListeLettres(Variables_t*);

/*
 * @param char: le dernier caractère lu dans le fichier texte.
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction vérifie si le dernier caractère lu est déjà dans la liste chainée qui contient les caractères.
 */
Variables_t* verifierLettre(char, Variables_t*);

/*
 * @param char: le dernier caractère lu dans le fichier texte.
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction ajoute un caractère à la fin de la liste chainée de caractères.
 */
Variables_t* nouvelleLettre(char, Variables_t*);

/*
 * @param char: le dernier caractère lu dans le fichier texte.
 * @return Stats_t*: retourne un pointeur vers la structure crée représentant un maillon de la liste
 * chainée qui contient les lettres du fichier texte d'entrée.
 * 
 * Cette fonction alloue un espace mémoire pour la structure représentant un maillon de la liste
 * chainée qui contient les caractères.
 */
Lettre_t* nouveauMaillonLettre(char);

/*
 * @param FILE*: le pointeur vers le stream correspondant au fichier texte de sortie.
 * 
 * Cette fonction ferme le stream correspondant au fichier texte de sortie.
 */
void fermerFichierStats(FILE* fichier);