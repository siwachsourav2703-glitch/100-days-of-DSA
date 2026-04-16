#include <stdio.h>
#define SIZE 1000
int maxLenZeroSum(int arr[], int n) {
    int prefixSum = 0, maxLen = 0;
    int hash[2 * SIZE + 1];
    for (int i = 0; i < 2 * SIZE + 1; i++)
        hash[i] = -2;
    hash[SIZE] = -1;
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        int index = prefixSum + SIZE;
        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i;
        }
    }
    return maxLen;
}
int main() {
    int arr[SIZE];
    int n = 0;
    while (scanf("%d", &arr[n]) == 1) {
        n++;
        if (getchar() == '\n') break;
    }
    printf("%d\n", maxLenZeroSum(arr, n));
    return 0;
}