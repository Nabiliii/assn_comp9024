// TODO: Add any extra #includes that you need
#include <stdio.h>
#include <stdlib.h> // for malloc and free etc ..
#include "queue.h"
#include <stddef.h> // for defining NULL
#include <string.h>


// TODO: Add your data structure definitions

//for eksempel:
typedef struct Node {
    string data;
    //char data[1000];
    struct Node * next;
} Node;

typedef struct QueueRepr{
    Node* head;
    Node* tail;
} QueueRepr;


//may need this function:
Node* create_node(char* data, Node* next)  {
    Node* new_node = malloc(sizeof(Node)); 
    new_node->data = malloc(strlen(data) + 1);
    strcpy(new_node->data, data);
    new_node->next = next;
    return new_node;
}


// TODO: Fill in these function stubs

//create object:
queue queue_create() {
    QueueRepr* q = malloc(sizeof(QueueRepr));
    q->head = NULL;
    q->tail = NULL;
    return q;
}


void queue_destroy(queue q) {
    Node* current = q->head;
    //loop through the list and free every element
    while (current != NULL) {
        Node* curr = current;
        current = current->next;
        //free(curr->data);
        free(curr);
    }
    free(q);
  
}


void queue_enqueue(queue q, string dat) {
    //first create a new node with dat
    Node* new_node = create_node(dat, NULL);
    // Allocate memory for newNode->data:
    new_node->data = malloc(strlen(dat) + 1);
    strcpy(new_node->data, dat);
    new_node->next = NULL;
    //if empty list:
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    }
    else {
        q->tail->next = new_node;  //add new_node at the last.
        q->tail = new_node;
    }

}


string queue_dequeue(queue q) {
    // first check if q is empty:
    if (q->head == NULL) {
        return NULL;
    }
    // find the data (string) from the q.head so return it later.
    string data = malloc(strlen(q->head->data) + 1);
    strcpy(data, q->head->data);

    // a node equal to the q.head
    Node *a_node = q->head;
    // set the tail to NULL
    q->head = q->head->next;

    // free the node
    free(a_node);
    return data;
}





// Peeks at and returns the front element in the queue, without removing it.
string queue_peek(queue q) {
   // check if empty queue
    if (q == NULL || q->head == NULL) {
        return "";
    }
    else {
        return q->head->data;
    }
}


bool queue_empty(queue q) {
    if (q == NULL || q->head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
