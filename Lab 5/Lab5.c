#include <stdio.h>

int num[7] = {10, 20, 30, 40, 50, 60, 70};
int A[2][2] = {1, 2,
               3, 4};
int B[2][2] = {1, 0,
               0, 1};
int C[2][2] = {0};


int main(){
    printf(" ___ L - A - B - A - 5 ___ \n\n");
    printf(" - + - + - + - Exercise 1 - + - + - + - \n");

    for(int i = 0; i < 7; i++)
        printf("\nElement number: %d Value: %d",i,num[i]);

    printf("\n\n - + - + - + - Exercise 2 - + - + - + - \n");

    printf("\nResult: ");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
            C[i][j] += A[i][k] * B[k][j];
    for(int i = 0; i < 2; i++){
        printf("\n");
        for(int j = 0; j < 2; j++)
            printf(" %d ", C[i][j]);
    }
    printf("\n\n ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
