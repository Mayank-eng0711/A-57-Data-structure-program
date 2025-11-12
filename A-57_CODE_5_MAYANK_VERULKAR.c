#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define MID (MAX / 2)

int queue[MAX];
int front1 = -1, rear1 = -1;
int front2 = MID, rear2 = MID;

// Enqueue in Queue 1
void enqueue1(int value) {
    if (rear1 == MID - 1) {
        printf("\nQueue 1 Overflow!\n");
    } else {
        if (front1 == -1)
            front1 = 0;
        queue[++rear1] = value;
        printf("%d inserted into Queue 1\n", value);
    }
}

// Enqueue in Queue 2
void enqueue2(int value) {
    if (rear2 == MAX - 1) {
        printf("\nQueue 2 Overflow!\n");
    } else {
        if (front2 == MID)
            front2 = MID + 1;
        queue[++rear2] = value;
        printf("%d inserted into Queue 2\n", value);
    }
}

// Dequeue from Queue 1
void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("\nQueue 1 Underflow!\n");
    } else {
        printf("%d removed from Queue 1\n", queue[front1++]);
    }
}

// Dequeue from Queue 2
void dequeue2() {
    if (front2 == MID || front2 > rear2) {
        printf("\nQueue 2 Underflow!\n");
    } else {
        printf("%d removed from Queue 2\n", queue[front2++]);
    }
}

// Display both queues
void display() {
    printf("\nQueue 1 elements: ");
    if (front1 == -1 || front1 > rear1)
        printf("Empty");
    else
        for (int i = front1; i <= rear1; i++)
            printf("%d ", queue[i]);

    printf("\nQueue 2 elements: ");
    if (front2 == MID || front2 > rear2)
        printf("Empty");
    else
        for (int i = front2; i <= rear2; i++)
            printf("%d ", queue[i]);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Two Queue Menu ---");
        printf("\n1. Enqueue in Queue 1");
        printf("\n2. Enqueue in Queue 2");
        printf("\n3. Dequeue from Queue 1");
        printf("\n4. Dequeue from Queue 2");
        printf("\n5. Display Queues");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue1(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue2(value);
                break;
            case 3:
                dequeue1();
                break;
            case 4:
                dequeue2();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
