#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* queue[1000];
int front = 0, rear = 0;
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
void zigzagTraversal(struct Node* root) {
    if (!root) return;
    struct Node* q[1000];
    int f = 0, r = 0;
    q[r++] = root;
    int leftToRight = 1;
    while (f < r) {
        int size = r - f;
        int level[1000];
        for (int i = 0; i < size; i++) {
            struct Node* node = q[f++];
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->data;
            if (node->left) q[r++] = node->left;
            if (node->right) q[r++] = node->right;
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root);
    return 0;
}