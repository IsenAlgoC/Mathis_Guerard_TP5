#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TABSIZE 10
#define TAILLEAJOUT 50
#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;
	int size;
	int eltsCount;
} TABLEAU;

//fonction qui remplit un tableau d'entiers de taille size avec des z�ros
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

//affiche les nbElts premiers �l�ments du tableau sur une ligne
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

//ajoute un �l�ment dans le tableau, en augmentant la m�moire allou�e si besoin
int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL || size < 0) {
		return NULL;
	}
	else {
		if (*nbElts >= *size) { //cas ou il faut ajouter de la m�moire, on cr�� une copie du tableau pour �viter de perdre des donn�es

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
		else { //cas ou la m�moire est suffisante
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
			return (tab);
		}
	}
}

//cr�� un nouveau tableau en utilisant la structure TABLEAU, avec une taille initiale pour les donn�es
TABLEAU newArray() {
	TABLEAU Tab;
	Tab->elt = NULL;
	Tab.size = TAILLEINITIALE;
	Tab.eltsCount = 0;

	Tab->elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	return Tab;
}

//modifie la taille du tableau en utilisant la structure TABLEAU
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	tab->elt = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
	tab->size = tab->size + incrementValue;
	if (tab->elt == NULL) {
		return -1;
	}
	else {
		return tab->size;
	}
}