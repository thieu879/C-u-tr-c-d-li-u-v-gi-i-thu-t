#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5

typedef struct {
    char data[100];
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
    deque->size = 0;
}

int isEmpty(Deque *deque) {
    return deque->size == 0;
}

int isFull(Deque *deque) {
    return deque->size == MAX_SIZE;
}

void addFront(Deque *deque, const char *data) {
    if (isFull(deque)) {
        printf("Ð?y r?i");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    strcpy(deque->elements[deque->front].data, data);
    deque->size++;
}

void addRear(Deque *deque, const char *data) {
    if (isFull(deque)) {
        printf("Ð?y r?i");
        return;
    }

    if (isEmpty(deque)) {
        deque->front = deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    strcpy(deque->elements[deque->rear].data, data);
    deque->size++;
}

void removeFront(Deque *deque) {
    if (isEmpty(deque)) {
        printf("R?ng\n");
        return;
    }

    printf("L?y ra ph?n t? t? d?u: \"%s\".\n", deque->elements[deque->front].data);
    deque->front = (deque->front + 1) % MAX_SIZE;
    deque->size--;
    if (deque->size == 0) {
        deque->front = deque->rear = -1;
    }
}

void removeRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("R?ng\n");
        return;
    }

    printf("L?y ra ph?n t? t? cu?i: \"%s\".\n", deque->elements[deque->rear].data);
    deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    deque->size--;
    if (deque->size == 0) {
        deque->front = deque->rear = -1;
    }
}

void printDeque(Deque *deque) {
	int count;
    if (isEmpty(deque)) {
        printf("R?ng\n");
        return;
    }

    printf("Hàng d?i hi?n t?i: ");
    int i = deque->front;
    for (count = 0; count < deque->size; count++) {
        printf("%s", deque->elements[i].data);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Thêm ph?n t? vào d?u\n");
        printf("2. Thêm ph?n t? vào cu?i\n");
        printf("3. L?y ph?n t? t? d?u\n");
        printf("4. L?y ph?n t? t? cu?i\n");
        printf("5. In hàng d?i\n");
        printf("6. Thoát\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char data[100];
                printf("Nh?p d? li?u: ");
                scanf("%s", data);
                addFront(&deque, data);
                break;
            }
            case 2: {
                char data[100];
                printf("Nh?p d? li?u: ");
                scanf("%s", data);
                addRear(&deque, data);
                break;
            }
            case 3:
                removeFront(&deque);
                break;
            case 4:
                removeRear(&deque);
                break;
            case 5:
                printDeque(&deque);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Ðùa t à\n");
        }
    } while (1);

    return 0;
}

