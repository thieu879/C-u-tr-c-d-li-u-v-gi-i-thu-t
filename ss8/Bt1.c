#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insertNode(Node *node, int data){
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data<node->data)
    {
        node->left = insertNode(node->left, data);
    }else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}
void preoderTraversal(Node *node){
    if(node!=NULL){
        printf("%d \t", node->data);
        preoderTraversal(node->left);
        preoderTraversal(node->right);
    }
}
void inoderTraversal(Node *node){
    if(node!=NULL){
    	preoderTraversal(node->left);
        printf("%d \t", node->data);
        preoderTraversal(node->right);
    }
}
void postoderTraversal(Node *node){
    if(node!=NULL){
        preoderTraversal(node->left);
        preoderTraversal(node->right);
        printf("%d \t", node->data);
    }
}
int main(){
    Node *tree = NULL;
    tree = insertNode(tree, 4);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 1);
    tree = insertNode(tree, 3);
    preoderTraversal(tree);
    inoderTraversal(tree);
    postoderTraversal(tree);
    return 0;
}

