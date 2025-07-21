#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200011;
char s[MAXN], c[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize the result array with the initial move sequence
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int ans = 0, sum = n;

    // Try to minimize the number of adjacent same moves
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i];
            --sum;
        }
    }
    ans = max(ans, sum);

    // Reset the result array to the initial move sequence
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Special case: handle the first two moves separately
    if (s[1] == s[2]) {
        c[1] = s[1];
        --sum;
        for (int i = 3; i <= n; ++i) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i];
                --sum;
            }
        }
    }
    ans = max(ans, sum);

    printf("%d\n", ans);
    return 0;
}