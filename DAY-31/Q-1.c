#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}
void display() {
    if (top == -1) {
        return;   
    }   
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}
int main() {
    int n, choice, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &value);
            push(value);
        } 
        else if (choice == 2) {
            pop();
        } 
        else if (choice == 3) {
            display();
        }
    }   
    return 0;
}