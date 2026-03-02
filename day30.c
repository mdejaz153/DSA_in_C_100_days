#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

// create node
struct node* createNode(int c, int e) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, c, e;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL;

    // create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);

        struct node* newNode = createNode(c, e);

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // print polynomial
    temp = head;
    while(temp != NULL) {

        if(temp->exp == 0) {
            printf("%d", temp->coeff);
        }
        else if(temp->exp == 1) {
            printf("%dx", temp->coeff);
        }
        else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}