---
title: Langage C avancé : Tableaux
author: M. Delon
---
Tableaux et chaînes de caractères
----------

## Tableaux

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
int var_a = tab[0];
```

Alternative pour assigner le premier élément du tableau à une variable :
```c
int var_a = tab;
```
**Le nom du tableau pointe sur son premier élément** : donc, `var_a` vaudra ici `tab[0]`;

### Exercice
Déclarer un tableau de 10 entiers et l'initialiser à l'aide d'une boucle
```c
int tab[10], i;

for (i = 0; i < 10; i++) {
	tab[i] = 0;
}
```

## Chaînes de caractère
En C, une chaîne de caractères et représentée par un tableau de caractères terminée par un caractère null : `\0`.

```c
char maChaine[7] = {'H','e','l','l','o','!','\0'};
```
**Attention à ne pas oublier le \0 lors de ce type d'initialisation de chaîne**

```c
char maChaine[7] = "Hello!";
```
Et oui, `""` représente un chaîne de caractères, qui est un tableau !
Le \0 est ajouté automatiquement, magique !

```c
char maChaine[] = "Hello!";
```
La taille du tableau n'est pas connue à l'avance, on peut **pas** la récupérer sans parcourir le tableau jusqu'à tomber sur le `\0`. (il n'y à pas d'attribut qui donne la taille d'un tableau)

---

**Cela ne fonctionne pas :**
```c
char str[4] = "texte";
```
En effet, on essaye de mettre une chaîne de taille 6 dans un tableau de taille 4 : les caractères en trop sont `e` et `\0`. (rappel : `"texte"` <=> `{'t', 'e', 'x', 't', 'e', '\0'}`)


