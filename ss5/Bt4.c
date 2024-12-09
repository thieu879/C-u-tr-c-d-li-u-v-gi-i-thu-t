#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Kh�ng d? b? nh? d? c?p ph�t!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createDoublyLinkedList(int n) {
    Node *head = NULL, *tail = NULL;
    int i;
    for (i = 0; i < n; i++) {
        int value;
        printf("Nh?p gi� tr? cho ph?n t? %d: ", i + 1);
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

int countElements(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printDoublyLinkedList(Node *head) {
    if (head == NULL) {
        printf("Danh s�ch r?ng\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("Nh?p s? lu?ng ph?n t? n: ");
    scanf("%d", &n);

    Node *head = createDoublyLinkedList(n);

    printf("Danh s�ch li�n k?t d�i: ");
    printDoublyLinkedList(head);

    int count = countElements(head);

    printf("S? ph?n t? trong danh s�ch: %d\n", count);

    return 0;
}

