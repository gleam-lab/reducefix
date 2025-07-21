#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN];
char c[MAXN];

int solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    int ans = 0;

    // Try all three possible initial transformations
    for (int init = 0; init < 3; ++init) {
        // Initialize c array
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
        }

        int changes = 0;

        // Apply transformation rules
        for (int i = 1; i <= n; ++i) {
            // If this is the first character, use the initial choice
            if (i == 1 && init != 0) {
                c[i] = s[i];  // No transformation for this strategy
                changes++;
            }

            // Ensure no two consecutive characters are the same
            while (i > 1 && c[i] == c[i-1]) {
                // Try different transformation if possible
                if (s[i] == 'P') {
                    if (c[i] == 'S') c[i] = 'P';  // No change
                    else c[i] = 'S';
                } else if (s[i] == 'R') {
                    if (c[i] == 'P') c[i] = 'R';
                    else c[i] = 'P';
                } else { // 'S'
                    if (c[i] == 'R') c[i] = 'S';
                    else c[i] = 'R';
                }
                changes++;
            }
        }

        ans = max(ans, n - changes);
    }

    return ans;
}

int main() {
    printf("%d\n", solve());
    return 0;
}