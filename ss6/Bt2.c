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

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngan x?p d� d?y! Kh�ng th? th�m ph?n t?.\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan x?p r?ng! Kh�ng th? x�a ph?n t?.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void printStack(Stack *stack) {
	int i;
    if (isEmpty(stack)) {
        printf("Ngan x?p r?ng.\n");
        return;
    }
    printf("C�c ph?n t? trong ngan x?p c�n l?i:\n");
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

int main() {
	int i;
    Stack stack;
    initStack(&stack);
    int n, value;

    printf("Nh?p n: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("S? lu?ng ph?n t? vu?t qu� k�ch thu?c t?i da c?a ngan x?p.\n");
        return 1;
    }

    printf("Nh?p c�c ph?n t?:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    int poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("Ph?n t? b? x�a: %d\n", poppedValue);
    }

    printStack(&stack);

    return 0;
}

