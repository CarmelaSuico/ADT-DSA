#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);


int main(){
  EPtr L;
  initialize(L);
    
    int choice, data, position;
    
    do{
        printf("1: Inserting a number\n");
        printf("2: Deleting a number\n");
        printf("3: Locating an existing data\n");
        printf("4: Retrieving an existing data at a position\n");
        printf("5: Inserting a number by ordert\n");
        printf("6: Display List\n");
        printf("7: Deleting List\n");
        printf("0: Exit\n\n");
        printf("Enter a number: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("-----------------------------------------Inserting a number-----------------------------------------\n");
                printf("Enter your data: ");
                scanf("%d", &data);
                printf("Enter the position where you want to insert: ");
                scanf("%d", &position);
                insertPos(L, data, position);
                printf("\n");
            break;
            case 2:
                printf("-----------------------------------------Deleting a number-----------------------------------------\n");
                printf("Enter the position where you want to delete: ");
                scanf("%d", &position);
                deletePos(L, position);
                printf("\n");
            break;
            case 3:
                printf("-----------------------------------------Locating an existing data--------------------------------------\n");
                printf("Enter the data you want to find: ");
                scanf("%d", &data);
                locate(L, data);
                printf("\n");
            break;
            case 4:
                printf("-----------------------------------Retrieving an existing data at a position-----------------------------\n");
                printf("Enter the position you want to find: ");
                scanf("%d", &position);
                retrieve(L, position);
                printf("\n");
            break;
            case 5:
                printf("-----------------------------------------Inserting a data by order-----------------------------------------\n");
                printf("Enter your data: ");
                scanf("%d", &data);
                insertSorted(L, data);
                printf("\n");
            break;
            case 6:
                printf("-----------------------------------------Displaying List-----------------------------------------\n");
                display(L);
                printf("\n");
            break;
            case 7:
                printf("Deleting List...\n");
                makeNULL(L);
                printf("\n");
            break;
            case 0:
                printf("Exit...");
                printf("\n");
            break;
            default:
                printf("Invalid number");
                printf("\n");
            break;
        }
    }while(choice != 0);
    
  return 0;
}

 
void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(position > L->count){
        printf("Not valid position");
    }
    
    if(L->count == MAX){
        printf("The list is full");
    }
    
    for(int i = L->count - 1; i >= position; i--){
        L->elem[i+1] = L->elem[i];
    }
    
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    if(position > L->count){
        printf("Not valid position");
    }
    
    for(int i = position; i < L->count; i++){
        L->elem[i] = L->elem[i+1];
    }
    
    L->count--;
}

int locate(EPtr L, int data){// looking through data
    for(int i = 0; i <= L->count; i++){
        if(L->elem[i] == data){
            printf("Data found: %d, Position at %d\n", L->elem[i], i);
            return i;
        }
    }
    
    printf("Data %d not found\n", data);
    return -1;
}

int retrieve(EPtr L, int position){// looking through position
    if(position > L->count){
        printf("Not valid position");
    }
    
    for(int i = L->count - 1; i >= position; i--){
        printf("Position %d: %d", i, L->elem[i]);
        return i;
    }
}

void insertSorted(EPtr L, int data){
    if(L->count == MAX){
        printf("The list is full");
    }
    
    int i;
    for(i = 0; i < L->count; i++){//finding the position
        if(L->elem[i] >= data){
            break;
        }
    }
    
    for(int j = L->count; j > i; j--){//moving all the elems
        L->elem[j] = L->elem[j-1];
    }
    
    L->elem[i] = data;
    L->count++;
}

void display(EPtr L){
    printf("Elem: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
    printf("Count: %d ", L->count);
    printf("\n");
}

void makeNULL(EPtr L){
    L->count = 0;
}
