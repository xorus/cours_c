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