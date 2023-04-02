// TODO: Add any extra #includes that you need

#include "stack.h"
#include <stdio.h>
#include <stdlib.h> // for malloc and free etc ..
#include <stddef.h> // for defining NULL
#include <string.h>

// TODO: Add your data structure definitions

typedef struct Node {
    string data;
    struct Node * next;
} Node;

typedef struct StackRepr{
    Node* head;
    //Node* tail;
} StackRepr;



// TODO: Fill in these function stubs

//create object:
stack stack_create() {
    StackRepr * min_stack = malloc(sizeof(StackRepr));
    if (min_stack == NULL) {
        return NULL;
    }
    min_stack->head = NULL;
    return min_stack;
}


void stack_destroy(stack s) {
    //check weather the stack is empty:
    while (!stack_empty(s)) {
        // call the stack_pop function:
        stack_pop(s);
    }
    free(s);
}




void stack_push(stack s, string dat) {
    if (s == NULL) {
        return;
    }
    //allocate memory for newNode to be pushed:
    Node *newNode = malloc(sizeof(Node));
    // Allocate memory for newNode->data:
    newNode->data = malloc(strlen(dat) + 1);
    //copy the input string to the newNode->data
    strcpy(newNode->data, dat);
    // Push the new node to the top (head) of s:
    newNode->next = s->head;
    s->head = newNode;
}


string stack_pop(stack s) {
    if (stack_empty(s)) {
        return NULL;
    }
    Node *nodeToPop = s->head;
    string poppedValue = malloc(strlen(nodeToPop->data) + 1);
    if (poppedValue == NULL) {
        return NULL;
    }
    strcpy(poppedValue, nodeToPop->data);
    s->head = nodeToPop->next;
    free(nodeToPop);
    return poppedValue;
}


string stack_peek(stack s) {
    //first check weather stack is empty
    if (stack_empty(s)) {
        return NULL;
    }
    return s->head->data;
}


bool stack_empty(stack s) {
    return (s == NULL || s->head == NULL);

}
