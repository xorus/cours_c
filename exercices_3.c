#include <stdio.h>
#include <string.h>
#include <limits.h>

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

/* PART 2 */

int f3e7_isPalindrome(char string[], int strLen) {
    int i;
    char stringRev[strLen];

    for (i = 0; i < strLen - 1; i++) {
        stringRev[i] = string[strLen - i - 2];
    }
    stringRev[strLen - 1] = '\0';

    return (strcmp(string, stringRev) == 0) ? 1 : 0;
}

int f3e8_strLen(char string[]) {
    int i = 0;
    for (; i < INT_MAX; i++) {
        if (string[i] == '\0') {
            return i;
        }
    }

    return 0;
}

void f3e8() {
    char str[100];
    printf("Input string: ");
    gets(str);
    printf("Length: %d", f3e8_strLen(str));
}

void f3e9_strConcat(char *output, char str1[], char str2[]) {
    int i, offset;
    for (i = 0; i < f3e8_strLen(str1); i++) {
        output[i] = str1[i];
    }
    offset = i;
    for (i = 0; i < f3e8_strLen(str2); i++) {
        output[i + offset] = str2[i];
    }
}

void f3e9() {
    char str1[100], str2[100], output[200];
    gets(str1);
    gets(str2);
    f3e9_strConcat(output, str1, str2);
    printf("%s", output);
}

int f3e10_strEquals(char str1[], char str2[]) {
    int len1 = f3e8_strLen(str1);
    int len2 = f3e8_strLen(str2);

    if (len1 != len2) {
        return 0;
    }

    int i;
    for (i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }

    return 1;
}

void f3e10() {
    char str1[100], str2[100];
    printf("1: ");
    scanf("%s", str1);
    printf("2: ");
    scanf("%s", str2);
    printf("%d", f3e10_strEquals(str1, str2));
}

int f3e10_strEqualsLim(char str1[], char str2[], int limit) {
    int len1 = f3e8_strLen(str1);
    int len2 = f3e8_strLen(str2);

    if (limit > len1 && limit > len2 && len1 != len2) {
        return 0;
    }

    if (limit > len1) {
        limit = len1;
    }

    int i;
    for (i = 0; i < limit; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }

    return 1;
}

void f3e11() {
    char str1[100], str2[100];
    int input;

    printf("str1: ");
    scanf("%s", str1);
    printf("str2: ");
    scanf("%s", str2);
    printf("int: ");
    scanf("%d", &input);

    printf("%d", f3e10_strEqualsLim(str1, str2, input));
}

int f3e12_strStr(char needle[], char haystack[]) {
    int lenN = f3e8_strLen(needle);
    int lenH = f3e8_strLen(haystack);
    int i, matchCount = 0;

    for (i = 0; i < lenH; i++) {
        if (lenH < lenN + i) {
            return -1;
        }

        if (haystack[i] == needle[matchCount]) {
            matchCount++;
        } else {
            matchCount = 0;
        }

        if (matchCount == lenN) {
            return i - matchCount + 1;
        }
    }

    return -1;
}

int f3e12_strFind(char needle[], char haystack[]) {
    return f3e12_strStr(needle, haystack) >= 0 ? 1 : 0;
}

void f3e12() {
    char str1[100], str2[100];

    printf("str1: ");
    scanf("%s", str1);
    printf("str2: ");
    scanf("%s", str2);


    printf("%d", f3e12_strFind(str2, str1));
}

void f3e13_strOffset(char *string, char offset) {
    int i;
    for (i = 0; i < f3e8_strLen(string); i++) {
        string[i] = string[i] + offset;
    }
}

void f3e13() {
    char str[100];

    printf("input: ");
    scanf("%s", str);

    f3e13_strOffset(str, -32);
    printf("%s", str);
}

void f3e14() {
    char str[100];

    printf("input: ");
    scanf("%s", str);

    f3e13_strOffset(str, 32);
    printf("%s", str);
}

void f3e15() {
    char str[100];

    printf("input: ");
    scanf("%s", str);

    char *lim = strstr(str, "er");
    if (lim != NULL) {
        strcpy(lim, "\0");

        printf("je %se\n", str);
        printf("tu %ses\n", str);
        printf("il %se\n", str);
        printf("nous %sons\n", str);
        printf("vous %sez\n", str);
        printf("ils %sent\n", str);
    }

    printf("%s", str);
}

void f3e16() {
    char str1[100], str2[100];

    printf("str1: ");
    scanf("%s", str1);
    printf("str2: ");
    scanf("%s", str2);

    int mid1 = f3e8_strLen(str1) / 2;
    int mid2 = f3e8_strLen(str2) / 2;

    strcpy(&str1[mid1], "\0");

    char *str3 = strcat(str1, &str2[mid2]);

    printf("%s", str3);
}

void part1() {
    printf("Original tab: ");
    dispTab(tab, tabLen);

//    f3e1_find();
//    f3e2_reverseTab();
//    f3e3_findLast();
//    f3e4_searchReplace();
//    f3e5_swap();
//    f3e6_sort();
}

int main() {
//    part1();

//    printf("%d", f3e7_isPalindrome("laval", 6));
//    f3e8();
//    f3e9();
//    f3e10();
//    f3e11();
//    f3e12();
//    f3e13();
//    f3e14();
//    f3e15();
//    f3e16();

    return 0;
}
