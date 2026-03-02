#include <stdio.h>
#include <stdlib.h>

// structure for doubly linked list node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    int n, x;
    struct node *head = NULL, *temp = NULL, *newnode;

    scanf("%d", &n);   // number of nodes

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        // create new node
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->prev = NULL;
        newnode->next = NULL;

        // if list empty
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // traversal forward
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}