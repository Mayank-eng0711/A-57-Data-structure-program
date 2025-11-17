#include <stdio.h>
#include <ctype.h>   // For isalnum()
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push to stack
void push(char c) {
    stack[++top] = c;
}

// Pop from stack
char pop() {
    return stack[top--];
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Check associativity (Right associative only for ^)
int isRightAssociative(char op) {
    return op == '^';
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand, add to postfix
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        }
        // Operator
        else {
            while (!isEmpty() && precedence(stack[top]) > precedence(c) ||
                  (!isEmpty() && precedence(stack[top]) == precedence(c) && !isRightAssociative(c))) {
                if (stack[top] == '(') break;
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
