#include<stdio.h>
#define V 5
int visited[V];
int graph[V][V];
// h�m duy?t theo chi?u s�u DFS(v: d?nh, n: s? d?nh)
void DFS(int v, int n){
    int i;
    printf("%d", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
    {
        if (visited[i] ==0 && graph[v][i]==1)
        {
            DFS(i, n);
        }
    }
    
}

int main(){
    int n, start, i, edges, u, v;
    printf("Nh?p s? d?nh c?a d? th�:");
    scanf("%d", &n);
    printf("Nh?p v�o s? c?nh:");
    scanf("%d", &edges);
    printf("Nh?p c�c c?nh (d?nh u, v):");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    printf("Nh?p v�o d?nh b?t d?u duy?t:");
    scanf("%d", &start);
    DFS(start, n);
    return 0;
}
