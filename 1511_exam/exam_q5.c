// exam_q5.c
//
// This program was written by Bryan Le (z5361001)
// on 01/05/2021
//
// This program prints the least common and first character of a string. 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ARGS 1000

int main(int argc, char *argv[]) {

    char string[MAX_ARGS] = {};
    char least_common[MAX_ARGS] = {};
    int tmp = 0;
    int lowest = 0;
    int i = 1;
    while (i < argc) {
        int j = 1;
        while (j < argc) {
            strcpy(string, argv[i]);
            if (strcmp(argv[j], string) == 0) {
                tmp++;
            }
            j++;
        }
        j = 0;
        if (lowest > tmp || lowest == 0) {
            lowest = tmp;
            strcpy(least_common, string);
        }
        tmp = 0;
        i++;
    }
    printf("%s", least_common);
    return 0;
}
