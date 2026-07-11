#include<stdio.h>
#include<stdlib.h>

//defining structure for circular queue
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
    if(((q->r+1)%q->size)==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

//inserting elements in the queue
void enqueue(struct queue* q,int val){
    if(isfull(q)){
        printf("The queue is full unable to insert %d \n",val);
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Successfully inserted %d \n",val);
    }
}

//deleting elements from the queue
void dequeue(struct queue* q){
    if(isempty(q)){
        printf("Nothing is there,the queue is empty \n");
    }
    else{
        int a;
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
        printf("Successfully deleted %d \n",a);
    }
}


//display elements in the queue
void display(struct queue* q){
    if(isempty(q)){
        printf("The queue is empty nothing to display \n");
    }
    else{
        printf("Elements are: ");
        int i=(q->f+1)%q->size;
        for(i;i!=(q->r+1)%q->size;i=(i+1)%q->size){
            printf("%d \t",q->arr[i]);
        }
    }
    printf("\n");
}

//main function
int main(){
    struct queue* q= (struct queue*)malloc(sizeof(struct queue));
    q->size=4;
    q->f=q->r=0;
    q->arr=(int*)malloc(q->size*sizeof(int));

    //inserting elements in the queue till full
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);

    //deleting element till it getting full
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    //inserting element in the queue to check space
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);

    //displaying elements
    display(q);

    //deleting and inserting elements again to test display
    dequeue(q);
    enqueue(q,40);
    
    display(q);
    return 0;
}