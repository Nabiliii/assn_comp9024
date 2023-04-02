// TODO: Add any extra #includes that you need

#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h> // for malloc and free etc ..
#include <stddef.h> // for defining NULL
#include <string.h>
//typedef char *string;

// TODO: Add your data structure definitions

// node structure for priority queue
typedef struct Node {
    string value;
    priority p;
    struct Node *next;
} Node;

// priority queue structure
typedef struct PriorityQueueRepr {
    Node *head;
} PriorityQueueRepr;



// TODO: Fill in these function stubs

pqueue pqueue_create() {
    PriorityQueueRepr* pq = malloc(sizeof(PriorityQueueRepr));
    //if malloc fails
    if (pq == NULL) {
        return NULL;
    }
    else {
        pq->head = NULL;
        return pq;
    }
}


 //Destroys a given pqueue, freeing all associated memory.
void pqueue_destroy(pqueue pq) {
    if (pq == NULL) {
        return;
    }
    Node *current = pq->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->value); // free the string value of the node
        free(temp);
    }
    free(pq);
}


/*
void pqueue_join(pqueue pq, string dat, priority prio) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    new_node->value = dat;
    new_node->p = prio;
    if (pq->head == NULL || pq->head->p > prio) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        Node *temp = pq->head;
        while (temp->next != NULL && temp->next->p <= prio) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}*/
void pqueue_join(pqueue queue, string value, priority prio) {
    if (queue == NULL || value == NULL) {
        return;
    }
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return;
    }
    node->value = malloc(strlen(value) + 1);
    if (node->value == NULL) {
        free(node);
        return;
    }
    strcpy(node->value, value);
    node->p = prio;
    Node* prev = NULL;
    Node* curr = queue->head;
    while (curr != NULL && curr->p < prio) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        node->next = queue->head;
        queue->head = node;
    } else {
        node->next = prev->next;
        prev->next = node;
    }
}



 //Removes the highest priority string in the given pqueue.

/*
string pqueue_leave(pqueue pq) {
    if (pq->head == NULL || pq->head->value == NULL) {
        return NULL;
    }

    string value = malloc(strlen(pq->head->value) + 1);
    //string value = pq->head->value;
    strcpy(value, pq->head->value);//temp->value);
    Node *temp = pq->head;
    pq->head = pq->head->next;
    //free(temp->value);
    free(temp);
    return value;
}*/

string pqueue_leave(pqueue queue) {
    if (queue == NULL || queue->head == NULL) {
        return NULL;
    }
    Node* node = queue->head;
    queue->head = node->next;
    string value = node->value;
    free(node);
    return value;
}





string pqueue_peek(pqueue pq) {
    
    if (pq == NULL || pq->head == NULL) {
        return "";
    }
    else {
        return pq->head->value;
    }
}





bool pqueue_empty(pqueue pq) {
    if (pq == NULL || pq->head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
