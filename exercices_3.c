/* Exercices feuille 3 - de 1 à 6 */
#include <stdio.h>
#include <string.h>

int tabLen = 8;
int tab[8] = {12, 15, 13, 10, 8, 9, 13, 14};

void dispTab(int tab[], int len) {
    int i;
    printf("[");
    for (i = 0; i < len; i++) {
        printf("%d", tab[i]);
        if (i < len - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// find value in tab
int f3e1_find() {
    printf("search: ");

    int input;
    scanf("%d", &input);

    int i;
    for (i = 0; i < tabLen; i++) {
        if (tab[i] == input) {
            printf("yup");
            return 1;
        }
    }

    printf("nope");
    return 0;
}

// tab reverse
void f3e2_reverseTab() {
    int tab2[tabLen], i;

    for (i = tabLen - 1; i >= 0; i--) {
        tab2[i] = tab[tabLen - i - 1];
    }

    dispTab(tab2, tabLen);
}

// find last value in tab
int f3e3_findLast() {
    printf("search: ");

    int input, i, foundAt = -1;
    scanf("%d", &input);

    for (i = 0; i < tabLen; i++) {
        if (tab[i] == input) {
            foundAt = i;
        }
    }

    if (foundAt >= 0) {
        printf("last found at index %d", foundAt);
        return 1;
    }

    printf("nope");
    return 0;
}

// find and replace
void f3e4_searchReplace() {
    int search, replace, i;

    printf("Find: ");
    scanf("%d", &search);
    printf("Replace by: ");
    scanf("%d", &replace);

    for (i = 0; i < tabLen; i++) {
        if (tab[i] == search) {
            tab[i] = replace;
        }
    }

    dispTab(tab, tabLen);
}


// swap
void f3e5_swap() {
    int input1, input2, buffer;

    printf("A: ");
    scanf("%d", &input1);
    printf("B: ");
    scanf("%d", &input2);

    buffer = tab[input1];
    tab[input1] = tab[input2];
    tab[input2] = buffer;

    dispTab(tab, tabLen);
}

// tab sort
void f3e6_sort() {
    int i, j;

    // insert sort
    for (i = 0; i < tabLen; i++) {
        int buffer = tab[i];

        for (j = i; j > 0 && tab[j - 1] > buffer; j--) {
            tab[j] = tab[j - 1];
        }

        tab[j] = buffer;
    }

    printf("Ascending sort: ");
    dispTab(tab, tabLen);

    printf("Descending sort: ");
    f3e2_reverseTab();
}


int main() {
    printf("Original tab: ");
    dispTab(tab, tabLen);

//    f3e1_find();
//    f3e2_reverseTab();
//    f3e3_findLast();
//    f3e4_searchReplace();
//    f3e5_swap();
//    f3e6_sort();

    return 0;
}
