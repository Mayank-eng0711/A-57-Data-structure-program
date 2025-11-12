#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to add an element (enqueue)
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert %d.\n", value);
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("\n%d inserted into the queue.\n", value);
    }
}

// Function to remove an element (dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No element to remove.\n");
    } else {
        printf("\n%d removed from the queue.\n", queue[front]);
        front++;
    }
}

// Function to view the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nFront element is %d\n", queue[front]);
    }
}

// Function to display all elements
void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
