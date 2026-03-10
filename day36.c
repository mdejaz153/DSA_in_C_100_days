#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int size = 0;

void enqueue(int value, int n)
{
    rear = (rear + 1) % n;
    queue[rear] = value;
    size++;
}

int dequeue(int n)
{
    int val = queue[front];
    front = (front + 1) % n;
    size--;
    return val;
}

int main()
{
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int val = dequeue(n);
        enqueue(val, n);
    }

    for(int i = 0; i < n; i++)
    {
        int index = (front + i) % n;
        printf("%d ", queue[index]);
    }

    return 0;
}