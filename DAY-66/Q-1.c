#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;
    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }
    recStack[node] = false;
    return false;
}
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}
int main() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }
    if (hasCycle())
        printf("YES (Cycle exists)\n");
    else
        printf("NO (No cycle)\n");
    return 0;
}