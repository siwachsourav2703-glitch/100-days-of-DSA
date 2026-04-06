#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int dfs(int node, int parent, int V) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, V))
                    return 1;
            }
            else if (i != parent) {
                return 1; 
            }
        }
    }
    return 0;
}
int isCycle(int V) {
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V))
                return 1;
        }
    }
    return 0;
}
int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }
    if (isCycle(V))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}