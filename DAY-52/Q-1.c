#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
struct Queue {
    struct Node* arr[1000];
    int front, rear;
};
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Queue q;
    initQueue(&q);
    struct Node* root = newNode(arr[0]);
    enqueue(&q, root);
    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(&q);
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }
    return root;
}
struct Node* LCA(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;
    if (root->data == p || root->data == q)
        return root;
    struct Node* left = LCA(root->left, p, q);
    struct Node* right = LCA(root->right, p, q);
    if (left && right)
        return root;
    return (left != NULL) ? left : right;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int p, q;
    scanf("%d %d", &p, &q);
    struct Node* root = buildTree(arr, n);
    struct Node* ans = LCA(root, p, q);
    if (ans != NULL)
        printf("%d\n", ans->data);
    else
        printf("LCA not found\n");
    return 0;
}