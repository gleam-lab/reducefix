#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200011;
char s[MAXN], c[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize the result with the maximum possible value
    int ans = n;

    // Iterate through all possible starting points
    for (int start = 0; start < 2; ++start) {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
        }

        int sum = n;
        for (int i = 2; i <= n; ++i) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i];
                --sum;
            }
        }

        ans = max(ans, sum);

        // Special case for the first character
        if (s[1] == s[2]) {
            c[1] = s[1];
            --sum;
            for (int i = 3; i <= n; ++i) {
                if (c[i] == c[i - 1]) {
                    c[i] = s[i];
                    --sum;
                }
            }
            ans = max(ans, sum);
        }
    }

    printf("%d\n", ans);
    return 0;
}