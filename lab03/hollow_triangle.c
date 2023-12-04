// Drawing a Hollow Triangle
// By Bryan Le (bryan.le1248@gmail.com)
// 07/03/2021


#include <stdio.h>

int main(void) {

    int size;
    int x = 0;
    int y = 0;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    while (x < size - 1) {
        if (y == 0) {
            printf("*");
            y = y + 1;
            }
            
        while (y < x) {
            printf(" ");
            y = y + 1;
            }
            if (y == x) {
                printf("*\n");
                y = 0;
                x = x + 1;
                }
            else {
                printf("\n");
                x = x + 1;
                y = 0;
                }
        if (x == size - 1)
            while (y < size) {
                printf("*");
                y = y + 1;
                } 
    }
    
    printf("\n");
    
    return 0;

}
