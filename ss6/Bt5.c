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

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Ngan x?p dã d?y! Không th? thêm ph?n t?.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan x?p r?ng! Không th? l?y ph?n t?.\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

void reverseString(char str[]) {
    Stack stack;
    initStack(&stack);
	int i;
    for (i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    printf("Chu?i d?o ngu?c: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    char str[MAX_SIZE];

    printf("Nh?p n: ");
    fgets(str, MAX_SIZE, stdin);

    reverseString(str);

    return 0;
}

