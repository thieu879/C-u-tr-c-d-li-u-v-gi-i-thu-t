#include<stdio.h>
#define V 5
int visited[V];
int graph[V][V];
// hàm duy?t theo chi?u sâu DFS(v: d?nh, n: s? d?nh)
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
    printf("Nh?p s? d?nh c?a d? thì:");
    scanf("%d", &n);
    printf("Nh?p vào s? c?nh:");
    scanf("%d", &edges);
    printf("Nh?p các c?nh (d?nh u, v):");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    printf("Nh?p vào d?nh b?t d?u duy?t:");
    scanf("%d", &start);
    DFS(start, n);
    return 0;
}
