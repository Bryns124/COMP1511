// Divisible by 3 or 5?
// By Bryan Le (bryan.le1248@gmail.com) (done with Thomas Mei during TutLab)
// 07/03/2021

#include <stdio.h>

int main(void) {

int input_number;
int output_number = 1;

    printf("Enter number: ");
    scanf("%d", &input_number);
    
    while (input_number > output_number) {
        if ((output_number % 5 == 0) || (output_number % 3 == 0)) {
            printf("%d\n", output_number);
        }
        output_number = output_number + 1;
    }
    
    return 0;
}
