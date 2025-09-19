#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){
    List *L = initialize();
    int index;
    printf("Inserting First: \n");
    insertFirst(L, 13);
    insertFirst(L, 12);
    insertFirst(L, 11);
    display(L);
    
    printf("\nInserting Last:\n");
    insertLast(L, 14);
    insertLast(L, 16);
    display(L);
    
    printf("\nInserting elem at a position\n");
    insertPos(L, 15, 4);
    display(L);
    
    printf("\nDeleting elem at the first position\n");
    deleteStart(L);
    display(L);
    
    printf("\nDeleting elem at the last position\n");
    deleteLast(L);
    display(L);
    
    printf("\nDeleting elem at the certain position\n");
    deletePos(L, 3);
    display(L);
    
    printf("\nRetrieving elem at the certain position\n");
    int data = retrieve(L, 2);
    printf("Position %d contain data %d\n", 2, data);
    
    printf("\nLocating elem \n");
    int locating = locate(L, 13);
    printf("Data %d located at position %d", 13, locating);
}

List *initialize(){
    List *list = (List *)malloc(sizeof(List));
    if(list == NULL){
        printf("Memory Allocation failed");
        return NULL;
    }
    
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    Node *nextNode;
    for(Node *current = list->head; current != NULL; current = nextNode){
        nextNode = current->next;//store the next node's address
        free(current);//free the current node
    }
    
    list->head = NULL;//setting head to NULL
    list->count = 0;//setting count to 0
}

void insertFirst(List *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation failed");
        return;
    }
    
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation failed");
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){//checking if the list is empty
        list->head = newNode;   
    }
    Node *current = list->head;
    for(; current->next != NULL; current = current->next){}
    current->next = newNode;
    list->count++;
}

void insertPos(List *list, int data, int index){
    if(list->count < index){
        printf("Invalid position");
        return;
    }
    
    if(index == 0){
        insertFirst(list, data);
    }else if(index == list->count){
        insertLast(list, data);
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        Node *current = list->head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;//moving the current pointer to the next node
        }
        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

void deleteStart(List *list){
    Node *current = list->head;//setting the current to the first node
    list->head = current->next;//and head will get the next node
    free(current);//freeing the first node
    list->count--;//decrement the count
}

void deleteLast(List *list){
    if(list->count == 1){//if the list has 1 node only
        free(list->head);//free the head
        list->head = NULL;//setting the head to NULL        
    }
    
    Node *current = list->head;
    for(int i = 0; i < list->count - 2; i++){//looping to the second to the last of the node
        current = current->next; //setting the current to the second to the last of node        
    }
    free(current->next);
    current->next = NULL;
    list->count--;
}

void deletePos(List *list, int index){
    if(index == 0){
        deleteStart(list);
    }
    
    Node *current = list->head;
    for(int i = 0;  i < index - 1; i++){//going to the position before the position to be deleted
        current = current->next;
    }
    Node *temp = current->next;//current->next is the position where to delete and giving it to temp
    current->next = temp->next;//connecting back the list
    free(temp);//freeing temp
    list->count--;
}

int retrieve(List *list, int index){
    if(list->count < index){
        printf("Invalid Position\n");
        return -1;
    }
    Node *current = list->head;
    //int i;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    
    return current->data;
}

int locate(List *list, int data){
    if(list->head == NULL){
        return -1;
    }
    
    Node *current = list->head;
    int i = 0;
    while(current != NULL){
        if(current->data == data){
            return i;
        }
        current = current->next;
        i++;
    }
    
    if(i == 0){
        printf("Data %d does not exist\n", data);
        return -1;
    }
}

void display(List *list){
    printf("Elem: ");
    for(Node *current = list->head; current != NULL; current = current->next){
        printf("%d ", current->data);
    }
    printf("\n");
    printf("Position: ");
    for(int i = 0; i < list->count; i++){
        printf("%d ", i);
    }
    printf("\n");
}



