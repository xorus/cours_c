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

Taille dynamique d'un tableau de int :
```c
int size = sizeof(tab) / sizeof(int);
```

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

## Gestion des chaînes de caractères
### string.h
```c
#include <string.h>
```
#### **strlen** : renvoie la longueur d'une chaine
C'est aussi le **nombre d'octets** occupé par cette chaine. En C, 1 `char` = 1 octet

```c
size_t taille = strlen(ma_chaine)
```

**Attention** : Strlen ne renvoie pas un `int` mais un `size_t`.

`size_t` est un **type de données** défini dans la librairie standard, il peut **varier** d'une machine à l'autre.


#### **strcpy** : copie une chaîne de caractère
Usage :
```c
strcpy(chaîne_destination, chaîne_origine);
```
Exemple :
```c
char origine[6] = "Texte";
char destination[6];
strcpy(destination, origine);
```

## Lire et écrire une chaîne de caractères
```c
// lecture
char array_ch[80];
scanf("%s", array_ch);

// affichage
printf("%s", array_ch);
printf("%s\n", array_ch);
// équivalent à :
puts(array_ch);
```
`puts` remplace le caractère de fin de la chaîne par un `\n`.
