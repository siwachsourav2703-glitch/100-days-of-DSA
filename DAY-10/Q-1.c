#include <stdio.h>

int main() {
    char s[100];
    int left = 0, right = 0;

    scanf("%s", s);

    // find length
    while (s[right] != '\0') {
        right++;
    }
    right--;  
    while (left < right) {
        if (s[left] != s[right]) {
            printf("NO");
            return 0;
        }
        left++;
        right--;
    }
    printf("YES");
    return 0;
}
