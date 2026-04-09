#include <stdio.h>
#define MAX 100
int queue[MAX], front = 0, rear = 0;
void enqueue(int x) {
    queue[rear++] = x;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}
void topologicalSort(int n, int graph[MAX][MAX]) {
    int indegree[MAX] = {0};
    int result[MAX];
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }
    while (!isEmpty()) {
        int u = dequeue();
        result[index++] = u;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }
    if (index != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }
    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}
int main() {
    int n = 6;
    int graph[MAX][MAX] = {
        {0,1,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };
    topologicalSort(n, graph);
    return 0;
}