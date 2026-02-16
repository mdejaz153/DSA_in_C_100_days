#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(int i = 0; i < n; i++) {
        int count = 1;

        // Skip if already counted
        if(arr[i] == -1)
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -1;  // mark counted
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
