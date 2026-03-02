#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// function to create list
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int x;

    for(int i = 0; i < n; i++) {
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
    return head;
}

// function to get length
int getLength(struct node *head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// function to find intersection
int findIntersection(struct node *head1, struct node *head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for(int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // move both together
    while(head1 != NULL && head2 != NULL) {
        if(head1 == head2)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1; // no intersection
}

int main() {

    int n, m;

    scanf("%d", &n);
    struct node *head1 = createList(n);

    scanf("%d", &m);
    struct node *head2 = createList(m);

    int result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
