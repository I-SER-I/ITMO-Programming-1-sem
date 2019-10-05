#include <stdio.h>

int main(){
    printf(" ___ L - A - B - A - 9 ___ \n\n");

    printf("\n - + - + - + - Exercise 1 - + - + - + - \n");

    int upper = 0, lower = 0, digit = 0, i = 0;
    char str[100];
    printf("\nAdd string: ");
    gets(str);
    for(i = 0; i < strlen(str); i++){
        if(isdigit(str[i]))
            digit++;
        else if(isupper(str[i]))
            upper++;
        else if(islower(str[i]))
            lower++;
    }
    printf("\nNumber of numbers: %d", digit);
    printf("\nNumber of upper register: %d", upper);
    printf("\nNumber of lower register: %d", lower);

    printf("\n\n - + - + - + - Exercise 2 - + - + - + - \n");

    int tariff_price, minutes, cost_per_minute;
    printf("Add tariff price: ");
    scanf("%d", &tariff_price);
    printf("Add number of minutes: ");
    scanf("%d", &minutes);
    printf("Add cost per 1 minute: ");
    scanf("%d", &cost_per_minute);
    int full_price = tariff_price;
    if(minutes > 499)
        full_price += (minutes - 499) * cost_per_minute;
    printf("Full price id: %d", full_price);

    printf("\n\n ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
