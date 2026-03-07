#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Push onto stack
void push(struct Node** top, int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = *top;
    *top = node;
}

// Pop from stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow!\n");
        exit(1);
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

void processToken(char* token, struct Node** stack) {
    if (strlen(token) == 1 &&
        (token[0] == '+' || token[0] == '-' ||
         token[0] == '*' || token[0] == '/')) {
        int b = pop(stack);
        int a = pop(stack);
        int result;
        switch (token[0]) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
        }
        push(stack, result);
    } else {
        push(stack, atoi(token));
    }
}

int main() {
    struct Node* stack = NULL;
    char line[1000];
    char token[20];
    int j = 0;

    printf("Enter postfix expression: ");
    fgets(line, sizeof(line), stdin);  // reads full line on Enter

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\n') {
            if (j > 0) {
                token[j] = '\0';
                j = 0;
                processToken(token, &stack);
            }
        } else {
            token[j++] = line[i];
        }
    }

    // last token if no trailing space
    if (j > 0) {
        token[j] = '\0';
        processToken(token, &stack);
    }

    printf("Result: %d\n", pop(&stack));
    return 0;
}