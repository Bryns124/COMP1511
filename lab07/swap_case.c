// Function to print out a string that has had it's cases swapped.
// swap_case.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
 
#include <stdio.h>

int swap_case(int character);

int main(void) {

    int read_character = getchar();

    while (read_character != EOF) {
        
        int swapped_character = swap_case(read_character);
        putchar(swapped_character);
 
        read_character = getchar();
    }

    return 0;
}

int swap_case(int character) {
    // TODO: Write this function, which should:
    //  - return character in lower case if it is an upper case letter
    //  - return character in upper case if it is an lower case letter
    //  - return the character unchanged otherwise
    int alphabet_position;
    if (character >= 'a' && character <= 'z') {
        alphabet_position = character - 'a';
        return 'A' + alphabet_position;
    }
    if (character >= 'A' && character <= 'Z') {
        alphabet_position = character - 'A';
        return 'a' + alphabet_position;
    }
    return character;
}