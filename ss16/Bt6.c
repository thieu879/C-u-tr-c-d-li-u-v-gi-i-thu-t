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
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
int countNodesGreaterThanX(struct Node *root, int X) {
    if (root == NULL) {
        return 0;
    }
    int count = (root->data > X) ? 1 : 0;
    count += countNodesGreaterThanX(root->left, X);
    count += countNodesGreaterThanX(root->right, X);
    return count;
}
int main() {
    Node *root = NULL;
    int X;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);
    printf("Nhap gia tri X: ");
    scanf("%d", &X);
    int count = countNodesGreaterThanX(root, X);
    printf("So luong nut co gia tri lon hon %d la: %d\n", X, count);

    return 0;
}

