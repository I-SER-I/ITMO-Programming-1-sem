#include <stdio.h>
#include <stdlib.h>
int main()
{
    const int n = 4;
    char a[n];
    int i, j;

    printf(" ___ L - A - B - A - 6 ___ \n\n");
    printf(" - + - + - + - Exercise 1 - + - + - + - \n");
    printf("\nAdd values: ");

    for (i = 0; i < n; i++)
        scanf("%c", &a[i]);

    printf("Your values: ");
    for(i = 0; i < n; i++)
        printf("%c", *(a + i));

    printf("\n\n - + - + - + - Exercise 2 - + - + - + - \n");
    char *b;
    b = (char*)malloc(n * sizeof(char));

    printf("\nAdd values: ");
    for (j = 0; j < n; j++)
        scanf("%c", &b[j]);

    printf("Your values: ");
    for (j = 0; j < n; j++)
        printf("%c", *(a + j));

    free(b);

    printf("\n\n ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
