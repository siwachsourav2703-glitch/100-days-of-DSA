#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    scanf("%d", &n);  
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  
    }
    qsort(arr, n, sizeof(int), compare);
    int left = 0, right = n - 1;
    int min_sum = arr[left] + arr[right];
    int pair1 = arr[left], pair2 = arr[right];
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            pair1 = arr[left];
            pair2 = arr[right];
        }
        if(sum < 0)
            left++;    
        else
            right--;   
    }
    printf("%d %d\n", pair1, pair2);
    return 0;
}
