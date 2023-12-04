// Prints the first n digits of pi, where n is specified 
// by Bryan Le (bryan.le1248@gmail.com)


#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int input_digits;
    printf ("How many digits of pi would you like to print? ");
    scanf ("%d", &input_digits);
    
    int i = 0;
    while (i < input_digits) {
        if (i == 1) {
            printf(".");
        }    
        printf("%d", pi[i]);
        i++;
    }
 
    
    printf("\n");

    return 0;
}
