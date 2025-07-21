#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize c to the moves that beat s
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int sum = n;
    // First pass: handle consecutive same moves from left to right
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            // Change c[i] to something that doesn't match c[i-1] and still tries to win or tie
            // We can try to set c[i] to s[i], which might not win, but avoids consecutive same moves
            c[i] = s[i];
            sum--;
        }
    }

    int ans = sum;
    sum = n;
    // Reset c
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Second pass: handle consecutive same moves from right to left
    for (int i = n - 1; i >= 1; --i) {
        if (c[i] == c[i + 1]) {
            c[i] = s[i];
            sum--;
        }
    }

    ans = max(ans, sum);
    printf("%d\n", ans);

    return 0;
}