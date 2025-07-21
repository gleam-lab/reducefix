#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize counter moves
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int sum = n;
    // Check from left to right
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            // Change current move to original to break the tie
            c[i] = s[i];
            sum--;
        }
    }
    int ans = sum;

    // Reset counter moves
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    sum = n;
    // Check from right to left
    for (int i = n - 1; i >= 1; i--) {
        if (c[i] == c[i + 1]) {
            // Change current move to original to break the tie
            c[i] = s[i];
            sum--;
        }
    }
    ans = max(ans, sum);

    printf("%d\n", ans);
    return 0;
}