// exam_q3.c
//
// This program was written by Bryan Le (z5361001)
// on 01/05/2021
//
// One line summary of what this exercise does.
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int array[999] = {};
    int a = 0;
    int b = 0;
    int min_distance = b;
    while (scanf("%d", &array[a]) == 1) {
        a++;
        b++;
    }
    int distance_count = 0;
    int i = 0;
    while (i < b) {
        int j = 0;
        distance_count = 0;
        j = i;
        while (j < b) {
            if (j != i) {
                if (array[i] == array[j]) {
                    min_distance = j - i;
                }
            }
            distance_count++;
            j++;
        }
        i++;
    }
    printf("The minimum distance was: %d\n", min_distance);
	return 0;
}
