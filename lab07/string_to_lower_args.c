#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 1;
    while (i < argc) {
        int j = 0;
        while (argv[i][j] != '\0') {
            if (argv[i][j] >= 'A' && argv[i][j] <= 'Z') {
                argv[i][j] = argv[i][j] + 32;
            }
            putchar(argv[i][j]);
            j++;
        }
        printf(" ");
        i++;
    }
    printf("\n");

    return 0;
}