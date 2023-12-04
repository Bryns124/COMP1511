#include <stdio.h>

int main(void) {

    int array[100] = {};
    int scanned_value;
    int size = 0;

    printf("Enter numbers forwards: \n");
    
    while (scanf("%d", &scanned_value) == 1) {
        array[i] = scanned_value;
        size = 0;
        i++;
    }

    printf("Reversed: \n");

    while () {
        i--;
        printf("%d\n", array[i]);
    }

    return 0;
}