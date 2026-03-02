#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val;
    struct Node *head = NULL, *temp = NULL, *newNode, *last = NULL;

    scanf("%d", &n);

    // If no nodes
    if(n <= 0) return 0;

    // Create circular linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    // Make it circular
    last->next = head;

    // Traversal of circular linked list
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}