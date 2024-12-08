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
        printf("V? trí n?m ngoài ph?m vi danh sách. Không th? chèn!\n");
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

    printf("Danh sách liên k?t ban d?u: ");
    printLinkList(head);

    int value, position;
    printf("Nh?p giá tr? c?n chèn: ");
    scanf("%d", &value);
    printf("Nh?p v? trí c?n chèn: ");
    scanf("%d", &position);

    head = insertAtPosition(head, value, position);

    printf("Danh sách liên k?t sau khi chèn: ");
    printLinkList(head);

    return 0;
}

