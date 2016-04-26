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

