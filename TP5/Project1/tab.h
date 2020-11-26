#pragma once

typedef struct Tableau {
	int* elt; //le tableau d'entiers
	int size; //la taille de ce tableau d'entiers
	int eltsCount; //le nombre d'�l�ments dans le tableau
} TABLEAU;

int initTab(int* Tab, int size); //fonction qui remplit un tableau d'entiers de taille size avec des z�ros

int afficheTab(int* Tab, int size, int nbElts); //affiche les nbElts premiers �l�ments du tableau sur une ligne

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element); //ajoute un �l�ment dans le tableau, en augmentant la m�moire allou�e si besoin

TABLEAU newArray(); //cr�� un nouveau tableau en utilisant la structure TABLEAU, avec une taille initiale pour les donn�es

int incrementArraySize(TABLEAU* tab, int incrementValue); //modifie la taille du tableau en utilisant la structure TABLEAU

int setElement(TABLEAU* tab, int pos, int element); //�crit un �l�ment � une position donn�e sans insertion

int displayElements(TABLEAU* tab, int startPos, int endPos); //affiche une portion du tableau de l'indice de d�but � l'indice de fin

int deleteElements(TABLEAU* tab, int startPos, int endPos); //supprime des �l�ments avec compactage du tableau
