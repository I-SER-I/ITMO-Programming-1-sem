#include <stdio.h>
#include "rectangle.h"

int main()
{
    printf(" ___ L - A - B - A - 11 ___ \n\n");
    printf("\n - + - + - + - Exercise 1 - + - + - + - \n");

    struct Rectangle rect;

    printf("Add first coords:  ");
    scanf("%f %f", &rect.x1, &rect.y1);
    printf("Add second coords: ");
    scanf("%f %f", &rect.x2, &rect.y2);
    printf("Perimeter: %f\n", rectanglePerimeter(rect));
    printf("Area: %f\n", rectangleArea(rect));

    printf("\n ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
