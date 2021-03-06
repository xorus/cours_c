Structures
----------

Une structure est un ensemble de variables de type différents réunis au sein d'une même entité, à la différence des tableaux où l'ensemble du contenu doit être du même type.


Les structures sont définies dans le fichier `.h`.

**Exemple**

Le nom de la structure commence toujours par une **majuscule**.

```c
struct MaSuperStructure {
	int variable1; // attention à ne pas oublier les points virguuuul
	int variable2;
	float variable3;
	char[] jeSuisUnFou;
}; // <--- surtout ce point virgule là, on l'oublie tout le temps.
```

### Exemple : point

#### Déclaration simple

**Dans le fichier `.h`**

```c
struct Point {
	int x;
	int y;
};
```

**Dans le fichier `.c`**

```c
#include "monfichier.h"

int main() {
	struct Point point_a; // struct Point ==> le type de la donnée "point_a"
}
```

#### Avec les alias `typedef`

L'instruction `typedef` permet de créer un alias à partir d'un type de données.

Syntaxe : `typedef TYPE_A_REMPLACER ALIAS`, ici par exemple `typedef struct Point Point`.

**Dans le `.h`**

```c
struct Point {
	int x;
	int y;
};

typedef struct Point Point;
```

**Dans le fichier `.c`**

```c
#include "monfichier.h"

int main() {
	Point point_a; // WOAW SUCH RACCOURCI!
	
	// Utilisation : affectation
	point_a.x = 14;
	point_a.y = 21;
}
```

## Initialisation

```c
Point point_a = {13, 17}
// REVIENT À FAIRE :
Point point_a;
point_a.x = 13;
point_a.y = 17;
```

Le raccourci peut être pratique mais **attention à l'ordre** ! L'index 0 ira à la première variable, la 1 à la seconde, etc.

## Pointeurs de structures

Un pointeur se crée de la même manière que des pointeurs sur d'autres types de données :

```c
Point* point_a = NULL
```

BAM! Pointeur sur une structure, le futur, c'est maintenant.

Pour envoyer une structure à une fonction, on utilise l'adresse de cette structure :

```c
void initialiserStructure(Point* pPoint) {
	// initialiser le corps de la structure
	// Pour agir sur un élément d'une structure passée en pointeur :
	(*pPoint).x = 0;
	// Parce que c'est pas très pratique comme écriture, on peut faire ça :
	pPoint->x = 0;
}

int main() {
	Point monPoing;
	initialiserStructure(&monPoing);
}
```

**Attention** : l'opérateur `->` n'existe que dans le cas d'un pointeur sur une structure.

Donc, pour manipuler un pointeur de structure, on peut soit faire `(*pointeurStructure).truc` soit `pointeurStructure->truc`.

La suite...

[&raquo; Les énumérations](enumerations.md)