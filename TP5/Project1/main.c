#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAB2SIZE 100
#define TAILLEINITIALE 100

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
	displayElements(&TB, 1, TB.size);

	printf("\n\n");

	//Exercice 2 Question 3
	setElement(&TB, 123, 54);
	displayElements(&TB, 1, TB.size);

	printf("\n\n");

	//Exercice 2 Question 5
	deleteElements(&TB, 1, 120);
	displayElements(&TB, 1, TB.size);

	printf("\n\n");
	system("pause");
}