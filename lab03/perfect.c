// Determining whether a number is a perfect number
// By Bryan Le (bryan.le1248@gmail.com) (Done with Thomas Mei during TutLab)
// 07/03/2021


#include <stdio.h>

int main(void) {

int input_number;
int output_number = 1;
int sum = 0;

    printf("Enter number: ");
    scanf("%d", &input_number);
    printf("The factors of %d are: \n", input_number);
    
    while (input_number >= output_number) {
        if (input_number % output_number == 0) {
            printf("%d\n", output_number);
            sum = sum + output_number;
            }
    output_number = output_number + 1;
    }

printf("Sum of factors = %d\n", sum);
if (input_number == sum - input_number) {
    printf("%d is a perfect number\n", input_number);
    }
else { printf("%d is not a perfect number\n", input_number);
    }
    
    return 0;
}
      
       
            
