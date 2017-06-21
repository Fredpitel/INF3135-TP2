#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

typedef struct Variables
{
  struct Liste* liste;
  struct Stats* stats;
} Variables_t;
  
typedef enum {FALSE, TRUE} boolean_t;

/* 
 * @param int: le nombre de paramètres reçus à l'exécution du programme.
 * @param char*: la chaine de texte entrée comme option pour afficher les statistiques.
 * @return boolean_t: retourne TRUE si les statistiques ont été demandées, FALSE sinon.
 * 
 * Cette fonction vérifie que le bon nombre de paramètres à été entré à l'exécution du programme.
 */
boolean_t validerParam(int, char*);

/* 
 * @param char**: le tableau de pointeur de chaines de caractères correspondant aux paramètres
 * entrés au lancement du programme.
 * @return FILE*: retourne un pointeur vers le stream correspondant au fichier texte d'entrée. 
 * 
 * Cette fonction ouvre le stream correspondant au fichier texte qui contient les mots à trier.
 */
FILE* ouvrirFichier(char**);

/* 
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction alloue un espace mêmoire pour la structure contenant les variables statistiques et les
 * listes chainées.
 */
Variables_t* initialiserVariables(Variables_t*);

/* 
 * Cette fonction affiche un message d'erreur à la console lorsqu'une erreur d'allocation de mémoire se
 * produit et termine le programme en erreur.
 */
void erreurMemoire();

/* 
 * @param FILE*: le pointeur vers le fichier contenant les mots à trier.
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction lit le contenu du fichier un caractère à la fois et analyse le caractère lu.
 */
Variables_t* lireFichier(FILE*, Variables_t*);

/* 
 * @param char: le dernier caractère lu dans le fichier texte.
 * @param char*: le pointeur vers la chaine de caractère représentant les lettres du mot lues jusqu'à date.
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * @return Variables_t*: retourne le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cette fonction vérifie si le mot est terminé et, si c'est le cas, elle ajoute '\0' à la fin du buffer
 * et termine la fonction. Sinon, elle ajoute le caractère lu à la fin du buffer.
 */
Variables_t* ajouterCarac(char, char*, Variables_t*);

/*
 * @param Variables_t*: le pointeur vers la structure contenant les variables statistiques et les
 * listes chainées.
 * 
 * Cettre fonction sert à libérer toute la mémoire allouée dynamiquement lors de l'exécution du programme.
 */
void libererVariables(Variables_t*);

/*
 * @param FILE*: le pointeur vers le fichier contenant les mots à trier.
 * 
 * Cette fonction ferme le stream correspondant au fichier texte d'entrée.
 */
void fermerFichier(FILE*);



