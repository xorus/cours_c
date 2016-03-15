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

# Tableaux

Une déclaration d'un tableau de N éléments revient à réserver un espace mémoire permettant de stocker N variables de même type sur des espaces contigus.

- `int tab[2]` permet de réserver l'espace pour stocker deux entiers
- En réalité, `tab` contient le premier élément (`tab[0]`)
- `*tab` permet de récupérer la valeur du premier élément
- `tab + 1` représente l'adresse du deuxième élément du tableau
- `*(tab + 1)` valeur du deuxième élément

# Passage par valeur vs par référence

## Par valeur
Lors de l'appel de la fonction, on lui transmet une copie des valeurs.
```c
void maFonction(int a, int b) {
	a = 100 * a;
	b = b / 3;
}

main () {
	int x = 10, y = 20;
	maFonction(x, y);
	printf("%d, %d", x, y);
}
```

## Par référence
Lors de l'appel de la fonction, on lui transmet les adresses des variables contenant les valeurs.

```c
void maFonction(int *a, int *b) {
	*a = 100 * (*a);
	*b = (*b) / 3;
}

main () {
	int x = 10, y = 20;
	maFonction(&x, &y);
	printf("%d, %d", x, y);
}
```

# Allocation dynamique de mémoire

Pour allouer de la mémoire en C, on utilise la fonction `malloc()`

* Elle réserve un nombre d'octets contigus en mémoire
* Elle renvoie un pointeur sur cet espace commun
* Elle renvoie NULL sis échec lors de l'allocation

**Attention !** Il faut toujours tester la non nullité avant de manipuler le pointeur.
