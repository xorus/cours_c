# Pointeurs

En C, un pointeur est une varibale contenant une **adresse mémoire**. Cette adresse représente l'espace mémoire ou est référencé la variable.

![la mémoire et les pointeurs](https://user.oc-static.com/files/5001_6000/5160.png)

## Déclaration

Un pointeur sur une variable de type `type` est déclarée de la manière suivante :
```c
type* p_var;
type *p_var;
```

Pro tip : préfixer par un `p` aide à retrouver facilement ses pointeurs quand on lit son code.


### Affectation

Pour récupérer l'adresse mémoire d'une variable, on utilise le symbole `&` :
```c
int maFuckingVar = 1965;
int *p_maFuckingVar; // variable non initialisée
p_maFuckingVar = &maFuckingVar;
```

Exemple :
```c
int a = 2;
int *p = &a; // je crée un pointeur qui référence l'adresse de a
*p = 3; // j'affecte la valeur 3 dans mon pointeur
printf("%d", a); // affichera 3
```

## Opérateurs arithmétiques

`+` et `-` : si on ajoute une valeur à un pointeur, celui-ci se déplace sur le **bloc** mémoire suivant.

Ça peut être utile pour traverser par exemple un tableau, vu que ce dernier est un espace continu en mémoire.

```c
int a = 4;
int *pa = &a;
```
Donc, `pa + 1` représente le bloc mémoire suivant, ici les 4 octets suivants en mémoire
