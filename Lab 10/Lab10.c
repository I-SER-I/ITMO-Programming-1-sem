#include <stdio.h>
#include <math.h>

int LCM(int a, int b){
	int i = 2;
	while(((a % i) && (b % i)) != 0)
		i++;
	return i;
}

int GCD(int a, int b){
	while(a && b)
		if(a >= b)
			a %= b;
		else
			b %= a;
	return a | b;
}

struct Coords{
    float x;
    float y;
};

float Matrix(float x1, float y1, float x2, float y2){
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
};

int main(){
    printf(" ___ L - A - B - A - 10 ___ \n\n");
    printf("\n - + - + - + - Exercise 1 - + - + - + - \n");

	int a, b;
	printf("Enter values: ");
	scanf("%d %d", &a, &b);
	printf("LCM: %d", LCM(a, b));
	printf("\nGCD: %d", GCD(a, b));

    printf("\n\n - + - + - + - Exercise 2 - + - + - + - \n");

    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    struct Coords point[n];
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("Enter %d coords: ", i + 1);
        scanf("%f %f", &point[i].x, &point[i].y);
    }

    printf("\nFrom|To ");
    for(int i = 0; i < n; i++)
        printf("%d\t", i + 1);

    for(int i = 0; i < n; i++){
        printf("\n%d\t", i + 1);
        for(int j = 0; j < n; j++){
            if(i == j)
                printf("X\t");
            else if(i < j)
                printf("%.2f\t", Matrix(point[i].x, point[i].y, point[j].x, point[j].y));
            else
                printf("%.2f\t", -Matrix(point[i].x, point[i].y, point[j].x, point[j].y));
        }
    }

    printf("\n\n ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
