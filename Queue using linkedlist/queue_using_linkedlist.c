#include <stdio.h>
#include <stdlib.h>

// Defining structure of node
struct node{
    int data;
    struct node* next;
};

// Defining structure of queue
struct queue{
    struct node* f;
    struct node* r;
};

// Checking if queue is empty
int isempty(struct queue* q){
    if(q->f == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Displaying elements of queue
void display(struct queue* q){
    if(isempty(q)){
        printf("Nothing to display, queue is empty.\n");
    }
    else{
        struct node* ptr = q->f;
        printf("Elements are:\n");
        while(ptr != NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

// Inserting element into queue
void enqueue(struct queue* q, int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));

    if(n == NULL){
        printf("Queue is full (Memory not available).\n");
    }
    else{
        n->data = val;
        n->next = NULL;

        if(q->f == NULL){
            q->f = q->r = n;
        }
        else{
            q->r->next = n;
            q->r = n;
        }

        printf("Element inserted successfully: %d\n", val);
    }
}

// Deleting element from queue
void dequeue(struct queue* q){
    if(isempty(q)){
        printf("Queue is empty.\n");
    }
    else{
        struct node* ptr = q->f;
        int val = ptr->data;

        q->f = q->f->next;

        if(q->f == NULL){
            q->r = NULL;
        }

        free(ptr);

        printf("Successfully deleted: %d\n", val);
    }
}

int main(){

    struct queue* q = (struct queue*)malloc(sizeof(struct queue));

    q->f = NULL;
    q->r = NULL;

    // Inserting elements
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);

    // Display queue
    display(q);

    // Deleting elements
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    return 0;
}