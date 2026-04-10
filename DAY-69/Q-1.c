#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 100
struct Node {
    int v, w;
    struct Node* next;
};
struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}
void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;
}
struct HeapNode {
    int vertex;
    int dist;
};
struct MinHeap {
    int size;
    struct HeapNode heap[N];
};
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;
    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;
    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}
void push(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;
    while (i != 0 && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}
void dijkstra(struct Node* adj[], int n, int src) {
    int dist[N];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    struct MinHeap h;
    h.size = 0;
    dist[src] = 0;
    push(&h, src, 0);
    while (h.size > 0) {
        struct HeapNode top = pop(&h);
        int u = top.vertex;
        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}
int main() {
    int n = 5;
    struct Node* adj[N] = {NULL};
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 7);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 4, 1);
    dijkstra(adj, n, 0);
    return 0;
}