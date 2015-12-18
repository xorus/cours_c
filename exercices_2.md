# Exercices : boucles et conditions

## 1.
nope (8 vs 9)

## 2.
yep

## 3.
```c
int k;
for (k = 100; k <= 100; k++) {
	printf("%c", k)
}
```

## 4.
```c
int somme = 0;
int i;
for (i = 1; i <= 100; i++) {
	somme += i;
}
```

## 5.
```c

int main(void) {
	int i, min, max, somme = 0;

	printf("Entrez min : \n");
	scanf("%d", &min);
	printf("Entrez max : \n");
	scanf("%d", &max);

	if (min >= max) {
		printf("Min doit être plus petit que max !");
		return 1;
	}

	for (i = min; i <= max; i++) {
		somme += i;
	}

	printf("La somme est %d", somme);

	return 0;
}
```

## 6.
```c
int i, somme = 0;
for (i = 1; i <= 100; i += 2) {
	somme += i;
}
```

## 7.
```c
int i;
for (i = 1; i <= 20; i++) {
	printf("%d", i);
	if (i % 3 == 0) {
		printf("\n");
	} else {
		printf(" ");
	}
}
```

### 8.
```c
int factorielle(int n) {
	int i, resultat = 1;

	for (i = n; i > 0; i--) {
		resultat *= i;
	}

	return resultat;
}
```

### 9.
```c
int factorielle(int n) {
	if (n == 0) {
		return 1;
	}

	return factorielle(n - 1) * n;
}
```

### 10.
```c
int n;

printf("Entrez un nombre : ");
scanf("%d", &n);

while (n > 0) {
	printf("%d", n % 10);
	n = n / 10;
}
```

### 11.
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));

    int input, tentatives = 0, maxTentatives = 10, max = 50;
    int nombre = rand() % max;

    do {
    	printf("[%d/%d] Entrez un nombre entre 0 et %d : ",
    			tentatives + 1, maxTentatives, max);
    	scanf("%d", &input);

    	if (input > nombre) {
    		printf("Mon nombre est plus petit\n");
    	} else if (input < nombre) {
    		printf("Mon nombre est plus grand\n");
    	} else {
    		printf("C'est ca !\n");
    		break;
    	}

    	tentatives++;
    } while (tentatives < maxTentatives);

    if (tentatives >= maxTentatives) {
    	printf("Vous n'avez pas trouve :(, mon nombre etait %d", nombre);
    }

	return 0;
}
```

### 12.
```c
int estMultipleDe(int nombre, int multiple) {
	if (nombre % multiple == 0) {
		printf("%d est multiple de %d\n", nombre, multiple);
	} else {
		printf("%d n'est pas multiple de %d\n", nombre, multiple);
	}
}
```