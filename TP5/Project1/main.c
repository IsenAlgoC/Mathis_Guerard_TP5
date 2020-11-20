#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

#define TAB2SIZE 100

void main() {

	int MyTab1[10];
	int *MyTab2 = NULL;
	int tabSize = TAB2SIZE;
	int nbElts = 100;

	initTab(MyTab1, 10);
	afficheTab(MyTab1, 10, 10);
	printf("\n\n");

	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));
	if (MyTab2 != NULL) {
		initTab(MyTab2, tabSize);
		for (int i = 0; i < nbElts; i++) {
			MyTab2[i] = i+1;
		}
		MyTab2 = ajoutElementDansTableau(MyTab2, &tabSize, &nbElts, 9000);
		afficheTab(MyTab2, tabSize, nbElts);
	}
	free(MyTab2);



	printf("\n\n");
	system("pause");
}