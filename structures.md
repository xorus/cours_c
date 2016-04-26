---
title: Langage C avancé : Tableaux
author: M. Delon
---
Structures
----------

Une structure est un ensemble de variables de type différents réunis au sein d'une même entité, à la différence des tableaux où l'ensemble du contenu doit être du même type.


Les structures sont définies dans le fichier `.h`.

**Exemple**

```c
struct MaSuperStructure {
	int variable1; // attention à ne pas oublier les points virguuuul
	int variable2;
	float variable3;
	char[] jeSuisUnFou;
}; // <--- surtout ce point virgule là, on l'oublie tout le temps.
```

Le nom de la structure commence toujours par une **majuscule**.