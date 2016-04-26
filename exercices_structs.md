# Ex 1.
Création d'une variable data de type t_data.

Si c'était un struct : 
data.i = 10
data.f = 220.5
data.str = "Mobylette"

On affiche 10, on affiche 220.5, on affiche Mobylette.

Comme c'est une union :
On assigne d'abord un int, l'espace mémoire de l'union contient donc un int. Puis on écrit par dessus un float, et enfin on écrase enore par un string.
Au final, on affiche :
data.i : {M sous forme de int}
data.f : {M sous forme de float}
data.str : Mobylette

# Ex 2
```c
typedef struct Heure {
    int hours;
    int minutes;
    int seconds;
} Heure;
```
```c
#include <stdio.h>
#include "exo.h"

int heureEnSecondes(Heure heure) {
    int seconds = heure.seconds
                  + heure.minutes * 60
                  + heure.hours * 3600;

    return seconds;
}

Heure secondesEnHeure(int seconds) {
    Heure heure;
    heure.hours = seconds / 3600 % 24;
    heure.minutes = seconds / 60 % 60;
    heure.seconds = seconds % 60;

    return heure;
}

Heure additionHeure(Heure h1, Heure h2) {
    Heure h3;
    h3.seconds = (h1.seconds + h2.seconds) % 60;
    h3.minutes = ((h1.minutes + h2.minutes)
                  + (h1.seconds + h2.seconds) / 60) % 60;
    h3.hours = ((h1.hours + h2.hours)
                + (h1.minutes + h2.minutes) / 60) % 60;

    return h3;
}

void afficheHeure(Heure h) {
    printf("%dh, %dmn et %ds\n", h.hours, h.minutes, h.seconds);
}

void ex02() {
    Heure a = {12, 30, 00};
    Heure b = {00, 30, 00};
    Heure c = {00, 00, 40};

    afficheHeure(a);
    afficheHeure(b);
    afficheHeure(c);

    printf("%d\n", heureEnSecondes(a));
    printf("%d\n", heureEnSecondes(b));
    printf("%d\n", heureEnSecondes(c));

    afficheHeure(secondesEnHeure(47));
    afficheHeure(secondesEnHeure(179));
    afficheHeure(secondesEnHeure(666));
    afficheHeure(secondesEnHeure(3600));
    afficheHeure(secondesEnHeure(3611));

    afficheHeure(additionHeure(a, b));
    afficheHeure(additionHeure(secondesEnHeure(60), secondesEnHeure(170)));
}
```

# Ex 3
```c
typedef struct {
    int x, y, cote;
} t_carre;

typedef struct {
    int x, y, longueur, largeur;
} t_rectangle;
```

```c
#include <stdio.h>
#include <malloc.h>
#include "exo.h"

void carre_creer(t_carre *self, int x, int y, int longueur_cote) {
    self->x = x;
    self->y = y;
    self->cote = longueur_cote;
}

void carre_detruire(t_carre *self) {
    free(self);
}

void carre_afficher(t_carre *self) {
    printf("Carré:\n");
    printf("haut gauche : (%d; %d)\n", self->x, self->y);
    printf("haut droite : (%d; %d)\n", self->x + self->cote, self->y);
    printf(" bas gauche : (%d; %d)\n", self->x + self->cote, self->y + self->cote);
    printf(" bas droite : (%d; %d)\n", self->x, self->y + self->cote);
}

void rectangle_afficher(t_rectangle *self) {
    printf("Rect:\n");
    printf("haut gauche : (%d; %d)\n", self->x, self->y);
    printf("haut droite : (%d; %d)\n", self->x + self->largeur, self->y);
    printf(" bas gauche : (%d; %d)\n", self->x + self->largeur, self->y + self->longueur);
    printf(" bas droite : (%d; %d)\n", self->x, self->y + self->longueur);
}

void carre_aire(t_carre *self) {
    printf("Aire du carré : %d\n", self->cote * self->cote);
}

void rectangle_aire(t_rectangle *self) {
    printf("Aire du rectangle : %d\n", self->longueur * self->largeur);
}

void ex03() {
    t_carre* carre = malloc(sizeof(t_carre));
    t_rectangle rectangle = {10, 4, 10, 5};

    carre_creer(carre, 10, 15, 50);
    carre_afficher(carre);
    rectangle_afficher(&rectangle);

    carre_aire(carre);
    rectangle_aire(&rectangle);

    carre_detruire(carre);
}
```

# Pointeurs avancés
## Ex 1
```c
int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("pas d'arguments, connard.");
        return -1;
    }

    int tab[argc - 1];
    int i;

    for (i = 1; i < argc; i++) {
        tab[argc - i - 1] = atoi(argv[i]);
    }

    printf("Affichage:\n");
    for (i = 0; i < argc - 1; i++) {
        printf("%d ", tab[i]);
    }

    return 0;
}
```