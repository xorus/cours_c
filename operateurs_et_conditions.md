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

### Arithmétiques et affectation

```c
x += y; /* revient à faire */ x = x + y;
/* c'est la même chose pour -, *, / et % */
```

### Incrémentation / Décrémentation

Permet d'ajouter ou retrancher un point à une variable

* Incrémentation : `variable++`
* Décrémentation : `variable--`

Attention, les syntaxes `variable++` et `++variable` n'ont pas les même significations :

* Pré incrémentation `++variable` : l'opération à lieu **avant** l'affectation
* Post incrémentation `variable++` : l'opération à lieu **après** l'affectation


### Opérateurs relationnels

| opérateur | signification |
|-----------|---------------|
| `==` | égalité |
| `!=` | différent |
| `>`  | supérieur |
| `<`  | inférieur |
| `<=` | inférieur ou égal |
| `>=` | supérieur ou égal |

### Opérateurs logique

| opérateur | signification |
|-----------|---------------|
| `&&`       | ET |
| `\|\|`     | OU |
| `!`        | NON |

### `if`, `else`

```c
if (condition) {
	// si condition vraie
} else {
	// sinon
}
```

### `else if`

```c
if (condition1) {
	// si condition vraie
} else if (condition2) {
	// si condition 1 est fausse ET condition 2 est vraie
} else {
	// si rien n'est vrai
}
```
