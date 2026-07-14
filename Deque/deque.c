#include<stdio.h>
#include<stdlib.h>

// Defining structure of deque
struct deque{
    int size;
    int f;
    int r;
    int *arr;
};

// Checking if deque is empty
int isempty(struct deque *q){
    if(q->f == -1){
        return 1;
    }
    return 0;
}

// Checking if deque is full
int isfull(struct deque *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

// Displaying elements
void display(struct deque *q){
    if(isempty(q)){
        printf("Deque is empty.\n");
    }
    else{
        printf("Elements are:\n");
        for(int i=q->f;i<=q->r;i++){
            printf("%d\t",q->arr[i]);
        }
        printf("\n");
    }
}

// Insert at Rear
void insertRear(struct deque *q,int val){
    if(isfull(q)){
        printf("Deque is full. Cannot insert %d\n",val);
    }
    else{
        if(isempty(q)){
            q->f = q->r = 0;
        }
        else{
            q->r++;
        }
        q->arr[q->r] = val;
        printf("Inserted at Rear: %d\n",val);
    }
}

// Insert at Front
void insertFront(struct deque *q,int val){
    if(q->f == 0){
        printf("No space at Front.\n");
    }
    else{
        if(isempty(q)){
            q->f = q->r = 0;
        }
        else{
            q->f--;
        }
        q->arr[q->f] = val;
        printf("Inserted at Front: %d\n",val);
    }
}

// Delete from Front
void deleteFront(struct deque *q){
    if(isempty(q)){
        printf("Deque is empty.\n");
    }
    else{
        printf("Deleted from Front: %d\n",q->arr[q->f]);

        if(q->f == q->r){
            q->f = q->r = -1;
        }
        else{
            q->f++;
        }
    }
}

// Delete from Rear
void deleteRear(struct deque *q){
    if(isempty(q)){
        printf("Deque is empty.\n");
    }
    else{
        printf("Deleted from Rear: %d\n",q->arr[q->r]);

        if(q->f == q->r){
            q->f = q->r = -1;
        }
        else{
            q->r--;
        }
    }
}

int main(){

    struct deque *q = (struct deque*)malloc(sizeof(struct deque));

    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    insertRear(q,10);
    insertRear(q,20);
    insertRear(q,30);

    display(q);

    insertFront(q,5);

    display(q);

    deleteFront(q);
    deleteRear(q);

    display(q);

    return 0;
}