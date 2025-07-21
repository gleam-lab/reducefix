#include<bits/stdc++.h>
using namespace std;

const int N = 200011;

char s[N];
char c[N];

int solve(int n) {
    // Apply transformation: P->S, R->P, S->R
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int changes = 0;
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // Revert to original character
            changes++;
        }
    }

    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Try starting with normal transformation
    int ans1 = solve(n);

    // Try special case where first two characters are the same
    if (n >= 2 && s[1] == s[2]) {
        // Start with keeping the first character unchanged
        c[1] = s[1];
        int changes = 1;  // We changed the first character from transformed value

        for (int i = 2; i <= n; ++i) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
            
            if (i > 2 && c[i] == c[i-1]) {
                c[i] = s[i];
                changes++;
            }
        }

        ans1 = max(ans1, n - changes);
    }

    printf("%d\n", ans1);
    return 0;
}