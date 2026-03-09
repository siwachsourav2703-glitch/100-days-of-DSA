#include <stdio.h>
#define MAX 100
int pq[MAX];
int size = 0;
void insert(int x) {
    if (size == MAX) return;
    pq[size++] = x;
}
int findMinIndex() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
void deletePQ() {
    int minIndex = findMinIndex();
    if (minIndex == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pq[minIndex]);
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}
void peek() {
    int minIndex = findMinIndex();
    if (minIndex == -1) {
        printf("-1\n");
        return;
    }
    printf("%d\n", pq[minIndex]);
}
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {
            deletePQ();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }
    return 0;
}