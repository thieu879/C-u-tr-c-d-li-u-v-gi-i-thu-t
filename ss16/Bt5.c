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
int findMaxValue(struct Node *root) {
    if (root == NULL) {
        return -1;
    }
    if (root->right == NULL) {
        return root->data;
    }
    return findMaxValue(root->right);
}
int main() {
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);
    int maxValue = findMaxValue(root);
    if (maxValue == -1) {
        printf("Cay rong, khong co gia tri lon nhat.\n");
    } else {
        printf("Gia tri lon nhat trong cay nh? phan la: %d\n", maxValue);
    }
    return 0;
}

