#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// Precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Right associativity for ^
int isRightAssociative(char c) {
    return c == '^';
}

// Function to reverse a string
void reverse(char *exp) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Step 1: Reverse infix
    reverse(infix);

    // Step 2: Swap '(' and ')'
    for (i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 3: Convert reverse infix to postfix
    for (i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // Operand → add to postfix
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // '(' → push
        else if (c == '(') {
            push(c);
        }
        // ')' → pop until '('
        else if (c == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (!isEmpty() &&
                  (precedence(stack[top]) > precedence(c) ||
                  (precedence(stack[top]) == precedence(c) && !isRightAssociative(c))) &&
                  stack[top] != '(') {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    // Step 4: Reverse postfix → prefix
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix: %s\n", prefix);

    return 0;
}
