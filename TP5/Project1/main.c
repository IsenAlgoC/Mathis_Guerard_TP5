#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAB2SIZE 100
#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;
	int size;
	int eltsCount;
} TABLEAU;

void main() {

	int MyTab1[10];
	int *MyTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 20;

	//Exercice 1 Question 1

	initTab(MyTab1, 10);
	afficheTab(MyTab1, 10, 10);
	printf("\n\n");

	//Exercice 1 Question 2

	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (MyTab2 != NULL) {
		initTab(MyTab2, tabSize);
		for (int i = 0; i < nbElts; i++) {
			MyTab2[i] = i+1;
		}
		afficheTab(MyTab2, tabSize, nbElts);
	}

	printf("\n\n");
	MyTab2 = ajoutElementDansTableau(MyTab2, &tabSize, &nbElts, 9832);
	afficheTab(MyTab2, tabSize, nbElts);

	free(MyTab2);

	printf("\n\n");

	//Exercice 2 Question 1
	TABLEAU TB = newArray();
	afficheTab(TB.elt, TB.size, TB.eltsCount);


	printf("\n\n");
	system("pause");
}