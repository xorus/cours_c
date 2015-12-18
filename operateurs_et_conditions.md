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

### `switch`

```c
int age = 29;

switch (age) {
	case 18: 
		// mon code age = 18
	break;
	case 20: 
		// mon code age = 20
	break;
	default:
		// pour tous les autres cas
	break;
}
```

**Le default est obligatoire** : on peut avoir aucun case mais il faut un default

### Ternaire

```c
(condition_a_evaluer) ? action si vrai : action si faux;
```

#### Exemple
```c
int resultat, valeur = 12;

resultat = (valeur > 10) ? 4 : 3;
// cette ligne revient à faire :
if (valeur > 10) {
	resultat = 4;
} else {
	resultat = 3;
}
```

## Boucles
### `for`
`for(expression1, expression2, expression3)`

**expression1** n'est traité qu'une seule fois : elle permet généralement d’initialiser une ou plusieurs variables

**expression2** est évaluée à chaque itération : c'est la condition d'arrêt

Si son résultat vaut 0 ==\> on sort de la boucle !

**expression3** n'est pas évaluée au premier passage

Évaluée *avant* d'évaluer l'expression 2 !

### `while`
```c
while (expression) {
	// ...
}
```

L'évaluation de l'expression détermine le passage ou non la boucle.

Si le résultat de l'expression est : 

* `> 0` on passe dans la boucle
* `== 0` on sort de la boucle



### `do` ... `while`
```c
do {
	// ...
} while (expression);
```

Attention à ne pas oublier le `;` !

Le bloc d'instructions est évaluée avant l'expression, l'intérêt de cette structure est de passer toujours **au moins une fois** dans la boucle.