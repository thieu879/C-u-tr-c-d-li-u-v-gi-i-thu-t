#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho!\n");
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
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

bool isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) return true;

    if (root->data <= min || root->data >= max) return false;

    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -__INT_MAX__, __INT_MAX__);
}

int main() {
    Node* root = NULL;
    int choice, value;
    do {
        printf("\nMENU LUA CHON:\n");
        printf("1. Chen gia tri vao cay\n");
        printf("2. Tim kiem gia tri trong cay\n");
        printf("3. Duyet cay theo thu tu inorder\n");
        printf("4. Kiem tra tinh chat BST\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can chen: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Da chen %d vao cay.\n", value);
                break;
            case 2:
                printf("Nhap gia tri can tim kiem: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Gia tri %d duoc tim thay trong cay.\n", value);
                } else {
                    printf("Gia tri %d khong ton tai trong cay.\n", value);
                }
                break;
            case 3:
                printf("Cac gia tri trong cay (inorder): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                if (isBST(root)) {
                    printf("Cay la cay nhi phan tim kiem (BST).\n");
                } else {
                    printf("Cay KHONG la cay nhi phan tim kiem (BST).\n");
                }
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 5);

    return 0;
}

