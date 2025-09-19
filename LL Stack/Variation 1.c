#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main(){
    Stack *S = initialize();
    printf("Pushing a data:\n");
    push(S, 10);
    push(S, 11);
    push(S, 12);
    push(S, 13);
    display(S);
    
    printf("Poping a data:\n");
    pop(S);
    display(S);
    
    printf("Top of the stack:\n");
    int top = peek(S);
    printf("Current Top: %d\n", top);
    
}

Stack *initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s){
    return false;//linked list can never be full
}
bool isEmpty(Stack* s){
    if(s->top == NULL){
        return true;
    }
    
    return false;
}

void push(Stack* s, int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;//add the value
    newNode->next = s->top;//setting to the next NULL
    s->top = newNode;//linking the first node to the head
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return;
    }
    printf("Elem: ");
    Node *trav = s->top;
    for(;trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
    printf("\n");
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }
    
    Node *temp = s->top;
    temp->data = s->top->data;
    s->top = s->top->next;
    free(temp);
    return s->top->data;
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }
    
    return s->top->data;
}
