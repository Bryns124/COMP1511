// exam_q1.c
//
// This program was written by Bryan Le (z5361001)
// on 01/05/2021
//
// This program will compare the values of each pair and return the pair that is decreasing.
#include <stdio.h>

// Return the number of decreasing pairs in the array.
int count_decreasing(int size, int array[size][2]) {
    
    int decreasing_pairs = 0;
    int i = 0;
    while (i < size) {
        if (array[i][0] > array[i][1]) {
            decreasing_pairs++;
        }
        i++;
    }
    return decreasing_pairs;
}

// This is a simple main function which could be used
// to test your count_decreasing function.
// It will not be marked.
// Only your count_decreasing function will be marked.

#define TEST_ARRAY_SIZE 5

int main(void) {
    int test_array[TEST_ARRAY_SIZE][2] = {{16, 7}, {8, 12}, {13, -9}, {-3, 12}, {1, 1}};

    int result = count_decreasing(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}
