#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TABSIZE 10

//fonction qui remplit un tableau d'entiers de taille size avec des zéros
int initTab(int* Tab, int size) {
	if (*Tab == NULL || size < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < TABSIZE; i++) {
			*Tab[i] = 0;
		}
		return size;
	}
}