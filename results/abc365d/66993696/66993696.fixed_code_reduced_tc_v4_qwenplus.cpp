#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Build the transformed string
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int changes = 0;
    // Count adjacent duplicates and resolve greedily
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // revert to original
            changes++;
        }
    }
    
    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    // Try two strategies:
    // 1. Normal transformation
    // 2. Force first character to stay as original
    
    int ans = solve(n);
    
    // Strategy 2: Keep first char unchanged
    if (n > 1) {
        // Reset c array
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
        }
        
        c[1] = s[1];  // force first to original
        int changes = 1;  // we changed first one
        
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