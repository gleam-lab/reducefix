#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200011;
char s[MAXN], c[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize the counter for valid moves
    int ans = 0;

    // First pass: Try to make all adjacent pairs different
    for (int i = 1; i <= n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            c[i] = s[i] == 'P' ? 'S' : (s[i] == 'R' ? 'P' : 'R');
            c[i + 1] = c[i];
            ans++;
        } else {
            c[i] = s[i];
            c[i + 1] = s[i + 1];
        }
    }

    // Check if the first and last elements can be made different
    if (s[1] != s[n]) {
        c[1] = s[1];
        c[n] = s[n];
    } else {
        c[1] = s[1] == 'P' ? 'S' : (s[1] == 'R' ? 'P' : 'R');
        c[n] = c[1];
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}