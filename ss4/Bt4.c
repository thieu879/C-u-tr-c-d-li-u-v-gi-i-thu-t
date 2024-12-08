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

void printLinkList(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách tr?ng\n");
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

int searchValue(Node *head, int search)
{
    int index = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == search)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main()
{
    int n;
    printf("Nh?p s? lu?ng n: ");
    scanf("%d", &n);

    Node *head = createListLink(n);

    printf("Danh sách liên k?t: ");
    printLinkList(head);

    int search;
    printf("Nh?p giá tr? c?n tìm: ");
    scanf("%d", &search);

    int result = searchValue(head, search);
    if (result != -1)
    {
        printf("Giá tr? %d du?c tìm th?y t?i v? trí: %d\n", search, result);
    }
    else
    {
        printf("Giá tr? %d không t?n t?i trong danh sách\n", search);
    }

    return 0;
}

