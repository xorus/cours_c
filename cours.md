---
title: Langage C avancé
author: M. Delon
---
Language C
----------
Inventé en 1972 par Denis Ritchie Un des languages haut niveau les plus utilisés (linux,
jeux, ...)

**Avantages :**

-   Comphréension et apprentissage facilité
-   Maintenance des programmes facilité (sauf si tu code comme un porc connard)
-   Portabilité par compilation succéssive (recompiler pour chaque architecture)
-   Language de haut niveau

**Différence language bas niveau - Haut niveau**
```
    haut niveau
    
    Language humain : "if line is ok"
    Language C : "if(line == ok) {}"
    Binaire
    
    bas niveau
```
-   D'autres languages héritent du C

Mon premier programme
---------------------

### 1. La directive \#include

-   Directive envoyée un préprocesseur

    -   `#include <stdio.h>` : gère l’entrée et sortie standard

    Exemple de librairies standard `stdlib.h, math.h, string.h, time.h`

    -   `#include <>` va inclure une librarie standard (dans le dossier du
        compilateur)

    -   `#include ""` va inclure un fichier dans le même répertoire (chemin
        relatif)

-   Organisation des fichiers Un fichier `.h` et Un fichier `.c`

    Le `.c` contient le code associé aux fonctiton du `.h` associé

    ==\> on se retrouve très vite avec beacuoup de fichiers

    **donc** les fichiers doivent avoir le même nom `mestrucs.c` et `mestrucs.h`

    Pro tip : décuoper et faire des putain de dossiers

### 2. La fonction `main()`

C'est le point d'entrée de l'application, tout progrmme C contient un amin, le
prgm s'arrête une fois que les instructions ont terminées

### 3. L'instruction `return`

-   Toutes les fonctions en C permettent de renvoyer une valeur à l'OS

-   Dans le `main()`, le return renvoie une valeur au système d'exploitation :

    `= 0 : Tout s'est bien passé != 0 : Une erreur s'est produite`

### Préprocesseur

![Schéma de compilation](http://i.imgur.com/426qZ7e.png)

|       | Préprocesseur |       | Compilateur |         |            |
|-------|---------------|-------|-------------|---------|------------|
| .h -- | \--\> .c      | \--\> | .o          | \---\\  |            |
| .h -- | \--\> .c      | \--\> | .o          | \----\> | Executable |
| .h -- | \--\> .c      | \--\> | .o          | \---/   |            |

Le tout va créer un éxecutable


Concepts fondamentaux
---------------------

### Constantes et variables
```c
// Constante
const type nom_constante = valeur;

// Variable
type nom_variable = valeur;
```

*Une bonne pratique est de toujours initialiser ses variables dès le début !*
*On ne peut pas savoir ce qu'elle peut contenir si elle n'est pas initialisée.*

### Opérateurs mathématiques
`+` `-` `/` `*` `%` addition, soustraction, division, multiplication, modulo
Exemple : `resultat = var_a + var_b;`

### Structure d'une fonction

#### Définition
```c
int mon_calcul(int a, int b) {
	int resultat = 0;
	resultat = a + b;
	return resultat;
}
```
On explique pour les teubés : 
 - `mon_calcul` c'est le nom de la fonction
 - `(int a, int b)` sont les paramètres de la fonction sous la forme `type nom`. Les paramètres sont séparés par des virgules.
 - `{` (...) `}` le bloc d'instructions

Le type de retour `void` peut être utilisé si la fonction (alors appelée *procédure*) ne renvoie aucune valeur.

#### Utilisation
```c
mon_calcul(12, 13);
int resultat = 0;
resultat = mon_calcul(18, 13);
int var_a = 5;
int var_b = 7;
resultat = mon_calcul(12, var_a);
resultat = mon_calcul(var_a, var_b);
```

### Quelques types de variables
 - `int` pour les nombres entiers
 - `float` pour les nombres réels
 - `char` caractres **attention :** ne contient qu'un seul caractère. Une chaine de caractère est un tableau de char

### Afficher du texte
```c
// Affiche coucou dans la console (sortie standard)
printf("coucou");

// Afficher en utilisant une chaîne de format
printf(chaineDeFormat, paramètre, paramètre, ...);
```

#### Formats
 - `%d` pour un **int**
 - `%f` pour un **float**
 - `%c` pour un **char**

#### Exemples
```c
int var_a = 14;
printf("%d", var_a); // affichera 14

char var_b = 'e';
printf("%d %c", var_a, var_b); // affichera 14 e
``` 

Les entrées sorties standard
-----------------
En C, on a trois flux de base *standard* :

| flux | description | exemple |
|------|-------------|----------------|
|`stdin`| Entrée std. | clavier |
|`stdout`| Sortie std. | écran |
|`stderr`| Sortie d'erreur std. |

### Fonction `getc()`

Permet de lire un caractère sur un flux

#### Exemple

```c
char carac;
carac = getc(stdin);
```

### Fonction `getchar()`

Permet de faire la même chose que `getc(stdin)`

```c
char carac;
carac = getchar()
```

### Fonction `putc()`

Permet d'afficher un caractère sur un flux

#### Exemple
```c
char carac = 'b';
putc(carac, stdout);
// écrit b sur la sortie standard
```

#### Fonction `putchar()`

Comme `putc()` mais uniquement sur `stdout`

#### Exemple
```c
char carac = 'b';
putc(carac);
// écrit b sur la sortie standard
```