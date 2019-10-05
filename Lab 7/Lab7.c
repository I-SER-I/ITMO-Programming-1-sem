#include <stdio.h>
#include <math.h>

enum DaysOfWeek{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

struct Obj{
    int x0, y0, x1, y1, x2, y2, x3, y3;
    int S;
    int P;
};

struct MP3{
    unsigned Play  : 1;
    unsigned Pause: 1;
    unsigned REC : 1;
};

int main(){
    printf(" ___ L - A - B - A - 7 ___ \n\n");
    printf(" - + - + - + - Exercise 1 - + - + - + - \n");

    int day;
    day = Monday;
    printf("\nYour day is: %d - it is Monday", day);

    printf("\n\n - + - + - + - Exercise 2 - + - + - + - \n");

    struct Obj Rect;
    printf("\nYour figure is a rectangle: ");
    printf("\nAdd coordinates:\n");
    printf("   ");
    scanf("  %d %d", &(Rect.x0), &(Rect.y0));
    printf("   ");
    scanf("  %d %d", &(Rect.x1), &(Rect.y1));
    printf("   ");
    scanf("  %d %d", &(Rect.x2), &(Rect.y2));
    printf("   ");
    scanf("  %d %d", &(Rect.x3), &(Rect.y3));
    Rect.P = 2 * (sqrt((Rect.x0 - Rect.x1)*(Rect.x0 - Rect.x1) + (Rect.y0 - Rect.y1)*(Rect.y0 - Rect.y1)) + sqrt((Rect.x1 - Rect.x2)*(Rect.x1 - Rect.x2) + (Rect.y1 - Rect.y2)*(Rect.y1 - Rect.y2)));
    Rect.S = sqrt((Rect.x0 - Rect.x1)*(Rect.x0 - Rect.x1) + (Rect.y0 - Rect.y1)*(Rect.y0 - Rect.y1)) * sqrt((Rect.x1 - Rect.x2)*(Rect.x1 - Rect.x2) + (Rect.y1 - Rect.y2)*(Rect.y1 - Rect.y2));
    printf("Perimeter: %d", Rect.P);
    printf("\nArea: %d", Rect.S);

    printf("\n\n - + - + - + - Exercise 3 - + - + - + - \n");

    struct MP3 Status;
    printf("\nAdd hex number: ");
    scanf("%x", &(Status));
    printf("MP3 status:");
    printf("\n  Play:   %s", (Status.Play) ? "ON" : "OFF");
    printf("\n  Pause:  %s", (Status.Pause) ? "ON" : "OFF");
    printf("\n  REC:    %s", (Status.REC) ? "ON" : "OFF");

    printf("\n\n ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
