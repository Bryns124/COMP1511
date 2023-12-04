// Taking two pointers to integers as input and swapping the values stored in those two integers.
// by Bryan Le
// 18/03/2021 

#include <stdio.h>

void swap_pointers(int *a, int *b);

// This is a simple main function which could be used
// to test your swap_pointers function.
// It will not be marked.
// Only your swap_pointers function will be marked.

int main(void) {
    int first = 1;
    int second = 2;
    
    //calls the function swap_pointers and its job to to swap the first and the second around.
    swap_pointers(&first, &second);
    
    printf("%d, %d\n", first, second);
    return 0;
}

// swap the values in two integers, given as pointers
void swap_pointers(int *a, int *b) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int x = *a;
    *a = *b;
    *b = x;
}
