#include <stdio.h>
#include <stdlib.h>
#define V 4

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// T?o m?t n�t m?i v� tr? v? con tr? t?i n�t d�
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Th�m m?t c?nh v�o danh s�ch k?
void addEdgeOfNode(Node *arr[], int i, int j) {
    Node *newNode = createNode(j);
    newNode->next = arr[i];
    arr[i] = newNode;

    newNode = createNode(i);
    newNode->next = arr[j];
    arr[j] = newNode;
}

// In ra danh s�ch k?
void printList(Node *arr[]) {
	int i;
    for (i = 0; i < V; i++) {
        printf("%d: ", i);
        Node *temp = arr[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Th�m m?t c?nh v�o ma tr?n k?
void addEdge(int matrix[V][V], int i, int j) {
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

// In ra ma tr?n k?
void printMatrix(int matrix[V][V]) {
	int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[V][V] = {0};

    // Th�m c�c c?nh v�o ma tr?n k?
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 2);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 1, 3);

    printf("Ma tr?n k?:\n");
    printMatrix(matrix);

    // T?o danh s�ch k? r?ng
    Node *adj[V];
    int i;
    for (i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Th�m c�c c?nh v�o danh s�ch k?
    addEdgeOfNode(adj, 0, 1);
    addEdgeOfNode(adj, 0, 2);
    addEdgeOfNode(adj, 1, 2);
    addEdgeOfNode(adj, 1, 3);

    printf("\nDanh s�ch k?:\n");
    printList(adj);

    return 0;
}

