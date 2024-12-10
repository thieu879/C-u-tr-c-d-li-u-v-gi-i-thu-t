#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Ngan x?p d� d?y! Kh�ng th? th�m ph?n t?.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

void checkEmpty(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan x?p r?ng.\n");
    } else {
        printf("Ngan x?p kh�ng r?ng.\n");
    }
}

int main() {
    Stack stack;
    initStack(&stack);
    int n, value, i;

    printf("Nh?p n: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("S? lu?ng ph?n t? vu?t qu� k�ch thu?c t?i da c?a ngan x?p.\n");
        return 1;
    }

    if (n > 0) {
        printf("Nh?p c�c ph?n t?:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &value);
            push(&stack, value);
        }
    }

    checkEmpty(&stack);

    return 0;
}

