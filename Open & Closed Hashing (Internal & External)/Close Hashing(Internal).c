#include <stdio.h>

#define SIZE 7

int hashFunction(int key);
void insertClosed(int table[], int key);
void displayClosed(int table[]);

int main() {
    int table[SIZE];
    for (int i = 0; i < SIZE; i++) table[i] = -1;

    insertClosed(table, 10);
    insertClosed(table, 17);
    insertClosed(table, 24);
    displayClosed(table);
    return 0;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertClosed(int table[], int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) return;
    }
    table[index] = key;
}

void displayClosed(int table[]) {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1) printf("[%d]: EMPTY\n", i);
        else printf("[%d]: %d\n", i, table[i]);
    }
}
