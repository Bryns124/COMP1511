// A Substitution cipher maps each letter to another letter.
// By Bryan Le (z5361001)

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

int position_of_letter(int character);

int main(int argc, char *argv[]) {
    int character = getchar();
    int i; 
    while (character != -1) {
        i = position_of_letter(character);
        if (character >= 'a' && character <= 'z') {
            printf("%c", argv[1][i]);
        }
        if (character >= 'A' && character <= 'Z') {
            printf("%c", toupper(argv[1][i]));
        }
        if (!(character >= 'a' && character <= 'z') && 
        !(character >= 'A' && character <= 'Z')) {
            putchar(character);
        }
        character = getchar();
    }
    return 0;
}

int position_of_letter(int character) {
    int i = 'a';
    while (i <= 'z') {
        if (i == character) {
            i = i - 97;
            return i;
        }
        i++;
    }
    i = 'A';
    while (i <= 'Z') {
        if (i == character) {
            i = i - 65;
            return i;
        }
        i++;
    }
    return i;
}
