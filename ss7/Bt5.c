#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5

typedef struct Queue{
    int priority;
    char data[100];
} Queue;

typedef struct {
    Queue elements[MAX_SIZE];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *queue) {
    queue->size = 0;
}

int isEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

int isFull(PriorityQueue *queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(PriorityQueue *queue, int priority, const char *data) {
	int i;
    if (isFull(queue)) {
        printf("Hàng d?i dã d?y\n");
        return;
    }

    Queue newElement = {priority, ""};
    strcpy(newElement.data, data);
    queue->elements[queue->size++] = newElement;

    for (i = queue->size - 1; i > 0; i--) {
        if (queue->elements[i].priority < queue->elements[i - 1].priority) {
            Queue temp = queue->elements[i];
            queue->elements[i] = queue->elements[i - 1];
            queue->elements[i - 1] = temp;
        }
    }
}

void dequeue(PriorityQueue *queue) {
	int i;
    if (isEmpty(queue)) {
        printf("Hàng d?i r?ng! Không th? l?y ph?n t? ra.\n");
        return;
    }

    Queue removedElement = queue->elements[0];

    for (i = 1; i < queue->size; i++) {
        queue->elements[i - 1] = queue->elements[i];
    }
    queue->size--;

    printf("L?y ra ph?n t?: \"%s\" (uu tiên %d)\n", removedElement.data, removedElement.priority);
}

// In tr?ng thái hàng d?i
void printQueue(PriorityQueue *queue) {
	int i;
    if (isEmpty(queue)) {
        printf("R?ng\n");
        return;
    }

    printf("Hàng d?i hi?n t?i: ");
    for (i = 0; i < queue->size; i++) {
        printf("(%d, \"%s\") ", queue->elements[i].priority, queue->elements[i].data);
    }
    printf("\n");
}

void peek(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("R?ng\n");
        return;
    }

    Queue topElement = queue->elements[0];
    printf("Ph?n t? uu tiên cao nh?t: %s\n", topElement.data);
}

int main() {
    PriorityQueue queue;
    initQueue(&queue);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Thêm ph?n t? (enqueue)\n");
        printf("2. L?y ph?n t? ra (dequeue)\n");
        printf("3. Xem ph?n t? uu tiên cao nh?t (peek)\n");
        printf("4. In hàng d?i (printQueue)\n");
        printf("5. Thoát\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int priority;
                char data[100];
                printf("Nh?p m?c d? uu tiên: ");
                scanf("%d", &priority);
                printf("Nh?p d? li?u: ");
                scanf("%s", data);
                enqueue(&queue, priority, data);
                break;
            }
            case 2:
                dequeue(&queue);
                break;
            case 3:
                peek(&queue);
                break;
            case 4:
                printQueue(&queue);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("L?a ch?n không h?p l?\n");
        }
    } while (1);

    return 0;
}

