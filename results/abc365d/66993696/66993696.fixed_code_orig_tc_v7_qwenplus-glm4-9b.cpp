#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[200011], c[200011];
    int n, i, ans = 0, max_same = 1, sum_same = 1;

    scanf("%d", &n);
    scanf("%s", s + 1);

    // Apply transformation rule
    for (i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Count the number of consecutive characters that remain the same
    for (i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            sum_same++;
        } else {
            ans = max(ans, sum_same);
            sum_same = 1;
        }
    }
    ans = max(ans, sum_same); // Check the last sequence

    // Output the result
    printf("%d", ans);

    return 0;
}