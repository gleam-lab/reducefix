#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

// Function to compute the maximum number of distinct adjacent elements after transformation
int solve(int n, char s[]) {
    if (n == 1) return 1;
    
    // Define transformation: P->S, R->P, S->R
    auto transform = [](char ch) {
        if (ch == 'P') return 'S';
        if (ch == 'R') return 'P';
        return 'R';
    };
    
    int max_result = 0;
    
    // Try two strategies:
    // 1. Start from left, greedily fix adjacent duplicates
    // 2. Fix first pair if needed and then proceed
    
    // Strategy 1: Greedy from left
    for (int i = 1; i <= n; i++) {
        c[i] = transform(s[i]);
    }
    
    int count1 = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // Revert to original
            count1--;
        }
    }
    max_result = max(max_result, count1);
    
    // Strategy 2: If first two transformed characters are same, try keeping first original
    for (int i = 1; i <= n; i++) {
        c[i] = transform(s[i]);
    }
    
    int count2 = n;
    if (c[1] == c[2]) {
        c[1] = s[1];
        count2--;
        for (int i = 3; i <= n; i++) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];
                count2--;
            }
        }
        max_result = max(max_result, count2);
    }
    
    // Strategy 3: Try keeping second character as original if first two would conflict
    for (int i = 1; i <= n; i++) {
        c[i] = transform(s[i]);
    }
    
    int count3 = n;
    if (c[1] == c[2]) {
        c[2] = s[2];
        count3--;
        for (int i = 3; i <= n; i++) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];
                count3--;
            }
        }
        max_result = max(max_result, count3);
    }
    
    // Strategy 4: Try dynamic programming / optimal merging
    // We'll use a greedy approach that looks ahead
    vector<int> dp(n+1, 0);
    vector<char> best(n+1);
    
    // Base case
    dp[1] = 1;
    best[1] = transform(s[1]);
    
    for (int i = 2; i <= n; i++) {
        char trans = transform(s[i]);
        char curr_choice = trans;
        
        // Check if we can keep transformed version
        if (trans != best[i-1]) {
            dp[i] = dp[i-1] + 1;
            best[i] = trans;
        } else {
            // Must use original
            dp[i] = dp[i-1];
            best[i] = s[i];
        }
    }
    max_result = max(max_result, dp[n]);
    
    return max_result;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    printf("%d", solve(n, s));
    return 0;
}