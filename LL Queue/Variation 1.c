#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct List{
    Node *front;
    Node *rear;
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
    
    printf("Dequeuing:\n");
    dequeue(Q);
    display(Q);
    
    printf("Current first queue:\n");
    int data = front(Q);
    printf("Queue 1: number %d\n", data);
}

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory Allocation failed");
    }
    
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q){
    return false;//linked list is never full
}
bool isEmpty(Queue* q){
    if(q->front == NULL){
        return true;
    }
    
    return false;
}

void enqueue(Queue* q, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation falied");
        return;
    }
    
    newNode->data = value;
    newNode->next = NULL;
    if(isEmpty(q)){//if the Queue is Empty
        q->front = newNode;
        q->rear = newNode;
    }else{//if its not
        q->rear->next = newNode;
        q->rear = newNode;
    }
    
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }
    
    Node *temp = q->front;
    temp->data = q->front->data;
    q->front = q->front->next;
    if(isEmpty(q)){
        q->rear = NULL;
    }
    
    free(temp);
    return q->front->data;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }
    
    return q->front->data;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return;
    }
    
    printf("Elem: ");
    Node *trav;
    for(trav = q->front; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
    printf("\n");
}

