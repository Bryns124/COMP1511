#include <stdio.h>

int is_vowel(int character);

int main(void) {

    int read_character = getchar();
    while (read_character != EOF) {
        if (is_vowel(read_character) == 0) {
            putchar(read_character);
        } 
        read_character = getchar();
    }

    return 0;
}

int is_vowel(int character) {

    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
        return 1;
    } else {
        return 0;
    }
}