#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n, int start) {
    // Create the transformed sequence starting with 'start' modification
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int changes = 0;
    // Start from the given index and resolve consecutive duplicates
    for (int i = start; i <= n; i++) {
        if (i > 1 && c[i] == c[i-1]) {
            c[i] = s[i];  // Revert to original character
            changes++;
        }
    }
    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    int ans = 0;
    
    // Try two strategies:
    // 1. Process from left to right normally
    ans = max(ans, solve(n, 2));
    
    // 2. Force keep first character and process rest
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Keep first character as original
    if (n >= 1) {
        c[1] = s[1];
        int changes = 1; // One change already made
        
        for (int i = 2; i <= n; i++) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];
                changes++;
            }
        }
        ans = max(ans, n - changes);
    }
    
    printf("%d\n", ans);
    return 0;
}