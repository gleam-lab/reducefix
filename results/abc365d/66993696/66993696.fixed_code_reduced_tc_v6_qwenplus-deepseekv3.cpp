#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // First, generate the optimal moves without considering consecutive duplicates
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int sum = n;
    // Now, adjust for consecutive duplicates
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            // We need to change c[i], but to what? Let's try to find an alternative that doesn't match c[i-1] or c[i+1]
            // The best alternative is to choose s[i], which means we lose this round
            c[i] = s[i];
            sum--;
        }
    }

    int ans = sum;

    // Check if changing the first element could yield a better result
    char original_first = c[1];
    if (n >= 2 && c[1] == c[2]) {
        // Try changing c[1] to something else that doesn't match c[2]
        // The best alternative is s[1], which means we lose the first round
        c[1] = s[1];
        int new_sum = n - 1;
        for (int i = 2; i <= n; ++i) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i];
                new_sum--;
            }
        }
        ans = max(ans, new_sum);
    }

    printf("%d\n", ans);
    return 0;
}