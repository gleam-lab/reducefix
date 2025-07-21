#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN];
char t[MAXN];

int solve(int n) {
    // Apply the transformation: P->S, R->P, S->R
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') t[i] = 'S';
        else if (s[i] == 'R') t[i] = 'P';
        else t[i] = 'R';
    }

    int changes = 0;
    for (int i = 1; i < n; ++i) {
        if (t[i] == t[i - 1]) {
            t[i] = s[i];  // Revert to original character
            changes++;
        }
    }

    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    // Try solving normally
    int ans = solve(n);

    // Try rotating the string (only first character changed)
    char orig_first = s[0];
    for (char new_first : {'P', 'R', 'S'}) {
        if (new_first == orig_first) continue;
        s[0] = new_first;
        ans = max(ans, solve(n));
    }

    printf("%d\n", ans);
    return 0;
}