#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[200011];
    char c[200011];
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1); // Use +1 to skip the first character which is unused

    // Convert input to '0', '1', '2' representation
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = '0';
        else if (s[i] == 'R') c[i] = '2';
        else c[i] = '1';
    }

    int ans = 0;
    int sum = n;

    // First pass to simplify the pattern
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            c[i] = '0'; // Set to any non-zero value to indicate change
            sum--;
        }
    }

    // Second pass to finalize the pattern and calculate the remaining sum
    int prev = '0'; // Start with dummy initial value
    for (int i = 1; i <= n; i++) {
        if (c[i] != prev) {
            prev = c[i];
            sum--;
        }
    }

    ans = max(ans, sum);

    // Reset c to original values to check if further simplification is possible
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = '0';
        else if (s[i] == 'R') c[i] = '2';
        else c[i] = '1';
    }

    // Reset sum
    sum = n;

    // Check if simplifying the first two characters leads to better solution
    if (s[1] != s[2]) {
        c[1] = '0';
        c[2] = '0';
        sum -= 2;
        prev = '0'; // Reset prev
        for (int i = 3; i <= n; i++) {
            if (c[i] != prev) {
                prev = c[i];
                sum--;
            }
        }
        ans = max(ans, sum);
    }

    printf("%d", ans);
    return 0;
}