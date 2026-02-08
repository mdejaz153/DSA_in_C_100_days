#include <stdio.h>

// Recursive function
int power(int a, int b) {
    if (b == 0)          // base case
        return 1;
    else
        return a * power(a, b - 1);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", power(a, b));
    return 0;
}
