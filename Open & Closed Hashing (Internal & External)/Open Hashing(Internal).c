#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct Node {
    int data;
    struct Node* next;
}Node;

int hashFunction(int key);
void insertOpen(struct Node* table[], int key);
void displayOpen(struct Node* table[]);

int main() {
    struct Node* table[SIZE] = {NULL};
    insertOpen(table, 10);
    insertOpen(table, 17);
    insertOpen(table, 15);
    displayOpen(table);
    return 0;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertOpen(struct Node* table[], int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = table[index];
    table[index] = newNode;
}

void displayOpen(struct Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = table[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

