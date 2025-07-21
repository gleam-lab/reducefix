#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN], c[MAXN];

int solve(int n) {
    // Apply the transformation: P->S, R->P, S->R
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int changes = 0;
    for (int i = 1; i < n; ++i) {
        if (c[i] == c[i - 1]) {
            // Conflict, change this character back to original
            c[i] = s[i];
            changes++;
        }
    }

    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    // Try all three possible starting transformations
    int max_result = 0;

    // We'll store the best result among different initial mappings
    char backup[MAXN];

    // First mapping: P->S, R->P, S->R
    max_result = max(max_result, solve(n));

    // Second mapping: shift mapping -> P->R, R->S, S->P
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') backup[i] = 'R';
        else if (s[i] == 'R') backup[i] = 'S';
        else backup[i] = 'P';
    }
    memcpy(c, backup, n);
    max_result = max(max_result, solve(n));

    // Third mapping: shift again -> P->P, R->R, S->S (no transformation)
    // In this case we just use original string, so every character matches itself
    // So the maximum number of wins is 0
    max_result = max(max_result, 0);

    printf("%d\n", max_result);
}