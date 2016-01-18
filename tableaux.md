---
title: Langage C avancé : Tableaux
author: M. Delon
---
Tableaux
----------

Les tableaux sont des ensembles de variables de -même types, stockés dans un **espace contigu** en mémoire.

```c
type nom_tab[taille];
int tab[4] = {2, 4, 6, 8};
```

Les indexes commencent par zéro : ici, 2 est à l'index 0, 4 à l'index 1, etc.

```c
int var = tab[2];
```
Ici, var prend la valeur de la troisième entrée du tableau `tab`.


```c
tab[2] = 45;
printd("%d", tab[2]); // affiche 45
```


