#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Try all three possible starting choices for the first character
    int ans = 0;
    
    // We'll try fixing the transformation rule consistently
    // For each position, transformed char should beat original char
    // P->S, R->P, S->R
    
    // But we can choose to not transform some positions (i.e., keep original)
    // Goal: maximize number of positions where transformed[i] != transformed[i-1]
    
    // Actually, re-read: we must transform each character according to the rule
    // unless we explicitly decide to "patch" it (keep original)
    // We want to minimize patches while ensuring no two adjacent transformed chars are same
    
    // Correct approach: try different strategies
    
    auto getTransform = [](char ch) {
        if (ch == 'P') return 'S';
        if (ch == 'R') return 'P';
        return 'R'; // S -> R
    };
    
    // Try all possible initial states and greedy propagation
    for (int start_choice = 0; start_choice < 3; start_choice++) {
        char last = 0;
        int patches = 0;
        int current_sum = 0;
        
        for (int i = 1; i <= n; i++) {
            char orig = s[i];
            char trans = getTransform(orig);
            
            // Determine what we'll actually use at position i
            char use;
            if (i == 1) {
                if (start_choice == 0) {
                    use = trans; // use transformed
                } else if (start_choice == 1) {
                    use = orig; // patch - use original
                    patches++;
                }
                // Note: third option is redundant since only two choices per position
            } else {
                // Check if we can use transformed without conflict
                if (trans != last) {
                    use = trans;
                } else {
                    // Would conflict, so must patch
                    use = orig;
                    patches++;
                }
            }
            
            // If using original, check if it also conflicts
            if (use == orig && use == last && i > 1) {
                // Even after patching, we have conflict
                // This strategy fails
                current_sum = 0;
                break;
            }
            
            last = use;
            current_sum++;
        }
        
        ans = max(ans, current_sum);
    }
    
    // Alternative approach: dynamic programming
    // State: dp[i][ch] = maximum length ending at position i with character ch
    const string choices = "RPS";
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    // Initialize first position
    for (int j = 0; j < 3; j++) {
        char choice = choices[j];
        char orig = s[1];
        char trans = getTransform(orig);
        
        if (choice == trans || choice == orig) {
            // We can achieve this character either by transforming or patching
            dp[1][j] = 1;
        }
        // Otherwise impossible
    }
    
    for (int i = 2; i <= n; i++) {
        char orig = s[i];
        char trans = getTransform(orig);
        
        for (int j = 0; j < 3; j++) {
            char curr_choice = choices[j];
            // Can we achieve curr_choice at position i?
            if (curr_choice != trans && curr_choice != orig) {
                continue; // Impossible
            }
            
            for (int k = 0; k < 3; k++) {
                if (choices[k] == curr_choice) continue; // Adjacent same not allowed
                
                dp[i][j] = max(dp[i][j], dp[i-1][k] + 1);
            }
        }
    }
    
    int best = 0;
    for (int j = 0; j < 3; j++) {
        best = max(best, dp[n][j]);
    }
    
    printf("%d\n", best);
    
    return 0;
}