// exam_q2.c
//
// This program was written by Bryan Le (z5361001)
// on 01/05/2021
//
// This program compares the total sums of a first node and a second node and will return 1 if the
// first sum is more than the second, return -1 if the first sum is less than the second and 0 if
// the first sum is the same as the second.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *strings_to_list(int len, char *strings[]);

// exam_q2() takes in the head of two lists and prints
// something based on which has the larger sum
int exam_q2(struct node *first, struct node *second){

    int first_sum = 0;
    int second_sum = 0;

    while (first != NULL) {
        first_sum = first_sum + first->data;
        first = first->next;
    }
    while (second != NULL) {
        second_sum = second_sum + second->data;
        second = second->next;
    }
    if (first_sum > second_sum) {
        return 1;
    } 
    else if (first_sum < second_sum) {
        return -1;
    }
    else if (first_sum == second_sum) {
        return 0;
    }
}



// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *first = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *second = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = exam_q2(first, second);
    printf("%d\n", result);

    return 0;
}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
