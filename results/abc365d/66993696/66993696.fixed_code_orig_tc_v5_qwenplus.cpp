#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Define what each move beats
    auto beats = [](char a, char b) {
        if (a == 'R') return b == 'S';
        if (a == 'P') return b == 'R';
        if (a == 'S') return b == 'P';
        return false;
    };

    // For each position, choose the move that beats the original
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') c[i] = 'P';
        else if (s[i] == 'P') c[i] = 'S';
        else c[i] = 'R';
    }

    int ans = 0;

    // Try all possible starting points for breaking consecutive duplicates
    // We can change at most one character per contiguous group of same characters
    vector<int> groups;
    int i = 1;
    while (i <= n) {
        int j = i;
        while (j <= n && c[j] == c[i]) j++;
        groups.push_back(j - i); // length of this group
        i = j;
    }

    // Each group contributes min(len, len+1) = len to survival count
    // But we can optimize by possibly merging changes
    // Actually, in any consecutive segment of same moves, only one person survives
    // So total survivors = number of segments
    int segments = groups.size();
    ans = segments;

    // However, we have a choice: at boundaries, we might be able to do better
    // Alternate approach: simulate optimally
    // We can change some c[i] back to s[i] to break long runs
    // Each time we do that, we split a run and potentially increase survivors

    // Maximum possible is when every adjacent duplicate is broken optimally
    // But we cannot change two adjacent positions both to originals if they would create new duplicates

    // Let's use greedy: traverse and whenever we see duplicate, consider changing one
    // But note: changing c[i] to s[i] means this player plays their original move
    // This may or may not help

    // Insight: The optimal strategy is to maximize the number of segments in the final sequence
    // We start with the "beats" sequence c[1..n]
    // We are allowed to change any subset of positions from c[i] to s[i]
    #define MAXN 200011
    static int dp[MAXN][2]; // dp[i][0] = max segments ending at i without changing i, dp[i][1] = with changing i
    
    // Initialize
    dp[1][0] = 1; // not changed
    dp[1][1] = 1; // changed
    
    for (int i = 2; i <= n; i++) {
        char orig_i = s[i];
        char beat_i = c[i];
        char orig_im1 = s[i-1];
        char beat_im1 = c[i-1];
        
        // Case 1: don't change i
        dp[i][0] = 1;
        // try extend from previous states
        if (beat_i != beat_im1) 
            dp[i][0] = max(dp[i][0], dp[i-1][0] + 1);
        if (beat_i != orig_im1)
            dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
        
        // Case 2: change i to original
        dp[i][1] = 1;
        if (orig_i != beat_im1)
            dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
        if (orig_i != orig_im1)
            dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
    }
    
    ans = max(dp[n][0], dp[n][1]);

    printf("%d\n", ans);
    return 0;
}