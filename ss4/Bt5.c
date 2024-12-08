#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Kh�ng d? b? nh? d? c?p ph�t!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *createListLink(int n)
{
    Node *head = NULL, *tail = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        int value;
        printf("Nh?p gi� tr? cho ph?n t? %d: ", i + 1);
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printLinkList(Node *head)
{
    if (head == NULL)
    {
        printf("Danh s�ch tr?ng\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *insertAtPosition(Node *head, int value, int position)
{
    Node *newNode = createNode(value);

    if (position == 0)
    {
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < position - 1)
    {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL)
    {
        printf("V? tr� n?m ngo�i ph?m vi danh s�ch. Kh�ng th? ch�n!\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

int main()
{
    int n;
    printf("Nh?p s? lu?ng n: ");
    scanf("%d", &n);

    Node *head = createListLink(n);

    printf("Danh s�ch li�n k?t ban d?u: ");
    printLinkList(head);

    int value, position;
    printf("Nh?p gi� tr? c?n ch�n: ");
    scanf("%d", &value);
    printf("Nh?p v? tr� c?n ch�n: ");
    scanf("%d", &position);

    head = insertAtPosition(head, value, position);

    printf("Danh s�ch li�n k?t sau khi ch�n: ");
    printLinkList(head);

    return 0;
}

