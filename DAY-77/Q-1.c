#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
struct Node {
    int val;
    struct Node* next;
};
struct Node* adj[MAXN];
int visited[MAXN];
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}
void dfs(int u) {
    visited[u] = 1;
    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->val;
        if (!visited[v]) {
            dfs(v);
        }
        temp = temp->next;
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); 
    }
    dfs(1);
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");
    return 0;
}