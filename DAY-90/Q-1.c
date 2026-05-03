#include <stdio.h>
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxTime) {
            painters++;       
            sum = arr[i];     

            if (painters > k)
                return 0;     
        }
    }
    return 1; 
}

int painterPartition(int arr[], int n, int k) {
    int max = 0, total = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        total += arr[i];
    }

    int low = max, high = total, ans = total;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;   
        }
    }

    return ans;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4, k = 2;

    printf("Minimum time: %d\n", painterPartition(arr, n, k));

    return 0;
}