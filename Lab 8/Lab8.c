#include <stdio.h>
#include <string.h>
int main(){
    printf(" ___ L - A - B - A - 8 ___ \n\n");

    char str1[100];
    char str2[100];
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    printf("\n - + - + - + - Exercise 1 - + - + - + - \n");

    char buffstr[100];
    strcpy(buffstr, str1);
    printf("\nConcatenation: %s", strcat(buffstr, str2));

    printf("\n\n - + - + - + - Exercise 2 - + - + - + - \n");

    printf("\nStrings are %s", (strcmp(str1, str2)) ? "different" : "same");

    printf("\n\n - + - + - + - Exercise 3 - + - + - + - \n");

    strcpy(str2, str1);
    printf("\nCopying completed");
    printf("\nFirst string: %s", str1);
    printf("\nSecond string: %s", str2);

    printf("\n\n - + - + - + - Exercise 4 - + - + - + - \n");

    printf("\nString length is %d", strlen(str1));

    printf("\n\n - + - + - + - Exercise 5 - + - + - + - \n");

    char key;
    printf("\nWhat symbol will we find?");
    printf("\nAdd symbol: ");
    scanf("%c", &key);
    printf("Your symbol in %d position", strrchr(str1, key) - str1 + 1);


    printf("\n\n ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}