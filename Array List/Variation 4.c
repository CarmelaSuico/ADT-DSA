#include<stdio.h>
#include<stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPTR;
    int count;
    int max;
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){
    List L;
    initialize(&L);
     int choice, data, position;
    
    do{
        printf("1: Inserting a number\n");
        printf("2: Deleting a number\n");
        printf("3: Locating an existing data\n");
        printf("4: Retrieve an data in a position\n");
        printf("5: Inserting a number by ordert\n");
        printf("6: Display List\n");
        printf("7. Empty the list\n");
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
                insertPos(&L, data, position);
                printf("\n");
            break;
            
            case 2:
                printf("-----------------------------------------Deleting a number-----------------------------------------\n");
                printf("Enter the position where you want to delete: ");
                scanf("%d", &position);
                deletePos(&L, position);
                printf("\n");
            break;
            
            case 3:
                printf("-----------------------------------------Locating an existing data--------------------------------------\n");
                printf("Enter the data you want to find: ");
                scanf("%d", &data);
                locate(&L, data);
                printf("\n");
            break;
            
            case 4:
                printf("---------------------------------Retrieving an existing data at a position------------------------\n");
                printf("Enter your position: ");
                scanf("%d", &position);
                retrieve(&L, position);
                printf("\n");
            break;
            
            case 5:
                printf("-----------------------------------------Inserting a data by order-----------------------------------------\n");
                printf("Enter your data: ");
                scanf("%d", &data);
                insertSorted(&L, data);
                printf("\n");
            break;
            
            case 6:
                printf("-----------------------------------------Displaying List-----------------------------------------\n");
                display(&L);
                printf("\n");
            break;
            
            case 7:
                printf("Deleting List...\n");
                makeNULL(&L);
                printf("\n");
            break;
            
            case 0:
                printf("Exit...");
                printf("\n");
            break;
            
            default:
            printf("Invalid choice");
            break;
        }
    }while(choice != 0);
    return 0;
}

void initialize(List *L){
    L->elemPTR = (int *)malloc(sizeof(int) * LENGTH);
    
    if(L->elemPTR == NULL){
        printf("Memory Allocation failed");
    }
    
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int data, int position){
    if(L->count < position){//cehcking if the position is less than count
        printf("Invalid position");
        return;
    }
    if(L->count == L->max){
        resize(L);
    }
    
    for(int i = L->count - 1; i >= position; i--){
        L->elemPTR[i + 1] = L->elemPTR[i];
    }
    
    L->elemPTR[position] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if(L->count < position){
        printf("Invalid position\n");
        return;
    }
    
    for(int i = position; i < L->count; i++){
        L->elemPTR[i] = L->elemPTR[i + 1];
    }
    
    L->count--;
}

int locate(List *L, int data){
    int found = 0;
    for(int i = 0; i < L->count; i++){
        if(L->elemPTR[i] == data){
            printf("Data %d found at position %d\n", L->elemPTR[i], i);
            found++;
            break;
        }
    }
    
    if(found == 0){
        printf("Data %d does not exist\n", data);
        return -1;
    }
}

int retrieve(List *L, int position){
    if(L->count < position){
        printf("Invalid position\n");
        return -1;
    }
    
    for(int i = 0; i < L->count; i++){
        if(i == position){
            printf("Position %d contains data %d\n", position, L->elemPTR[i]);   
            break;
        }
    }
}

void insertSorted(List *L, int data){
    if(L->count == L->max){
        resize(L);
    }
    int i = L->count - 1;
    for(; i >= 0 && L->elemPTR[i] > data; i--){
        L->elemPTR[i + 1] = L->elemPTR[i];
    }
    L->elemPTR[i + 1] = data;
    L->count++;
}

void display(List *L){
    printf("Elem: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elemPTR[i]);
    }
    
    printf("\nPosition: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", i);
    }
    
    printf("\n");
}

void resize(List *L){
    int newCap = L->max * 2;
    
    int *newelemPTR = (int *)realloc(L->elemPTR,sizeof(int) * newCap);
    
    if(newelemPTR == NULL){
        printf("\nMemory reallocation failed\n");
        return;
    }
    
    L->elemPTR = newelemPTR;
    L->max = newCap;
}

void makeNULL(List *L){
    free(L->elemPTR);
    L->elemPTR = NULL;
    L->count = 0;
    L->max = 0;
    printf("\nList has been reseted\n");
}

