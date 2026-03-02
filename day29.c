#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// create new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// rotate list right by k
struct node* rotateRight(struct node* head, int n, int k) {
    if (head == NULL || k == 0)
        return head;

    k = k % n;   // if k > n
    if (k == 0)
        return head;

    struct node* temp = head;
    int count = 1;

    // go to last node
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // make circular
    temp->next = head;

    // go to (n-k)th node
    int steps = n - k;
    temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // new head
    struct node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

// print list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x, k;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (head == NULL) {
            head = createNode(x);
            temp = head;
        } else {
            temp->next = createNode(x);
            temp = temp->next;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, n, k);

    printList(head);

    return 0;
}