Les énumérations
------------

Les énumérations ne contiennent pas de "sous variables". Il s'agit d'une **liste de valeurs**.

```c
// fichier.h
typedef enum Volume Volume;

enum Volume  {
	FAIBLE, MOYEN, FORT;
};
```

```c
// main.c
int main() {
	Volume son = Volume.MOYEN;
	// exemple d'utilisation
	if (son == Volume.FORT) {
		printf("Bordel de m***e baisse le son!!");
	}
	
	return 0;
}
```

Un truc bien avec les énumérations, c'est qu'on peut préciser des valeurs à côté des noms, par exemple :
```
// ...
enum Volume {
	FAIBLE = 20, MOYEN = 50, FORT = 100;
}
```

Et du coup on peut coder comme des chiens maintenant ! Trop bien :

```c
// main.c
int main() {
	Volume son = Volume.FORT;
	// sale et inutile dans ce cas mais peut être pratique dans
	// le cas d'une énumération par exemple Mois.JANVIER = 1, etc...
	if (son == 100) {
		// en effet, Volume.FORT vaut 100, du coup notre condition fonctionne !
		printf("Bordel de m***e baisse le son!!");
	}
	
	return 0;
}
```

