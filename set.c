// TODO: Add any extra #includes that you need

#include "set.h"
#include <stdio.h>
#include <stdlib.h> // for malloc and free etc ..
#include <stddef.h> // for defining NULL
#include <string.h>

// TODO: Add your data structure definitions

typedef struct Node {
    string data;
    struct Node * next;
} Node;


typedef struct SetRepr{
    Node* head;
} SetRepr;



// TODO: Fill in these function stubs

set set_create() {
    // allocate memory for the head-node:
    SetRepr* new_set = malloc(sizeof(SetRepr));
    //set the head to be empty
    new_set->head = NULL;
    return new_set;
}


void set_destroy(set s) {
    //need a temp node (current) = head
    Node* current = s->head;
    //iterate and free all the nodes:
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    //free the whole set:
    free(s);
}


void set_insert(set s, string dat) {
    //  if an element does not exist in the given set.
    if (!set_contains(s, dat)) {
        Node* new_node = malloc(sizeof(Node));
        new_node->data = malloc(strlen(dat) + 1);
        strcpy(new_node->data, dat);
        new_node->next = s->head;
        s->head = new_node;
    }
}


void set_remove(set s, string dat) {
    Node* current = s->head;
    Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->data, dat) == 0) { //if we are on the right value
            if (prev == NULL) {
                s->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
 
            break;
        }
        prev = current;
        current = current->next;
    }
}


bool set_contains(set s, string dat) {
    Node* current = s->head;
    while (current != NULL) {
        if (strcmp(current->data, dat) == 0) { //if we have reached the dat
            return true;
        }
        current = current->next;
    }
    return false;
}

