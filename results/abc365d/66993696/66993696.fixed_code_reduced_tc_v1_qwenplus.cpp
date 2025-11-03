#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n) {
    // Build the transformed string c where each character beats s[i]
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int changes = 0;
    // Count how many adjacent equal characters we need to fix
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            // When two adjacent are same, we can change c[i] to s[i] (original)
            // This breaks the run and guarantees c[i] != c[i-1] since s[i] loses to original c[i]
            c[i] = s[i];
            changes++;
        }
    }
    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    if (n == 1) {
        printf("1");
        return 0;
    }
    
    int ans = solve(n);
    
    // Try alternative: force first character to be unchanged (i.e., set c[1] = s[1])
    // Then rebuild from there
    if (s[1] == 'P') c[1] = 'S';
    else if (s[1] == 'R') c[1] = 'P';
    else c[1] = 'R';
    
    // But now try setting c[1] = s[1] instead
    c[1] = s[1]; // This means position 1 will lose, but might allow better continuation
    int changes = 1; // We "lose" one point by not winning at pos 1
    
    for (int i = 2; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
        
        // If current conflicts with previous, change current to original
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            changes++;
        }
    }
    
    ans = max(ans, n - changes);
    
    // One more possibility: what if we don't start with either?
    // Actually, the optimal strategy is to greedily avoid consecutive duplicates.
    // We should consider that sometimes breaking early allows longer runs later.
    // However, a simpler idea: try both possibilities for the first character:
    // Option 1: c[1] = best move against s[1] (win)
    // Option 2: c[1] = s[1] (tie/loss)
    
    // But our two cases above already cover:
    // Case 1: fully greedy win (solve() function)
    // Case 2: force c[1] = s[1], then greedy from 2 onward
    
    // However, the issue in the original code was incomplete handling.
    // Let's refactor: try both initial choices and simulate independently.
    
    // Reset and try option 1: start with winning move
    int count1 = 0;
    char d[200011];
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') d[i] = 'S';
        else if (s[i] == 'R') d[i] = 'P';
        else d[i] = 'R';
    }
    for (int i = 2; i <= n; i++) {
        if (d[i] == d[i-1]) {
            d[i] = s[i]; // change to original to break sequence
            count1++;
        }
    }
    ans = max(ans, n - count1);
    
    // Option 2: start with s[1] at position 1
    if (s[1] == 'P') d[1] = 'S';
    else if (s[1] == 'R') d[1] = 'P';
    else d[1] = 'R';
    d[1] = s[1]; // choose to not win at first position
    count1 = 1; // already lost one win
    for (int i = 2; i <= n; i++) {
        if (s[i] == 'P') d[i] = 'S';
        else if (s[i] == 'R') d[i] = 'P';
        else d[i] = 'R';
        if (d[i] == d[i-1]) {
            d[i] = s[i];
            count1++;
        }
    }
    ans = max(ans, n - count1);
    
    // Option 3: maybe start with third possibility? No, only three moves.
    // But note: the move at each position can be any of R/P/S, but only one wins.
    // However, we are allowed to choose any move. The key is to avoid consecutive equal.
    
    // Alternate approach: dynamic programming or greedy with state.
    // Since constraints are 2e5, we need O(N) or O(N log N).
    // Insight: we want to maximize number of positions where c[i] beats s[i],
    // subject to no two adjacent c[i] are equal.
    
    // We can do DP: dp[i][move] = maximum wins up to i, ending with move in {'R','P','S'}
    // But mapping chars to indices: R=0, P=1, S=2
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    auto getMove = [](char ch) -> int {
        if (ch == 'R') return 0;
        if (ch == 'P') return 1;
        return 2;
    };
    
    // Initialize first position
    for (int m = 0; m < 3; m++) {
        char move = "RPS"[m];
        // Can we choose this move at pos 1?
        dp[1][m] = (move == s[1]) ? 0 : 
                   ((move == 'R' && s[1] == 'S') ||
                    (move == 'P' && s[1] == 'R') ||
                    (move == 'S' && s[1] == 'P')) ? 1 : 0;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int m = 0; m < 3; m++) {
            char move = "RPS"[m];
            int win = 0;
            if (move == s[i]) win = 0;
            else if ((move == 'R' && s[i] == 'S') ||
                     (move == 'P' && s[i] == 'R') ||
                     (move == 'S' && s[i] == 'P')) win = 1;
            else win = 0;
            
            dp[i][m] = 0;
            for (int pm = 0; pm < 3; pm++) {
                if (pm == m) continue; // adjacent cannot be same
                dp[i][m] = max(dp[i][m], dp[i-1][pm] + win);
            }
        }
    }
    
    int best = *max_element(dp[n].begin(), dp[n].end());
    ans = max(ans, best);
    
    printf("%d", ans);
    return 0;
}