#pragma once

typedef struct Tableau {
	int* elt; //le tableau d'entiers
	int size; //la taille de ce tableau d'entiers
	int eltsCount; //le nombre d'éléments dans le tableau
} TABLEAU;

int initTab(int* Tab, int size); //fonction qui remplit un tableau d'entiers de taille size avec des zéros

int afficheTab(int* Tab, int size, int nbElts); //affiche les nbElts premiers éléments du tableau sur une ligne

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element); //ajoute un élément dans le tableau, en augmentant la mémoire allouée si besoin

TABLEAU newArray(); //créé un nouveau tableau en utilisant la structure TABLEAU, avec une taille initiale pour les données

int incrementArraySize(TABLEAU* tab, int incrementValue); //modifie la taille du tableau en utilisant la structure TABLEAU

int setElement(TABLEAU* tab, int pos, int element); //écrit un élément à une position donnée sans insertion

int displayElements(TABLEAU* tab, int startPos, int endPos); //affiche une portion du tableau de l'indice de début à l'indice de fin

int deleteElements(TABLEAU* tab, int startPos, int endPos); //supprime des éléments avec compactage du tableau
