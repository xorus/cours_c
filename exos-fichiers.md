## 1.
```c
/**
 * Ecrire un programme permettant de calculer le nombre d’occurrences d’un caractère dans
 * un fichier. Le programme demandera à l’utilisateur de saisir le caractère à compter et
 * affichera en retour le nombre d’occurrences dans le fichier.
 */
void compteCaracs() {
    int count = 0;
    char lookingFor, current;
    printf("Rechercher : ");
    scanf("%c", &lookingFor);

    FILE *file = fopen("fichier.txt", "r");
    while ((current = (char) fgetc(file)) != EOF) {
        if (current == lookingFor) {
            count++;
        }
    }

    printf("Caractère %c trouvé %d fois\n", lookingFor, count);

    fclose(file);
}
```


> Written with [StackEdit](https://stackedit.io/).