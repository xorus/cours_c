# Exercices "Bases du Langage C"
## Ex 1
```
a
a
c
```

## Ex 2
```
on ne sait pas car non initalisé
on ne sait pas car non initalisé
5
```

## Ex 3
```
-2
2
```

## Ex 4
```
0
0
```

## Ex 5
```
3
```

## Ex 6
**Le programme ne compile pas**

## Ex 7
```
10
```

## Ex 8
### A
```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int exo8_a(int r) {
	float perimetre = 2 * M_PI * r;
	printf("Périmètre : %f\n", perimetre);

	float aire = M_PI * pow(r, 2);
	printf("Aire : %f\n", aire);
}
```

### B
```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int exo8_b(int a, int b) {
	float hyp = sqrt(pow(a, 2) + pow(b, 2));
	printf("Hypoténuse : %f\n", hyp);
}
```
