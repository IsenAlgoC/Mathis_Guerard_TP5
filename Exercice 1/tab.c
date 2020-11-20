#include <stdlib.h>
#include <stdio.h>

//fonction qui remplit un tableau d'entiers de taille size avec des zéros
int initTab(int *Tab, int size) {
	if (*Tab == NULL || size < 0) {
		return -1;
	}
	else {
		*Tab[0] = 0;
		return size;
	}
}