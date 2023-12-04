#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int encrypt(int character1, int shift);

int main(int argc, char *argv[]) {

    int character1 = getchar();
    int shift = atoi(argv[1]);
    while (character1 != EOF) {
        character1 = encrypt(character1, shift);
        putchar(character1);
        character1 = getchar();
    }
    return 0;
}

int encrypt(int character1, int shift) {

    int character2 = character1;
    if (character1 >= 'A' && character1 <= 'Z') {
        if ((character1 + (shift % 26)) < 'A') {
            character1 = character1 + (shift % 26) + 26;
            return character1;
        }
        if ((character1 + (shift % 26)) > 'Z') {
            character1 = character1 + (shift % 26) - 26;
            return character1;
        }
        else {
            character1 = character1 + (shift % 26);
            return character1;
        }
    }
    if (character2 >= 'a' && character2 <= 'z') {
        if ((character2 + (shift % 26)) < 'a') {
            character2 = character2 + (shift % 26) + 26;
            return character2;
        }
        if ((character2 + (shift % 26)) < 'z') {
            character2 = character2 + (shift % 26) - 26;
            return character2;
        }
        else {
            character2 = character2 + (shift % 26);
            return character2;
        }
    }
    else {
        return character1;
    }
}