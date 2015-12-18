---
title: Langage C avancé : Opérateurs et traitements conditionnels
author: M. Delon
---
Opérateurs et traitements conditionnels
----------

### Opérateur d'affectation (`=`)
```
Opérande gauche = opérande droite
```
Cela signigie que ce qui est a gauche prend la valeur de ce qui est à droite

```c
A = 5; // A prend la valeur 5
A = B = 5; // B prend la valeur 5, A prend la valeur de B (donc 5)
A = B = C = D = 0; // tout le monde a zéro ! :D
```

### Conversion (cast)

Permet de modifier le type d'une donnée

`(type) variable`

#### Exemple
```c
float pi = 3.14;
int partie_entiere;

partie_entiere = (int) pi;
// partie_entiere vaudra 3,
// faire (int) convertira mon float en int, supprimant les décimales
```