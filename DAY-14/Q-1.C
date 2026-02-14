#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int isIdentity = 1;   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j && arr[i][j] != 1)
                isIdentity = 0;
            if(i != j && arr[i][j] != 0)
                isIdentity = 0;
        }
    }
    if(isIdentity == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");
    return 0;
}
