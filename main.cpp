#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *items;
int front = -1;
int rear = -1;
int max_size;
void createQueue(int size)
{
    max_size = size;
    items = (int *)malloc(size * sizeof(int));
}
void destroyQueue()
{
    free(items);
}
bool isFull()
{
    return (rear == max_size - 1);
}
bool isEmpty()
{
    return (front == -1 || front > rear);
}
void resizeQueue()
{
    max_size *= 2;
    items = (int *)realloc(items, max_size * sizeof(int));
    if (items == NULL)
    {
        printf("Memory allocation failed during resizing.\n");
        exit(1);
    }
    printf("Queue resized to %d.\n", max_size);
}
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full. Resizing...\n");
        resizeQueue();
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    items[rear] = value;
    printf("Enqueued: %d\n", value);
}
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = items[front];
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}
void displayQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", items[i]);
    }
    printf("\n");
}
int main()
{
    int choice, value;
    int size;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &size);
    createQueue(size);
    while (true)
    {
        printf("\nMenu:\n");
        printf("1. Push (enqueue)\n");
        printf("2. Pop (dequeue)\n");
        printf("3. Display Queue Content\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("Exiting\n");
            destroyQueue();
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
