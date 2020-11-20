#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TABSIZE 10
#define TAILLEAJOUT 50

//fonction qui remplit un tableau d'entiers de taille size avec des zéros
int initTab(int* Tab, int size) {
	if (Tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < TABSIZE; i++) {
			Tab[i] = 0;
		}
		return size;
	}
}

//affiche les nbElts premiers éléments du tableau sur une ligne
int afficheTab(int* Tab, int size, int nbElts) {
	if (Tab == NULL || size < 0 || size < nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", Tab[i]);
		}
		return 0;
	}
}

//ajoute un élément dans le tableau, en augmentant la mémoire allouée si besoin
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || size < 0) {
		return NULL;
	}
	else {
		if (*nbElts >= *size) {

			int* tabBis = tab;

			tabBis = (int*)realloc(tabBis, (*size + TAILLEAJOUT) * sizeof(int));

			if (tabBis != NULL) {
				tab = tabBis;
				tab[*nbElts] = element;
				*nbElts = *nbElts + 1;
				*size = *size + TAILLEAJOUT;
				return (tab);
			}
			else {
				return (NULL);
			}
		}
		else {
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
			return (tab);
		}
	}
}