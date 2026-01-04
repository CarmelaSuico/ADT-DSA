#include<stdio.h>
#include<stdlib.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertPos(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main() {
    VHeap myHeap;
    List myList = -1;

    initialize(&myHeap);

    insertFirst(&myList, &myHeap, 10);
    insertLast(&myList, &myHeap, 30);
    insertSorted(&myList, &myHeap, 20);
    insertPos(&myList, &myHeap, 25);

    printf("List after insertions: ");
    display(myList, myHeap);

    delete(&myList, &myHeap, 20);
    printf("List after deleting 20: ");
    display(myList, myHeap);

    insertLast(&myList, &myHeap, 25);
    insertFirst(&myList, &myHeap, 25);
    printf("List before deleting all 25s: ");
    display(myList, myHeap);

    deleteAllOccurrence(&myList, &myHeap, 25);
    printf("List after deleting all 25s: ");
    display(myList, myHeap);

    return 0;
}

void initialize(VHeap *V) {
    int i;
    V->avail = MAX - 1;
    for (i = MAX - 1; i > 0; i--) {
        V->H[i].next = i - 1;
    }
    V->H[0].next = -1;
}

int allocSpace(VHeap* V) {
    int index = V->avail;
    if (index != -1) {
        V->avail = V->H[index].next;
    }
    return index;
}

void deallocSpace(VHeap* V, int index) {
    if (index >= 0 && index < MAX) {
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

void insertFirst(int* L, VHeap* V, int elem) {
    int newNode = allocSpace(V);
    if (newNode != -1) {
        V->H[newNode].elem = elem;
        V->H[newNode].next = *L;
        *L = newNode;
    }
}

void insertLast(int* L, VHeap* V, int elem) {
    int newNode = allocSpace(V);
    if (newNode != -1) {
        V->H[newNode].elem = elem;
        V->H[newNode].next = -1;
        
        int* trav;
        for (trav = L; *trav != -1; trav = &V->H[*trav].next) {}
        *trav = newNode;
    }
}

void insertPos(int* L, VHeap* V, int elem) {
    int newNode = allocSpace(V);
    if (newNode != -1) {
        V->H[newNode].elem = elem;
        V->H[newNode].next = *L;
        *L = newNode;
    }
}

void insertSorted(int* L, VHeap* V, int elem) {
    int newNode = allocSpace(V);
    if (newNode != -1) {
        V->H[newNode].elem = elem;
        int* trav;
        for (trav = L; *trav != -1 && V->H[*trav].elem < elem; trav = &V->H[*trav].next) {}
        V->H[newNode].next = *trav;
        *trav = newNode;
    }
}

void delete(int* L, VHeap* V, int elem) {
    int* trav;
    for (trav = L; *trav != -1 && V->H[*trav].elem != elem; trav = &V->H[*trav].next) {}
    if (*trav != -1) {
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int* L, VHeap* V, int elem) {
    int* trav = L;
    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            int temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V) {
    int curr = L;
    while (curr != -1) {
        printf("%d ", V.H[curr].elem);
        curr = V.H[curr].next;
    }
    printf("\n");
}
