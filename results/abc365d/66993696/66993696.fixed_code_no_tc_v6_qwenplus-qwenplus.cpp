#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

char s[MAXN];
char c[MAXN];

int solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Apply the transformation: P->S, R->P, S->R
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int ans = 0;
    int changes = 0;

    // Case 1: greedy from left to right
    char left[MAXN];
    memcpy(left, c, sizeof(c));
    int cnt = n;
    for(int i = 2; i <= n; ++i) {
        if(left[i] == left[i-1]) {
            left[i] = s[i];
            cnt--;
        }
    }
    ans = max(ans, cnt);

    // Case 2: greedy from right to left
    char right[MAXN];
    memcpy(right, c, sizeof(c));
    cnt = n;
    for(int i = n - 1; i >= 1; --i) {
        if(right[i] == right[i+1]) {
            right[i] = s[i];
            cnt--;
        }
    }
    ans = max(ans, cnt);

    // Case 3: dynamic programming approach (to handle all possibilities correctly)
    // dp[i][0]: max count till position i, last character is original
    // dp[i][1]: max count till position i, last character is transformed
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    
    dp[1][0] = 1; // use original at pos 1
    dp[1][1] = 1; // use transformed at pos 1

    for(int i = 2; i <= n; ++i++) {
        // current original: s[i], transformed: c[i]
        
        // If we use original at i
        dp[i][0] = 1 + max(
            dp[i-1][0] * (s[i] != s[i-1]), 
            dp[i-1][1] * (s[i] != c[i-1])
        );
        
        // If we use transformed at i
        dp[i][1] = 1 + max(
            dp[i-1][0] * (c[i] != s[i-1]),
            dp[i-1][1] * (c[i] != c[i-1])
        );
    }

    ans = max(ans, max(dp[n][0], dp[n][1]));

    return ans;
}

int main() {
    printf("%d\n", solve());
    return 0;
}