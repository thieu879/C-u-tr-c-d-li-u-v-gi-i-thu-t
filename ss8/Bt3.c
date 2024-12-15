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
        printf("C?p phát b? nh? th?t b?i\n");
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

int search(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }

    if (root->data == value) {
        return 1;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);
    int i;

    for (i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    int searchValue;

    printf("Nh?p giá tr? c?n tìm: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue)) {
        printf("Ðã tìm th?y\n");
    } else {
        printf("Không tìm th?y\n");
    }

    return 0;
}

