#include <stdio.h>

int main(void) {

    int num_scanned_in;
    int scanned_value;
    int result = 0;

    printf("How many numbers: ");
    scanf("%d", &num_scanned_in);

    int j = 0;
    while (j < num_scanned_in) {
        int i = 0;
        if ((scanf("%d", &scanned_value)) == 1) {
            i++;
        }
        result = result + scanned_value;
        j++;
    }

    printf("The sum is: %d\n", result);

    return 0;
}