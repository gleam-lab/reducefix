#include<bits/stdc++.h>
using namespace std;
char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int ans = 0;
    int sum = n;

    // First pass to consolidate similar characters
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i]; // Restore character to maximize diversity
            sum--;
        }
    }
    ans = max(ans, sum);

    // Second pass to handle consecutive identical characters at the start
    if (n > 1 && s[1] == s[2]) {
        c[1] = s[1]; // Restore character to maximize diversity
        sum--;
        for (int i = 3; i <= n; i++) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i]; // Restore character to maximize diversity
                sum--;
            }
        }
    }
    ans = max(ans, sum);

    printf("%d", ans);
    return 0;
}