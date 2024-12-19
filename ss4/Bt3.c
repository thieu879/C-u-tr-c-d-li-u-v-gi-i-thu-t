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

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        printf("Danh s�ch tr?ng, kh�ng th? x�a ph?n t? d?u ti�n!\n");
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
Node *deleteTail(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng, không có gì để xóa.\n");
        return NULL;
    }
    if (head->next == NULL)
    { // Chỉ có một phần tử
        free(head);
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next; // Di chuyển tới node trước node cuối cùng
    }
    free(temp->next); // Xóa node cuối
    temp->next = NULL;
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

int main()
{
    int n;
    printf("Nh?p s? lu?ng n: ");
    scanf("%d", &n);

    Node *head = createListLink(n);

    printf("Danh s�ch ban d?u: ");
    printLinkList(head);

    head = deleteHead(head);

    printf("Danh s�ch sau khi x�a ph?n t? d?u ti�n: ");
    printLinkList(head);

    return 0;
}

