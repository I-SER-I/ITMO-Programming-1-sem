#include <stdio.h>
#include <math.h>

int oct_num, dec_num;
int oct_num_buff, dec_num_buff;
int dis=0;

int main(){
    printf(" ___ L - A - B - A - 3 ___ \n\n");
    printf(" - + - + - + - Exercise 1 and 2 - + - + - + - \n\n");

    printf("Enter the oct number: ");
    scanf("%d", &oct_num);
    oct_num_buff = oct_num;
    while(oct_num_buff > 0){
        dec_num += oct_num_buff % 10 * pow(8, dis);
        oct_num_buff /= 10;
        dis++;
    }
    printf("Your dec number: %d", dec_num);

    printf("\n\n - + - + - + - Exercise 3 - + - + - + - \n\n");

    printf("Your oct number: %d", oct_num);
    dec_num_buff = dec_num;
    dis = oct_num_buff = 0;
    dec_num_buff <<= 1;
    while(dec_num_buff > 0){
        oct_num_buff += dec_num_buff % 8 * pow(10, dis);
        dis++;
        dec_num_buff /= 8;
    }
    printf("\nYour oct number with a shift: %d", oct_num_buff);

    printf("\n\n - + - + - + - Exercise 4 - + - + - + - \n\n");

    printf("Your oct number: %d", oct_num);
    dec_num_buff = ~dec_num;
    dis = oct_num_buff = 0;
    while(abs(dec_num_buff) > 0){
        oct_num_buff += dec_num_buff % 8 * pow(10, dis);
        dis++;
        dec_num_buff /= 8;
    }
    printf("\nYour oct number with a revers: %d", oct_num_buff);

    printf("\n\n - + - + - + - Exercise 5 - + - + - + - \n\n");

    int sec_oct_num;
    int sec_dec_num;
    dis = 0;
    printf("Enter the second oct number: ");
    scanf("%d", &sec_oct_num);
    while(oct_num_buff > 0){
        sec_dec_num += sec_oct_num % 10 * pow(8, dis);
        sec_oct_num /= 10;
        dis++;
    }
    dis = 0;
    dec_num &= sec_dec_num;
    while(dec_num > 0){
        oct_num += dec_num % 8 * pow(10, dis);
        dis++;
        dec_num /= 8;
    }
    printf("Your new oct number: %d\n\n", oct_num);

    printf(" ___ E - N - D - - P - R - O - G - R - A - M - M ___ \n\n");
    return 0;
}
