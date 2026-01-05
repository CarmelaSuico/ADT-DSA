#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

struct Node {
    int key;
    struct Node* next;
};

int hash(int key);
void insertOpen(struct Node* table[], int key);
void displayOpen(struct Node* table[]);

int main() {
    struct Node* table[SIZE] = {NULL};
    insertOpen(table, 10);
    insertOpen(table, 17);
    insertOpen(table, 24);
    insertOpen(table, 5);
    displayOpen(table);
    return 0;
}

int hash(int key) {
    return key % SIZE;
}

void insertOpen(struct Node* table[], int key) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
}

void displayOpen(struct Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]:", i);
        struct Node* temp = table[i];
        while (temp) {
            printf(" %d ->", temp->key);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}
