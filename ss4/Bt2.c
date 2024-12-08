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
        printf("Không d? b? nh? d? c?p phát!\n");
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
        printf("Nh?p giá tr? cho ph?n t? %d: ", i + 1);
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

Node *insertAtHead(Node *head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

void printLinkList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, valueToInsert;
    printf("Nh?p s? lu?ng n: ");
    scanf("%d", &n);

    Node *head = createListLink(n);

    printf("Danh sách ban d?u: ");
    printLinkList(head);

    printf("Nh?p giá tr? c?n chèn vào d?u danh sách: ");
    scanf("%d", &valueToInsert);

    head = insertAtHead(head, valueToInsert);

    printf("Danh sách sau khi chèn: ");
    printLinkList(head);

    return 0;
}

