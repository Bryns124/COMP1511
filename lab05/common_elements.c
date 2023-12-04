#include <stdio.h> 

#define LENGTH 6 

int common_elements(int length, int source1[length], int source2[length], int destination[length]);
int main (void) { 
    int source1[LENGTH] = {1, 4, 1, 5, 9, 2};
    int source2[LENGTH] = {1, 1, 8, 2, 5, 3};
    int loop_max;
    int destination[LENGTH] = {};

    common_elements(LENGTH, source1, source2, destination);

    loop_max = common_elements(LENGTH, source1, source2, destination);

    int loop = 0;
    while (loop < loop_max) {
        printf("%d", destination[loop]);
        loop++;
    }
    printf("\n");

    return 0;
}


int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    int x = 0;
    int y = 0;
    int z = 0;
    while (x < length) {
        while (y < length) {
            if (source1[x] == source2[y]) {
                destination[z] = source2[y];
                z++;
                y = length;
            }
            y++;
        }
    y = 0;
    x++; 
    }
    return z;
}
