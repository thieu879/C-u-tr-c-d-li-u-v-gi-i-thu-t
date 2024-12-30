#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
struct Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}
void preOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (root->data < data) {
        root->right = insert(root->right, data);
    } else if (root->data > data) {
        root->left = insert(root->left, data);
    }
    return root;
}
int findHeight(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 3);
    printf("Duy?t cây theo th? t? tru?c (Pre-Order): ");
    preOrder(root);
    printf("\n");
    int height = findHeight(root);
    printf("Chi?u cao c?a cây nh? phân: %d\n", height);

    return 0;
}

