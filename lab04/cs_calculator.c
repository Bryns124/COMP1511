#include <stdio.h>

int main(void) {

    int input_number1;
    int input_number2;
    int input_number3;

    printf("Enter instruction: ");

    while ((scanf("%d %d", &input_number1, &input_number2) == 2)) {

        int result1 = input_number2 * input_number2;

        if (input_number1 == 1) {
            printf("%d\n", result1);
        }

        if (input_number1 == 2) {
            scanf("%d", &input_number3);

            int i = 0;
            int result2 = 1;

            while (i < input_number3) {
                result2 = result2 * input_number2;
                i++;
            }
            printf("%d\n", result2);
        }
        printf("Enter instruction: ");
    }

    return 0;
}