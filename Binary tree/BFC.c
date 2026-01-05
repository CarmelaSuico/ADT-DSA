#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node **array;
    int front, rear, size;
} Queue;

Node* newNode(int data);
Queue* createQueue(int size);
void enqueue(Queue* queue, Node* node);
Node* dequeue(Queue* queue);
void BFS(Node* root);

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("BFS (Level Order Traversal): ");
    BFS(root);
    printf("\n");

    return 0;
}

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = queue->rear = 0;
    queue->array = (Node**)malloc(queue->size * sizeof(Node*));
    return queue;
}

void enqueue(Queue* queue, Node* node) {
    queue->array[queue->rear++] = node;
}

Node* dequeue(Queue* queue) {
    return queue->array[queue->front++];
}



void BFS(Node* root) {
    if (root == NULL) return;

    Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (queue->front < queue->rear) {
        Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
    free(queue->array);
    free(queue);
}

