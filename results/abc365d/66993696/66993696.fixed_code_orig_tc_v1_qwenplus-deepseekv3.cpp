#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];
int dp[200011][3]; // 0: R, 1: P, 2: S

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Initialize DP
    for (int i = 1; i <= n; ++i) {
        char opponent = s[i];
        // R
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + (opponent == 'S' ? 1 : 0);
        // P
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + (opponent == 'R' ? 1 : 0);
        // S
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + (opponent == 'P' ? 1 : 0);
    }
    
    printf("%d\n", max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}