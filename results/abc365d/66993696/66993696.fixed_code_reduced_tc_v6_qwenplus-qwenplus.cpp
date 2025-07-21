#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN];
char c[MAXN];

int solve(int n) {
    // Apply the transformation: P->S, R->P, S->R
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int sum = n;
    // Remove adjacent duplicates
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // Revert to original character
            sum--;
        }
    }

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);  // Read string starting from index 1

    // Try solution forward
    int ans = solve(n);

    // Try solution backward by reversing and re-solving
    reverse(s + 1, s + n + 1);
    ans = max(ans, solve(n));

    printf("%d\n", ans);
    return 0;
}