#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

int main() {
    int n, x, i;
    struct node *head = NULL, *temp, *newnode;
    int count = 0;

    // Input number of elements
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Print linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }

    // Count nodes
    // printf("\nTotal nodes = %d", count);   // (uncomment if teacher asks count)

    return 0;
}