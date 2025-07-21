#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200011;
char s[MAXN], c[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // First pass: Convert all characters to their corresponding choices
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int ans = 0;
    int sum = n;

    // Try to maximize the number of different consecutive pairs
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i]; // Revert to original choice if same as previous
            sum--;
        }
    }
    ans = max(ans, sum);

    // Reset choices for second attempt
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Special case: Check first two characters
    if (s[1] == s[2]) {
        c[1] = s[1];
        sum--;
        for (int i = 3; i <= n; ++i) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i];
                sum--;
            }
        }
    }
    ans = max(ans, sum);

    printf("%d\n", ans);
    return 0;
}