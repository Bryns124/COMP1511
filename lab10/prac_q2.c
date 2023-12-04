#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int count_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = count_last(head);
    printf("%d\n", result);

    return 0;
}


// return the number of values in a linked list equal to the
// last value in that linked list.
int count_last(struct node *head) {
    struct node *curr_node = head;
    struct node *prev_node = head;
    int result = 1;
    if (head == NULL) {
        return 0;
    }
    if (head->next == NULL) {
        return 1;
    }
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }
    if (curr_node->next == NULL) {
        while (prev_node->next != NULL) {
            if (prev_node->data == curr_node->data) {
                result++;
            }
            prev_node = prev_node->next;
        }
    }
    return result;
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
