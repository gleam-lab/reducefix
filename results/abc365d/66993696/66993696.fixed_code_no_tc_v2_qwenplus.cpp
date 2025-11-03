#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

char counterChar(char ch) {
    if (ch == 'P') return 'S';
    if (ch == 'R') return 'P';
    if (ch == 'S') return 'R';
    return ch;
}

int solve(int n, char* s) {
    // Try all possible starting choices for the first character
    int maxWin = 0;
    
    // We'll try three possibilities for the first character: original counter or keep as is
    for (int startChoice = 0; startChoice < 3; startChoice++) {
        char temp[200011];
        
        // Initialize the transformation
        for (int i = 1; i <= n; i++) {
            temp[i] = counterChar(s[i]);
        }
        
        // Apply the start choice modification
        if (startChoice > 0) {
            // Try keeping the first character as original
            temp[1] = s[1];
        }
        
        // Count wins and resolve consecutive duplicates
        int wins = 0;
        for (int i = 1; i <= n; i++) {
            if (temp[i] != s[i]) wins++;
        }
        
        // Fix consecutive identical moves
        for (int i = 2; i <= n; i++) {
            if (temp[i] == temp[i-1]) {
                // If we have consecutive same moves, we can either:
                // 1. Revert back to counter move if not already
                // 2. Or keep original (but that gives no win)
                if (temp[i] != s[i]) {
                    // Currently was a winning move, but causes duplicate
                    // Change it to original (non-winning) to break the sequence
                    temp[i] = s[i];
                    wins--;
                }
            }
        }
        
        maxWin = max(maxWin, wins);
    }
    
    return maxWin;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    // Special case for n=1
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    
    int ans = 0;
    
    // Try different strategies systematically
    
    // Strategy 1: Always play counter move initially, then fix conflicts
    for (int i = 1; i <= n; i++) {
        c[i] = counterChar(s[i]);
    }
    
    int wins = n; // Initially assume all are wins
    // Fix consecutive duplicates from left to right
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i]; // Play original (non-winning) move to break sequence
            wins--;
        }
    }
    ans = max(ans, wins);
    
    // Strategy 2: Try making first move same as opponent
    for (int i = 1; i <= n; i++) {
        c[i] = counterChar(s[i]);
    }
    c[1] = s[1]; // First move same as opponent (no win)
    wins = n - 1; // One less win initially
    
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            wins--;
        }
    }
    ans = max(ans, wins);
    
    // Strategy 3: Try making second move same as opponent if first two are same
    if (s[1] == s[2]) {
        for (int i = 1; i <= n; i++) {
            c[i] = counterChar(s[i]);
        }
        c[2] = s[2]; // Second move same as opponent
        wins = n - 1;
        
        for (int i = 2; i <= n; i++) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];
                wins--;
            }
        }
        ans = max(ans, wins);
    }
    
    // Strategy 4: Try breaking sequences differently
    for (int i = 1; i <= n; i++) {
        c[i] = counterChar(s[i]);
    }
    wins = n;
    
    // This time, handle duplicates more carefully
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            // Only revert if it's a winning move we're using
            if (c[i] != s[i]) {
                c[i] = s[i];
                wins--;
            }
        }
    }
    ans = max(ans, wins);
    
    printf("%d\n", ans);
    return 0;
}