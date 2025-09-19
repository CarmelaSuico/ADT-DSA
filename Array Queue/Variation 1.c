#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef struct{
    int item[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main(){
    Queue *Q = initialize();
    printf("Enqueuing: \n");
    enqueue(Q, 10);
    enqueue(Q, 11);
    enqueue(Q, 12);
    enqueue(Q, 13);
    display(Q);
    
    printf("Dequeue:\n");
    dequeue(Q);
    display(Q);
    
    printf("Front of the Queue:\n ");
    int data = front(Q);
    printf("Queue 1: number %d\n", data);
}

Queue* initialize(){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    if(Q == NULL){
        printf("Memory Allocation failed");
        return NULL;
    }
    
    Q->list.count = 0;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

bool isFull(Queue* q){
    if(q->list.count == MAX){
        return true;
    }
    
    return false;
}

bool isEmpty(Queue* q){
    if(q->list.count == 0){
        return true;
    }
    
    return false;
}

void enqueue(Queue* q, int value){
    if(isFull(q)){
        printf("Queue is full");
        return;
    }else if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }else{
        q->rear = (q->rear + 1) % MAX;
    }
    
    q->list.item[q->rear] = value;
    q->list.count++;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return;
    }
    
    printf("Elem: ");
    int i;
    for(i = q->front; i != q->rear; i = (i + 1) % MAX){
        printf("%d ", q->list.item[i]);
    }
    
    printf("%d\n", q->list.item[i]);
    
    printf("\n");
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }
    
    q->list.item[q->front];
    q->front = (q->front + 1) % MAX;
    return q->list.item[q->front];
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }
    
    return q->list.item[q->front];
}


