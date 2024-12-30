#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
struct Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
int searchRecursive(struct Node *root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    if (value < root->data) {
        return searchRecursive(root->left, value);
    } else {
        return searchRecursive(root->right, value);
    }
}

int searchIterative(struct Node *root, int value) {
    while (root != NULL) {
        if (root->data == value) {
            return 1;
        }
        if (value < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0;
}
int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    if (searchRecursive(root, value)) {
        printf("Gia tri %d duoc tim thay trong cay.\n", value);
    } else {
        printf("Gia tri %d khong ton tai trong cay.\n", value);
    }
    return 0;
}

