#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    int choice;
    printf("Nhap 1 de chen %d vao ben trai cua %d, nhap 2 de chen ben phai: ", data, node->data);
    scanf("%d", &choice);

    if (choice == 1) {
        node->left = insertNode(node->left, data);
    } else if (choice == 2) {
        node->right = insertNode(node->right, data);
    } else {
        printf("Lua chon khong hop le\n");
    }
    return node;
}

void preorderTraversal(Node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void findLevel2Nodes(Node *root) {
    if (root == NULL) {
        printf("Cay rong\n");
        return;
    }

    int hasLevel2Nodes = 0;

    if (root->left != NULL) {
        if (root->left->left != NULL || root->left->right != NULL) {
            hasLevel2Nodes = 1;
            printf("%d ", root->left->left != NULL ? root->left->left->data : -1);
            printf("%d ", root->left->right != NULL ? root->left->right->data : -1);
        }
    }

    if (root->right != NULL) {
        if (root->right->left != NULL || root->right->right != NULL) {
            hasLevel2Nodes = 1;
            printf("%d ", root->right->left != NULL ? root->right->left->data : -1);
            printf("%d ", root->right->right != NULL ? root->right->right->data : -1);
        }
    }

    if (!hasLevel2Nodes) {
        printf("Khong co dinh lop 2\n");
    }
}

int main() {
    Node *tree = NULL;
    int n, i, value;

    printf("Nhap so luong nut cua cay: ");
    scanf("%d", &n);

    printf("Nhap gia tri nut goc: ");
    scanf("%d", &value);
    tree = createNode(value);

    for (i = 1; i < n; i++) {
        printf("Nhap gia tri nut thu %d: ", i + 1);
        scanf("%d", &value);
        tree = insertNode(tree, value);
    }

    printf("\nCac dinh trong cay: ");
    preorderTraversal(tree);
    printf("\n");

    printf("Cac dinh lop 2: ");
    findLevel2Nodes(tree);

    return 0;
}

