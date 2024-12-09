#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
        Node* newNode = createNode(value);
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

void printDoublyLinkedList(Node* head) {
    if (head == NULL) {
        printf("Danh s�ch r?ng\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void replaceElement(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    }
    printf("Kh�ng t�m th?y ph?n t? c?n thay th?\n");
}

int main() {
    int n;
    printf("Nh?p s? lu?ng ph?n t? n: ");
    scanf("%d", &n);

    Node* head = createDoublyLinkedList(n);

    printf("Danh s�ch li�n k?t d�i ban d?u: ");
    printDoublyLinkedList(head);

    int oldValue, newValue;
    printf("Gi� tr? c?n thay th?: ");
    scanf("%d", &oldValue);
    printf("Gi� tr? m?i: ");
    scanf("%d", &newValue);

    replaceElement(head, oldValue, newValue);

    printf("Danh s�ch sau khi thay th?: ");
    printDoublyLinkedList(head);

    return 0;
}

