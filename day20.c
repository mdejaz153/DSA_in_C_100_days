#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // prefix sum array (n+1)
    long long prefix[n + 1];
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // sort prefix array
    qsort(prefix, n + 1, sizeof(long long), cmp);

    long long count = 0;
    long long freq = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix[i] == prefix[i - 1]) {
            freq++;
        } else {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }

    // last frequency add
    count += (freq * (freq - 1)) / 2;

    printf("%lld", count);

    return 0;
}