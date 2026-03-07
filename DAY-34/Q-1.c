#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node {
    int data;
    struct node* next;
};
struct node* top = NULL;
void push(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}
int evaluatePostfix(char exp[]) {
    int i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();
            int result;
            switch (exp[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            push(result);
        }
        i++;
    }
    return pop();
}
int main() {
    char exp[100];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);
    return 0;
}