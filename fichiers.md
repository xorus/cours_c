Fichiers
======

Pour manipuler un fichier, on maipule un pointeur sur la structure *File*.

```c
File* fichier;
```

Une fois initialisé, le pointeur contient l'adresse mémoire du début du fichier.

## 1. Ouverture du fichier

`fopen()` renvoie un pointeur `File` sur le fichier spécifié.

```c
File* fichier = fopen("monFichier.txt", "mode d'ouverture");
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
File* fichier = fopen("fichier.txt", "w");
fclose(fichier); // fermera le fichier
```