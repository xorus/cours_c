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
|---|---|

On ne peut mettre qu'un seul mode à la fois.

Pour pouvoir par exemple 