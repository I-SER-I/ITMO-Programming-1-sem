#include <stdio.h>

int num;
int result;

int main(){
    printf(" ___ L - A - B - A - 4 ___ \n\n");
    printf(" - + - + - + - Exercise 1 - + - + - + - \n\n");

    printf("Enter the number: ");
    scanf("%d", &num);
    result = ( num >= 1 ) && ( num <= 10);
    printf("Result: %d\n\n", result);

    printf(" - + - + - + - Exercise 2 - + - + - + - \n\n");

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("First bite is: %d\n\n", num%2);
    printf(" ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
