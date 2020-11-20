#include <stdlib.h>
#include <stdio.h>
#include "tab.h"

void main() {

	int MyTab1[10];
	int retour;
	retour = initTab(MyTab1, 10);
	printf("%d", retour);
	printf("\n\n");
	system("pause");
}