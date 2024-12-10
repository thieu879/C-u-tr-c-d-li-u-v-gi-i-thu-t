#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Stack {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Ngan x?p dã d?y! Không th? thêm ph?n t?.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top--];
}

int isValidExpression(const char *expression) {
    Stack stack;
    initStack(&stack);
	int i;
    for (i = 0; i < strlen(expression); i++) {
        char current = expression[i];

        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        }
        else if (current == ')' || current == '}' || current == ']') {
            char top = pop(&stack);

            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                return 0;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];

    printf("Nh?p bi?u th?c: ");
    fgets(expression, MAX_SIZE, stdin);

    expression[strcspn(expression, "\n")] = '\0';

    if (isValidExpression(expression)) {
        printf("Bi?u th?c h?p l?\n");
    } else {
        printf("Bi?u th?c không h?p l?\n");
    }

    return 0;
}

