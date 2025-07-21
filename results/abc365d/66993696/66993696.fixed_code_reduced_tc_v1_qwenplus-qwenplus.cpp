#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN];
char c[MAXN];

int solve(int n) {
    // Apply the transformation: P->S, R->P, S->R
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int changes = 0;
    for (int i = 1; i < n; ++i) {
        if (c[i] == c[i-1]) {
            // This character can be changed back to original to break the tie
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

    // Try starting with normal transformation
    int ans1 = solve(n);

    // Try forcing first character to stay the same
    if (n >= 2) {
        // Copy original string to manipulate
        char temp[MAXN];
        strcpy(temp, s);

        // First two characters are the same, change second one
        if (temp[0] == temp[1]) {
            temp[1] = s[1];  // Change second character to original
        }

        // Apply transformation
        for (int i = 0; i < n; ++i) {
            if (temp[i] == 'P') c[i] = 'S';
            else if (temp[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
        }

        int changes = 0;
        for (int i = 1; i < n; ++i) {
            if (c[i] == c[i-1]) {
                c[i] = temp[i];
                changes++;
            }
        }

        ans1 = max(ans1, n - changes);
    }

    printf("%d\n", ans1);
    return 0;
}