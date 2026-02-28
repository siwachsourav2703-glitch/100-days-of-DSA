#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
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
    temp->next = head;
    return head;
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL)
        return;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = createCircularList(n);
    traverse(head);
    return 0;
}