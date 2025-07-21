#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200011;

int main() {
    int n;
    scanf("%d", &n);
    char s[MAXN], c[MAXN];
    scanf("%s", s + 1);

    // Transforming the string according to the rules
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Counting the maximum number of non-consecutive characters
    int ans = 0, sum = n;
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i];
            --sum;
        }
    }
    ans = max(ans, sum);

    // Resetting the transformation
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Handling the case where the first two characters are the same
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