#pragma once

int initTab(int* Tab, int size); //fonction qui remplit un tableau d'entiers de taille size avec des z�ros

int afficheTab(int* Tab, int size, int nbElts); //affiche les nbElts premiers �l�ments du tableau sur une ligne

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element); //ajoute un �l�ment dans le tableau, en augmentant la m�moire allou�e si besoin
