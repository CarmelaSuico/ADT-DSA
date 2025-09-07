#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
  List L;
  L = initialize(L);
    
    int choice, data, position;
    
    do{
        printf("1: Inserting a number\n");
        printf("2: Deleting a number\n");
        printf("3: Locating an existing data\n");
        printf("4: Inserting a number by order\n");
        printf("5: Display List\n");
        printf("0: Exit\n\n");
        printf("Enter a number: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("-----------------------------------------Inserting a number-----------------------------------------\n");
                if(L.count == 0){
                    printf("List is Empty, please place it at the first position: 0\n");
                }
                printf("Enter your data: ");
                scanf("%d", &data);
                printf("Enter the position where you want to insert: ");
                scanf("%d", &position);
                L = insertPos(L, data, position);
                printf("\n");
            break;
            case 2:
                printf("-----------------------------------------Deleting a number-----------------------------------------\n");
                printf("Enter the position where you want to delete: ");
                scanf("%d", &position);
                L=deletePos(L, position);
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
                printf("-----------------------------------------Inserting a number by order-------------------------------------\n");
                printf("Enter your data: ");
                scanf("%d", &data);
                L=insertSorted(L, data);
                printf("\n");
            break;
            case 5:
                printf("-----------------------------------------Displaying List-----------------------------------------\n");
                display(L);
                printf("\n");
            break;
            case 0:
                printf("Exiting...");
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

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position > L.count){ //checking if the position is valid
        printf("Not valid position");
        return L;
    }
    
    if(L.count == MAX){ // checking if the list is full or not
        printf("List is full");
        return L;
    }
    
    //inserting in a position
    for(int i = L.count - 1; i >= position; i--){
        L.elem[i+1] = L.elem[i];
    }
    
    L.elem[position] = data;
    L.count++;
    printf("Current Count: %d\n", L.count);
    return L;
}

List deletePos(List L, int position){
    if(position > L.count){ //checking if the position is valid
        printf("Not valid position");
        return L;
    }
    if(L.count == MAX){ // checking if the list is full or not
        printf("List is full");
        return L;
    }
    
    for(int i = position; i < L.count; i++){
        L.elem[i] = L.elem[i+1];
    }
    L.count--;
    
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            printf("Data found: %d\n", L.elem[i]);
            printf("Located at %d\n", i);
            return i;
        }
    }
    printf("Data not found: %d\n", data);
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == MAX){ // checking if the list is full or not
        printf("List is full");
        return L;
    }
    
    int i;
    for(i = 0; i < L.count; i++){//finding the position
        if(L.elem[i] >= data){
            break;
        }
    }
    
    for(int j = L.count; j > i; j--){
        L.elem[j] = L.elem[j-1];
    }
    
    L.elem[i] = data;
    L.count++;
    
    return L;
}


void display(List L){
    printf("Elem: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
    printf("Count: %d ", L.count);
    printf("\n");
}
