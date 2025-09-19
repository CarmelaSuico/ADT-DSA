#include<stdio.h>
#include<stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPTR;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){
    List L;
    L = initialize(L);
    int choice, data, position;
    
    do{
        printf("1: Inserting a number\n");
        printf("2: Deleting a number\n");
        printf("3: Locating an existing data\n");
        printf("4: Inserting a number by ordert\n");
        printf("5: Display List\n");
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
                L = insertPos(L, data, position);
                printf("\n");
            break;
            
            case 2:
                printf("-----------------------------------------Deleting a number-----------------------------------------\n");
                printf("Enter the position where you want to delete: ");
                scanf("%d", &position);
                L = deletePos(L, position);
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
                printf("-----------------------------------------Inserting a data by order-----------------------------------------\n");
                printf("Enter your data: ");
                scanf("%d", &data);
                L = insertSorted(L, data);
                printf("\n");
            break;
            
            case 5:
                printf("-----------------------------------------Displaying List-----------------------------------------\n");
                display(L);
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

List initialize(List L){
    L.elemPTR = (int *)malloc(sizeof(int) * LENGTH);
    if(L.elemPTR == NULL){
        printf("Memory Allocation failed");
    }
    
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count < position){ //checking if the position is valid
        printf("Invalid position\n");
    }
    if(L.count == L.max){// checking if the list is full
        L = initialize(L);
    }
    for(int i = L.count - 1; i >= position; i-- ){
        L.elemPTR[i + 1] = L.elemPTR[i];
    }
    
    L.elemPTR[position] = data;
    L.count++;
    
    return L;
}

List deletePos(List L, int position){
    if(L.count < position){ //checking if the position is valid
        printf("Invalid position\n");
    }
    
    for(int i = position; i < L.count; i++ ){
        L.elemPTR[i] = L.elemPTR[i + 1];
    }
    
    L.count--;
    return L;
}

int locate(List L, int data){
    int found = 0;// if found is 0 = not found and 1 = found 
    for(int i = 0; i < L.count; i++){
        if(L.elemPTR[i] == data){
            printf("Data %d found at position %d\n", L.elemPTR[i], i);
            found++;
            break;
        }
    }
    
    if(found == 0){
        printf("Data %d does not exist\n", data);
        return -1;
    }
}

List insertSorted(List L, int data){
    if(L.count == L.max){
        L = resize(L) ;
    }
    int i = L.count - 1;
    for(; i >= 0 && L.elemPTR[i] > data; i--){
            L.elemPTR[i + 1] = L.elemPTR[i];// existing data goes to the right
    }
    L.elemPTR[i + 1] = data; //the next position will have the new data
    L.count++;
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPTR[i]);
    }
    
    printf("\n");
}

List resize(List L) {
    int newCap = L.max * 2;
    int* newelemPTR = (int*)realloc(L.elemPTR, sizeof(int) * newCap);

    if (newelemPTR == NULL) {
        printf("Error: Memory reallocation failed.\n");
        return L;
    }

    L.elemPTR = newelemPTR;
    L.max = newCap;
    
    return L;
}
