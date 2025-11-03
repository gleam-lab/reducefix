#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Build transformation: beat the original move
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int best = 0;
    
    // Try all possible starting positions where we might break the chain
    // We'll try to minimize conflicts (adjacent same characters)
    
    // Case 1: Don't change anything - just use transformed string and fix conflicts greedily
    int sum = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            sum--;
        }
    }
    best = max(best, sum);
    
    // We need a better strategy: dynamic programming or greedy with multiple options
    
    // Alternate approach: try to simulate optimal assignment
    // Actually, let's rethink: we can choose any character at each position,
    // but if we choose s[i], then we don't get credit, otherwise we do.
    // Constraint: no two adjacent equal characters.
    
    // DP state: dp[i][ch] = maximum score up to position i, ending with character ch
    const int INF = 1e9;
    vector<map<char, int>> dp(n+1);
    vector<char> chars = {'R', 'P', 'S'};
    
    // Initialize first position
    for (char ch : chars) {
        dp[1][ch] = (ch == s[1] ? 0 : 1);
    }
    
    // Fill DP table
    for (int i = 2; i <= n; i++) {
        for (char curr : chars) {
            int add = (curr == s[i] ? 0 : 1);
            dp[i][curr] = -INF;
            for (char prev : chars) {
                if (curr != prev && dp[i-1].count(prev)) {
                    dp[i][curr] = max(dp[i][curr], dp[i-1][prev] + add);
                }
            }
        }
    }
    
    // Find maximum in last row
    for (auto &p : dp[n]) {
        best = max(best, p.second);
    }
    
    return best;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    printf("%d\n", solve(n));
    return 0;
}