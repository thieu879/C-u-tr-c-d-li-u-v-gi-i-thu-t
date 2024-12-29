#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Hàng d?i d?y\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Hàng d?i r?ng\n");
        return -1;
    }
    return queue[front++];
}
int isEmpty() {
    return front == -1 || front > rear;
}
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}
void BFS(int start) {
    int i;
    enqueue(start);
    visited[start] = 1;
    printf("Th? t? duy?t BFS: ");
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        Node* temp = adjList[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                enqueue(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
int main() {
    int V, E;
    int u, v;
    int start;
    printf("Nh?p s? d?nh: ");
    scanf("%d", &V);
    printf("Nh?p s? c?nh: ");
    scanf("%d", &E);
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    printf("Nh?p danh sách các c?nh (u, v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("Nh?p d?nh b?t d?u: ");
    scanf("%d", &start);
    BFS(start);
    return 0;
}

