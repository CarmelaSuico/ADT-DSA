#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef struct{
    int item[MAX];
    int top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack *s) ;
void display(Stack* s);

int main(){
    Stack *S = initialize();
    printf("Pushing a data\n");
    push(S, 10);
    push(S, 11);
    push(S, 13);
    push(S, 14);
    display(S);
    
    printf("Poping a data: \n");
    int value = pop(S);
    display(S);
    
    printf("Peek a data: \n");
    int peekvalue = peek(S);
    printf("The top data is %d\n\n", peekvalue);
    
    printf("Top data: \n");
    int topValue = top(S);
    printf("The top data is %d\n\n", topValue);
}

Stack* initialize(){
    Stack *S = (Stack *)malloc(sizeof(Stack));
    if(S == NULL){
        printf("Memory Allocation failed\n");
        return NULL;
    }
    
    S->top = -1; //indecating the stack is empty
    return S;
}

bool isFull(Stack *s){
    if(s->top == MAX - 1){//checking if the stack is full when it reaches 9 cuz 10 - 1
        return true;                
    }
    return false;
}

bool isEmpty(Stack *s){
    if(s->top == -1){//checking if the stack is empty since its -1, not 0 cuz 0 is the first stack meaning the stack is not empty
        return true;
    }
    return false;
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Stack is full\n");
        return;
    }
    
    s->top++;//incrementing to the next position
    s->item[s->top] = value;//adding the value
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    
    s->item[s->top];
    s->top--;
    return s->item[s->top];
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    
    return s->item[s->top];
}

int top(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    
    return s->item[s->top];
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    
    printf("Elem: ");
    for(int i = 0; i <= s->top; i++){
        printf("%d ", s->item[i]);
    }
    printf("\n");
    
    printf("Position: ");
    for(int i = 0; i <= s->top; i++){
        printf("%d ", i);
    }
    printf("\n\n");
}

