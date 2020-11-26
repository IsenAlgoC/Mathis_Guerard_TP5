#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TABSIZE 10
#define TAILLEAJOUT 50
#define TAILLEINITIALE 100

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
		if (*nbElts >= *size) { //cas ou il faut ajouter de la mémoire, on créé une copie du tableau pour éviter de perdre des données

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
		else { //cas ou la mémoire est suffisante
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
			return (tab);
		}
	}
}

//créé un nouveau tableau en utilisant la structure TABLEAU, avec une taille initiale pour les données
TABLEAU newArray() {
	TABLEAU Tab;
	Tab.size = TAILLEINITIALE;
	Tab.eltsCount = 0;

	Tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
	if (Tab.elt == NULL) {
		return Tab;
	}
	else {
		for (int i = 0; i < Tab.size; i++) {
			Tab.elt[i] = 0;
		}
		return Tab;
	}
}

//modifie la taille du tableau en utilisant la structure TABLEAU
int incrementArraySize(TABLEAU* tab, int incrementValue) {
	int* tabBis = tab->elt;
	tabBis = (int*)realloc(tabBis, (tab->size + incrementValue) * sizeof(int));
	if (tabBis == NULL || incrementValue < 0 || tab->eltsCount > tab->size) { //si erreur
		return -1;
	}
	else {
		tab->elt = tabBis;
		return (tab->size + incrementValue);
	}
}

//écrit un élément à une position donnée sans insertion
int setElement(TABLEAU* tab, int pos, int element) {
	if (pos > tab->size) { //cas ou la position est plus grande que la taille max du tableau
		int taille = tab->size;
		tab->size = incrementArraySize(tab, pos - tab->size); //on augmente la taille du tableau du nombre manquant
		if (tab->size == -1 || tab->elt == NULL || tab->eltsCount > tab->size) { //si erreur
			return 0;
		}
		else {
			for (int i = taille + 1; i < pos; i++) { //on ajoute les zéros
				tab->elt[i-1] = 0;
			}
			tab->elt[pos-1] = element;
			tab->eltsCount = tab->eltsCount + pos;
			return pos;
		}
	}

	else {
		tab->elt[pos-1] = element;
		return pos;
	}
}

//affiche une portion du tableau de l'indice de début à l'indice de fin
int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (startPos <= 0 || endPos <= 0 || tab->elt == NULL || tab->eltsCount > tab->size || endPos > tab->size || startPos > tab->size) {
		return -1;
	}
	else {
		if (startPos <= endPos) {
			for (int i = startPos; i <= endPos; i++) {
				printf("%d ", tab->elt[i - 1]);
			}
			return 0;
		}
		else { //si startPos >= endPos
			for (int i = endPos; i <= startPos; i++) {
				printf("%d ", tab->elt[startPos - i]);
			}
			return 0;
		}
	}
}

//supprime des éléments avec compactage du tableau
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab->elt == NULL || tab->eltsCount > tab->size || startPos < 0 || endPos < 0 || startPos > tab->size || endPos > tab->size) {
		return -1;
	}
	else {
		if (startPos <= endPos) {
			for (int i = startPos; i <= tab->size; i++) {
				int temp = tab->elt[i - 1];
				tab->elt[i - 1] = tab->elt[i + endPos - startPos];
				tab->elt[i + endPos - startPos] = temp;
				//on déplace les élements que l'on veut supprimer vers la fin du tableau
			}
			int* tabBis = NULL;
			tab->eltsCount = tab->eltsCount - (endPos - startPos + 1);
			tab->size = tab->size - (endPos - startPos + 1);
			tabBis = (int*)realloc(*tab->elt, (tab->size) * sizeof(int)); //on réalloue la mémoire du tableau avec le nbr d'éléments en tant que nouvelle taille
			if (tabBis == NULL) {
				return -1;
			}
			else {
				tab = tabBis;
				return tab->size;
			}
		}


		else { //si startPos >= endPos
			for (int i = endPos; i <= tab->size; i++) {
				int temp2 = tab->elt[i - 1];
				tab->elt[i - 1] = tab->elt[i + startPos - endPos];
				tab->elt[i + startPos - endPos] = temp2;
				//idem qu'avant mais c'est inversé
			}
			int* tabBis = NULL;
			tab->eltsCount = tab->eltsCount - (startPos - endPos + 1);
			tab->size = tab->size - (startPos - endPos + 1);
			tabBis = (int*)realloc(*tab->elt, (tab->size) * sizeof(int)); //idem
			if (tabBis == NULL) {
				return -1;
			}
			else {
				tab = tabBis;
				return tab->size;
			}
		}
	}
}
