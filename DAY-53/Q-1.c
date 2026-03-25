#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* queue[2000];
int front = 0, rear = 0;
void enqueueNode(struct TreeNode* node) {
    queue[rear++] = node;
}
struct TreeNode* dequeueNode() {
    return queue[front++];
}
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = newNode(arr[0]);
    enqueueNode(root);
    int i = 1;
    while (i < n) {
        struct TreeNode* curr = dequeueNode();
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueueNode(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueueNode(curr->right);
        }
        i++;
    }
    return root;
}
struct QNode {
    struct TreeNode* node;
    int hd;
};
struct Queue {
    struct QNode data[2000];
    int front, rear;
};
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}
void enqueue(struct Queue* q, struct TreeNode* node, int hd) {
    q->data[q->rear].node = node;
    q->data[q->rear].hd = hd;
    q->rear++;
}
struct QNode dequeue(struct Queue* q) {
    return q->data[q->front++];
}
void verticalOrder(struct TreeNode* root) {
    if (!root) return;
    struct Queue q;
    initQueue(&q);
    int map[2000][200];
    int size[2000] = {0};
    int offset = 1000;
    int min = 0, max = 0;
    enqueue(&q, root, 0);
    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct TreeNode* curr = temp.node;
        int hd = temp.hd;
        int index = hd + offset;
        map[index][size[index]++] = curr->val;
        if (hd < min) min = hd;
        if (hd > max) max = hd;
        if (curr->left)
            enqueue(&q, curr->left, hd - 1);
        if (curr->right)
            enqueue(&q, curr->right, hd + 1);
    }
    for (int i = min; i <= max; i++) {
        int index = i + offset;
        for (int j = 0; j < size[index]; j++) {
            printf("%d ", map[index][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}