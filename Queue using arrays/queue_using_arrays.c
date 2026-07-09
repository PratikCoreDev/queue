#include<stdio.h>
#include<stdlib.h>

//defining structure of queue
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

//checking the queue is empty or not
int isempty(struct queue* q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}

//checking the queue is full or not
int isfull(struct queue* q){
    if(q->r==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

//displaying elements of the queue
void display(struct queue* q){
    if(isempty(q)){
        printf("Nothing to display its empty \n");
    }
    else{
        printf("Elements are: \n");
        for(int i=q->f+1;i<=q->r;i++){
            printf("%d \t",q->arr[i]);
        }
        printf("\n");
    }
}

//inserting element in the queue
void enqueue(struct queue* q,int val){
    if(isfull(q)){
        printf("The queue is full unable to insert %d \n",val);
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("Element inserted successfully: %d \n",val);
    }
}

//deleting the element from the queue
void dequeue(struct queue* q){
    int a;
    if(isempty(q)){
        printf("The queue is empty \n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
        printf("Succesfully deleted: %d \n",a);
    }
}

int main(){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->size=5;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    //inserting element till queue is full;
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);

    //displaying the queue
    display(q);

    //deleting element till queue is empty
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    return 0;
}