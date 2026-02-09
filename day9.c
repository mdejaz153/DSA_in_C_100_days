#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int len;

    printf("Enter string: ");
    scanf("%s", str);   // since no spaces in input

    len = strlen(str);

    // Print in reverse order
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
