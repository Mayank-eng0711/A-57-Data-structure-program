#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

// Push to Stack 1
void push1(int value) {
    if (top1 + 1 == top2) {
        printf("\nStack Overflow! No space to push %d\n", value);
        return;
    }
    arr[++top1] = value;
    printf("%d pushed to Stack 1\n", value);
}

// Push to Stack 2
void push2(int value) {
    if (top2 - 1 == top1) {
        printf("\nStack Overflow! No space to push %d\n", value);
        return;
    }
    arr[--top2] = value;
    printf("%d pushed to Stack 2\n", value);
}

// Pop from Stack 1
void pop1() {
    if (top1 == -1) {
        printf("\nStack 1 Underflow!\n");
        return;
    }
    printf("%d popped from Stack 1\n", arr[top1--]);
}

// Pop from Stack 2
void pop2() {
    if (top2 == MAX) {
        printf("\nStack 2 Underflow!\n");
        return;
    }
    printf("%d popped from Stack 2\n", arr[top2++]);
}

// Display both stacks
void display() {
    printf("\nStack 1 elements: ");
    if (top1 == -1)
        printf("Empty");
    else
        for (int i = 0; i <= top1; i++)
            printf("%d ", arr[i]);

    printf("\nStack 2 elements: ");
    if (top2 == MAX)
        printf("Empty");
    else
        for (int i = MAX - 1; i >= top2; i--)
            printf("%d ", arr[i]);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Two Stack Menu ---");
        printf("\n1. Push in Stack 1");
        printf("\n2. Push in Stack 2");
        printf("\n3. Pop from Stack 1");
        printf("\n4. Pop from Stack 2");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
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
