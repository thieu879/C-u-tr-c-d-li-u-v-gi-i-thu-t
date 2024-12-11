#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct Queue
{
    int array[MAX];
    int front;
    int rear;
} Queue;
// kh?i t?o h�ng d?i
void initalQueue(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}
// ki?m tra h�ng d?i r?ng
int isEmpty(Queue *queue){
    if(queue->front == -1){
        printf("r�ngc r?i");
        return 1;
    }
    return 0;
}
// ki?m tra h�ng d?i d?y
int isFull(Queue *queue)
{
    if(queue->rear >= MAX-1){
        printf("d?y r?i");
        return 1;
    }
    return 0;
}
// th�m
void enqueue(Queue *queue, int value)
{
    if(isFull(queue)==1){
        printf("�?y r?i");
        return;
    }
    if(isEmpty(queue) == 1){
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}
// xo�
void dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("R?ng r?i xo� sao dc");
        return;
    }
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }else{
        queue->front++;
    }
}
// in ra c�i d?u
void peek(Queue *queue){
    if (isEmpty(queue))
    {
        printf("R?ng r?i xo� sao dc");
        return;
    }
    printf("ph?n t? d?u ti�n l�: %d", queue->array[queue->front]);
}
//in 
void printQueue(Queue *queue)
{
    int i;
    for (i = queue->front; i <= queue->rear; i++)
    {
        printf("%d \t", queue->array[i]);
    }
}
int main(){
    Queue queue;
    int value;
    initalQueue(&queue);
    do
    {
        printf("menu\n");
        printf("0. tho�t\n");
        printf("1. th�m v�o cu?i h�ng d?i\n");
        printf("2. hi?n ra h�ng d?i\n");
        printf("3. xo�\n");
        printf("4. l?y gi� tr? d?u\n");
        int choice;
        printf("Nh?p l?a ch?n:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Nh?p gi� tr?:");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            printQueue(&queue);
            break;
        case 3:
            dequeue(&queue);
            break;
        case 4:
            peek(&queue);
            break;
        default:
            break;
        }
    } while (1);

    return 0;
}

