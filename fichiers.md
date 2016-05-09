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

