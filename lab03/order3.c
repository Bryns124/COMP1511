//Making a program that reads integers and orders them from smallest to largest
//By Bryan Le (bryan.le1248@gmail.com) (worked on it with Thomas Mei during the TutLab)
// 04/03/2021

#include <stdio.h>

int main(void) {
    
    int number_1;
        printf("Enter integer: ");
        scanf("%d", &number_1);
        
    int number_2;
        printf("Enter integer: ");
        scanf("%d", &number_2);
        
    int number_3;
        printf("Enter integer: ");
        scanf("%d", &number_3);
    
    if(number_1 >= number_2 && number_2 >= number_3) {
        printf("The integers in order are: %d %d %d \n", number_3, number_2, number_1);
    }
    
    else if(number_1 >= number_3 && number_3 >= number_2) {
        printf("The integers in order are: %d %d %d \n", number_2, number_3, number_1);
    }
    
    else if(number_2 >= number_1 && number_1 >= number_3) {
        printf("The integers in order are: %d %d %d \n", number_3, number_1, number_2);
    }
    
    else if(number_2 >= number_3 && number_3 >= number_1) {
        printf("The integers in order are: %d %d %d \n", number_1, number_3, number_2);
    }
    
    else if(number_3 >= number_1 && number_1 >= number_2) {
        printf("The integers in order are: %d %d %d \n", number_2, number_1, number_3);
    }
    
    else if(number_3 >= number_2 && number_2 >= number_1) {
        printf("The integers in order are: %d %d %d \n", number_1, number_2, number_3);
    }

    
    return 0;
    }
