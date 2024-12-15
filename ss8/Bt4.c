#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Kh�ng th? c?p ph�t b? nh?!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    char direction;
    printf("Ch�n %d v�o b�n tr�i ho?c ph?i c?a %d? ", value, root->data);
    scanf(" %c", &direction);

    if (direction == 'L' || direction == 'l') {
        root->left = insert(root->left, value);
    } else if (direction == 'R' || direction == 'r') {
        root->right = insert(root->right, value);
    } else {
        printf("Hu?ng kh�ng h?p l?\n");
    }
    return root;
}

int calculateHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    Node* root = NULL;
    int n, value, i;

    printf("Nh?p s? lu?ng d?nh c?a c�y: ");
    scanf("%d", &n);

    printf("Nh?p gi� tr? cho n�t g?c: ");
    scanf("%d", &value);
    root = createNode(value);

    for (i = 1; i < n; i++) {
        printf("Nh?p gi� tr? c?a n�t %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    int height = calculateHeight(root);
    printf("Chi?u cao c?a c�y l�: %d\n", height);

    return 0;
}

