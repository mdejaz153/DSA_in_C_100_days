#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x)
{
    if(size == MAX)
    {
        return;
    }

    int i = size - 1;

    // shift elements greater than x
    while(i >= 0 && pq[i] > x)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

// Delete element (highest priority = smallest)
int delete()
{
    if(size == 0)
        return -1;

    int val = pq[0];

    for(int i = 0; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;

    return val;
}

// Peek element
int peek()
{
    if(size == 0)
        return -1;

    return pq[0];
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char op[10];
        scanf("%s", op);

        if(op[0] == 'i')  // insert
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd')  // delete
        {
            printf("%d\n", delete());
        }
        else if(op[0] == 'p')  // peek
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}