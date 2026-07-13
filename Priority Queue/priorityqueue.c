#include<stdio.h>
#include<stdlib.h>

// Defining structure of priority queue
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

// Checking if queue is empty
int isempty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    else{
        return 0;
    }
}

// Checking if queue is full
int isfull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Displaying elements
void display(struct queue *q){
    if(isempty(q)){
        printf("Queue is empty.\n");
    }
    else{
        printf("Elements are:\n");
        for(int i=q->f+1;i<=q->r;i++){
            printf("%d\t",q->arr[i]);
        }
        printf("\n");
    }
}

// Inserting according to priority
void enqueue(struct queue *q,int val){

    if(isfull(q)){
        printf("Queue is full. Unable to insert %d\n",val);
        return;
    }

    int i;

    // Shift larger elements to the right
    for(i=q->r;i>q->f && q->arr[i]>val;i--){
        q->arr[i+1]=q->arr[i];
    }

    q->arr[i+1]=val;
    q->r++;

    printf("Inserted: %d\n",val);
}

// Delete highest priority element
void dequeue(struct queue *q){

    if(isempty(q)){
        printf("Queue is empty.\n");
    }
    else{
        q->f++;
        printf("Deleted: %d\n",q->arr[q->f]);
    }
}

int main(){

    struct queue *q=(struct queue*)malloc(sizeof(struct queue));

    q->size=10;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    // Inserting elements
    enqueue(q,30);
    enqueue(q,10);
    enqueue(q,50);
    enqueue(q,20);
    enqueue(q,40);

    // Display queue
    display(q);

    // Deleting elements
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // Display again
    display(q);

    return 0;
}