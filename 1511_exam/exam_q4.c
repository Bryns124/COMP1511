// exam_q4.c
//
// This program was written by Bryan Le (z5361001)
// on 01/05/2021
//
// This program will compare two nodes and delete a node in the second list so that both lists
// are the same.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct node
{
    struct node *next;
    int data;
};

struct container
{
    struct node *list1;
    struct node *list2;
};

void remove_outlier(struct container *container);
struct node *create_node(int data, struct node *next);
void strings_to_list(struct container *container, char *strings[], int argc);
void print_list(struct node *head);
void free_list(struct node *head);

// Remove the the outlier that exists in the two linked lists
//  - the linked lists should contain identical values after this function has completed
//  - this function should modify the two lists in the container passed into the function
//  - you are guaranteed the extra element is always in the second list (ie container->list2)
//  - this function does not return anything.
void remove_outlier(struct container *container)
{
    struct node *curr_node1 = container->list1;
    struct node *curr_node2 = container->list2;
    struct node *prev_node2 = NULL;
    while (curr_node1->data == curr_node2->data && curr_node1->next != NULL && curr_node2->next != NULL) {
        prev_node2 = curr_node2;
        curr_node1 = curr_node1->next;
        curr_node2 = curr_node2->next;
    }
    if (curr_node1->next == NULL) {
        curr_node2->next = NULL;
    }
    else if (curr_node1->next != NULL) {
        if (curr_node1->data != curr_node2->data) {
            prev_node2->next = curr_node2->next;
            free(curr_node2);
        }
    }
}

// DO NOT CHANGE THIS FUNCTION
int main(int argc, char *argv[])
{

    struct container *container = malloc(sizeof(struct container));
    container->list1 = NULL;
    container->list2 = NULL;

    // smallest possible usage is ./exam_q4 1 | 1 2
    // which is an argc of 4
    if (argc < 4)
    {
        printf("Invalid usage.\n");
        exit(1);
    }
    else
    {

        strings_to_list(container, &argv[1], argc);

      
    }

    remove_outlier(container);

    print_list(container->list1);
    print_list(container->list2);

    free_list(container->list1);
    free_list(container->list2);

    free(container);
    return 0;
}

// create linked list from array of strings
void strings_to_list(struct container *container, char *strings[], int argc)
{
    int i = 0;
    struct node *head = NULL;
    while (strcmp(strings[i+1], "-") != 0)
    {
        i++;
    }
    int sep = i + 1;
    while (i >= 0)
    {
        struct node *n = malloc(sizeof(struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }
    container->list1 = head;
    
    i = argc - 2;
    head = NULL;
    while (i > sep)
    {  
        struct node *n = malloc(sizeof(struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }
    container->list2 = head;
}

// print a linked list
void print_list(struct node *head)
{
    printf("[");
    struct node *n = head;
    while (n != NULL)
    {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL)
        {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}

// free a linked list
void free_list(struct node *head)
{

    struct node *curr = head;
    while (curr != NULL)
    {
        struct node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}
