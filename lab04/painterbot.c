#include <stdio.h>

int main(void) {
    int indices[36] = {};
    int i = 0;
    int j;
    
    while ((scanf("%d", &j) == 1)) {
        indices[j] = 1;
    }

    while (i < 36) {
        printf("%d", indices[i]);
        i++;
    }

    printf("\n");

    return 0;
}