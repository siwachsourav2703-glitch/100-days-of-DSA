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
struct Node* queue[1000];
int front = 0, rear = 0;
void enqueue(struct Node* node) {
    queue[rear++] = node;
}
struct Node* dequeue() {
    return queue[front++];
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node* root = newNode(arr[0]);
    enqueue(root);
    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue();
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;
        if (i >= n) break;
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    return root;
}
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    printf("%d\n", height(root));
    return 0;
}