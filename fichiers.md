Fichiers
======

Pour manipuler un fichier, on maipule un pointeur sur la structure *FILE*.

```c
FILE* fichier;
```

Une fois initialisé, le pointeur contient l'adresse mémoire du début du fichier.

## 1. Ouverture du fichier

`fopen()` renvoie un pointeur `FILE` sur le fichier spécifié.

```c
FILE* fichier = fopen("monFichier.txt", "mode d'ouverture");
```

**Attention**, sur windows, les `\` dans les chemins de fichier deviennent des `/`.

### Mode d'ouverture de fichiers
| mode | ce que ça fait |
|---|---|
| r | Read : Lecture seule, si le fichier n'existe pas, il est crée |
| w | Write : Écriture, si le fiichier n'existe pas, il est crée. Si il existe déjà, il est *écrasé*. |
| a | Append : Écriture, fichier crée si non existant, contenu ajouté à la fin si déja existant |

On ne peut mettre qu'un seul mode à la fois.

Pour pouvoir par exemple ouvrir un fichier en lecture et en écriture, on peut utiliser des variations : 

| mode | ce que ça fait |
|---|---|
| r+ | Lecture/Écriture : le fichier doit déjà exister |
| w+ | Lecture/Écriture : fichier écrasé si déjà existant |
| a+ | Lecture/Écriture : contenu ajouté à la fin |

Donc Read : lit, Write : écrase, Append : ajoute, et **+** pour faire la même chose mais avec en bonus la lecture / écriture.

## Fermeture des fichiers

**Tout** fichier ouvert doit être fermé après son utilisation :

1. Remettre le fichier à disposition d'autres programmes
2. Pour libérer l'espace mémoire occupé (il fait automatiquement des free sur ses pointeurs

On utilise pour cela la fonction `fclose(fichier)`. Où fichier est un pointeur sur le fichier à fermer.

```c
FILE* fichier = fopen("fichier.txt", "w");
fclose(fichier); // fermera le fichier
```

## 3. Écrire dans un fichier

Pour écrire, il existe trois fonctions :

-  `fputc()` : écrit **un caractère**
- `fputs()` :  écrit une **chaîne de caractères**
- `fprintf()` : écrit une **chaîne de caractères** (formatée, comme printf)

```c
FILE* fichier = fopen("fichier.txt", "w");
int variable = 69;

// Écrire HEY avec fputc
fputc('H', fichier);
fputc('E', fichier);
fputc('Y', fichier);

// Écrire Coucou avec fputs
fputs("Coucou", fichier);

// Acrobaties
fprintf("Un nombre au pif : %d", fichier, variable);

fclose(fichier);
```

## 4. Lire dans un fichier

- `fgetc()` : lit un caractère
- `fgets()` : lit une chaine de caractères (tableau de caractères)
- `fscanf()` : lit une chaîne formatée (comme un scanf)

### Vérifier que le fichier est bien ouvert
```c
if (fichier != NULL) {
  // le fichier est ouvert
} else {
  // on à pas pu ouvrir le fichier, le pointeur est NULL
}
```

### `fgetc()`
Renvoie un nombre entier : le caractère lu.

Si il n'y à un à lire, la fonction renvoie EOF (pour End Of File).

```c
FILE *fichier = fopen("fichier", "r");
char carac;

do {
	carac = fgetc(fichier);
	fprintf("%c", carac);
} while (carac != EOF);

// ou (n'affichera pas le symbole ? sous UNIX)
while ((carac = fgetc(file)) != EOF) {
    printf("%c", carac);
};
```


### `fgets()`

Renvoie un pointeur NULL si il n'a plus rien à lire.

```c
FILE *fichier = fopen("fichier", "r");
int taille_tampon = 500; // lire par paquets de 500 caractères max
char chaine[500] = {'\0'}; // on initialise avec le caractère nul

if (FILE == NULL) {
	printf("Impossible d'ouvrir le fichier.");
	return;
}

fgets(chaine, taille_tampon, fichier);
printf("%s", chaine);
```

Inconvénient : cela ne lira que 500 caractères. On doit boucler !

```c
FILE *fichier = fopen("fichier", "r");
int taille_tampon = 500;
char chaine[500] = {'\0'};

while (fgets(chaine, taille_tampon, fichier) != NULL) {
    printf("%s", chaine);
}
```

### `fscanf()`

C'est comme un scanf !

`fscanf(fichier, "%d", &age);` lira un entier du fichier et l'enregistrera dans age.

`fscanf` ne lit que ligne par ligne : il s'arrête quand il rencontre une fin de ligne (\n).


## 5. Manipulation du curseur

Toutes le fonctions de lecture/écriture vues précédemment manipulent automatiquement un *curseur virtuel*.

Il existe trois fonctions pour manipuler ce curseur : 

- `ftell()` : indique la position du curseur dans le fichier
- `fseek()` : repositionne le curseur à un endroit précis dans le fichier
- `rewind()` : remet le curseur au début du fichier

Position du curseur :
```c
long position = ftell(fichier);
```

Déplacer le curseur :
```c
fseek(fichier, deplacement, position);
```
Fichier: pointeur de fichier
Deplacement: nb positif ou négatif représentant le déplacement (négatif = en arrière, positif = en avant)
Position (long) : positino à partir de la quelle on se déplace

| Constante pour position | Description |
| -- | -- |
| SEEK_SET | début du fichier |
| SEEL_CUR | position actuelle |
| SEEK_END| fin du fichier |

Revenir au début du fichier :
```c
rewind(fichier); 
```

