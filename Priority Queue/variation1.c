#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int lastNdx;
} PriorityQueue;

void initialize(PriorityQueue *PQ) {
    PQ->lastNdx = -1;
}

void insert(PriorityQueue *PQ, int key);
int deleteMax(PriorityQueue *PQ);
void display(PriorityQueue PQ);

int main() {
    PriorityQueue PQ;
    initialize(&PQ);

    insert(&PQ, 15);
    insert(&PQ, 30);
    insert(&PQ, 20);
    insert(&PQ, 40);

    printf("Priority Queue (Heap Array): ");
    display(PQ);

    printf("Deleted Max: %d\n", deleteMax(&PQ));
    printf("After deletion: ");
    display(PQ);

    return 0;
}

void insert(PriorityQueue *PQ, int key) {
    if (PQ->lastNdx < MAX - 1) {
        PQ->lastNdx++;
        int curr = PQ->lastNdx;

        while (curr > 0 && PQ->elem[(curr - 1) / 2] < key) {
            PQ->elem[curr] = PQ->elem[(curr - 1) / 2];
            curr = (curr - 1) / 2;
        }
        PQ->elem[curr] = key;
    }
}



int deleteMax(PriorityQueue *PQ) {
    int max = -1;
    if (PQ->lastNdx != -1) {
        max = PQ->elem[0];
        int lastElement = PQ->elem[PQ->lastNdx];
        PQ->lastNdx--;

        if (PQ->lastNdx >= 0) {
            int curr = 0;
            int child;

            while (curr * 2 + 1 <= PQ->lastNdx) {
                child = curr * 2 + 1;
                if (child + 1 <= PQ->lastNdx && PQ->elem[child + 1] > PQ->elem[child]) {
                    child++;
                }

                if (lastElement < PQ->elem[child]) {
                    PQ->elem[curr] = PQ->elem[child];
                    curr = child;
                } else {
                    break;
                }
            }
            PQ->elem[curr] = lastElement;
        }
    }
    return max;
}



void display(PriorityQueue PQ) {
    int i;
    for (i = 0; i <= PQ.lastNdx; i++) {
        printf("%d ", PQ.elem[i]);
    }
    printf("\n");
}

