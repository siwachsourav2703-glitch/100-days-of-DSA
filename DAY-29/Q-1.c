#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;
    struct Node* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    k = k % length;
    if (k == 0)
        return head;
    temp->next = head;
    int steps = length - k;
    temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
    struct Node* head = createList(n);
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    return 0;
}