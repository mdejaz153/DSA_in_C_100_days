#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize empty queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear  = NULL;
}

// Enqueue: insert at rear
void enqueue(struct Queue* q, int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;

    if (q->rear == NULL) {
        // Queue is empty
        q->front = node;
        q->rear  = node;
    } else {
        q->rear->next = node;
        q->rear       = node;
    }
}

// Dequeue: remove from front
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = temp->next;
    if (q->front == NULL)
        q->rear = NULL;   // queue became empty
    free(temp);
    return val;
}

// Display from front to rear
void display(struct Queue* q) {
    struct Node* curr = q->front;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL)
            printf(" ");
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
    }

    display(&q);

    return 0;
}