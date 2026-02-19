#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int flag = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            break;
    }
    if(flag)
        printf("Symmetric Matrix");
    else
        printf("Not Symmetric");
    return 0;
}
