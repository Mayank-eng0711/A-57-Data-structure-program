#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push value to stack
void push(int val) {
    stack[++top] = val;
}

// Pop value from stack
int pop() {
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    int i = 0;

    while (exp[i] != '\0') {
        // If space, skip it
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If digit, read the full number
        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }
        // Operator
        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
            i++;
        }
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression (use space between numbers):\n");
    fgets(exp, MAX, stdin);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
