#pragma once

int initTab(int* Tab, int size); //fonction qui remplit un tableau d'entiers de taille size avec des zéros

int afficheTab(int* Tab, int size, int nbElts); //affiche les nbElts premiers éléments du tableau sur une ligne

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element); //ajoute un élément dans le tableau, en augmentant la mémoire allouée si besoin
