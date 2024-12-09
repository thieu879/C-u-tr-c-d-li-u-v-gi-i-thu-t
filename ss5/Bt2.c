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
        printf("Không d? b? nh? d? c?p phát!\n");
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
        printf("Nh?p giá tr? cho ph?n t? %d: ", i + 1);
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

void printDoublyLinkedList(Node *head) {
    if (head == NULL) {
        printf("Danh sách tr?ng\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtPosition(Node **head, int value, int position) {
    Node *newNode = createNode(value);
    if (*head == NULL && position == 0) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    int index = 0;

    if (position == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("L?i v? trí không h?p l?\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

int main() {
    int n;
    printf("Nh?p s? lu?ng ph?n t? n: ");
    scanf("%d", &n);

    Node *head = createDoublyLinkedList(n);

    printf("Danh sách liên k?t dôi ban d?u: ");
    printDoublyLinkedList(head);

    int value, position;
    printf("Giá tr? c?n chèn: ");
    scanf("%d", &value);
    printf("V? trí c?n chèn: ");
    scanf("%d", &position);

    insertAtPosition(&head, value, position);

    printf("Danh sách liên k?t dôi sau khi chèn: ");
    printDoublyLinkedList(head);

    return 0;
}

