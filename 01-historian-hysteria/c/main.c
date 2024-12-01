#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *) a - *(int *)b);
}

int main() {
    FILE *fptr;
    fptr = fopen("../input.txt", "r");
    char line[255];

    int a[1000];
    int b[1000];
    int n = sizeof(a) / sizeof(a[0]);

    int i = 0;
    while (fgets(line, sizeof(line), fptr) != NULL) {
        char *val1 = strtok(line, " ");
        char *val2 = strtok(NULL, "\n");
        a[i] = atoi(val1);
        b[i] = atoi(val2);
        i++;
    }

    fclose(fptr);

    qsort(a, n, sizeof(int), comp);
    qsort(b, n, sizeof(int), comp);

    int c = 0;
    for (int i = 0; i < n; i++) {
        c += abs(a[i] - b[i]);
    }

    printf("total distance: %d\n", c);

    return 0;
}