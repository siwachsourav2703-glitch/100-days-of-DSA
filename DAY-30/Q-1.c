#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createPolynomial(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int c, e;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->exp = e;
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
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->exp > 1)
            printf("%dx^%d", temp->coeff, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%d", temp->coeff);
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    struct Node* poly = createPolynomial(n);
    printPolynomial(poly);
    return 0;
}