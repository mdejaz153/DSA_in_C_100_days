#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[100][100];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check square condition
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int symmetric = 1;

    // Compare a[i][j] with a[j][i]
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if(symmetric == 0)
            break;
    }

    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
