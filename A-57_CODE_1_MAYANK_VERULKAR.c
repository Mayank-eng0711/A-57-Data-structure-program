#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot insert %d.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("\n%d pushed to stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No element to pop.\n");
    } else {
        printf("\n%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Function to view the top element
void peek() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nTop element is %d\n", stack[top]);
    }
}

// Function to display all stack elements
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
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
