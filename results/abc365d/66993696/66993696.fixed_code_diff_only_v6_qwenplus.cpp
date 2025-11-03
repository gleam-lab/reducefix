#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n) {
    // Create the transformed string: P->S, R->P, S->R
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R'; // S -> R
    }
    
    int changes = 0;
    // Count consecutive identical characters and fix them greedily
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i]; // Revert to original character to break the sequence
            changes++;
        }
    }
    
    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    int ans = solve(n);
    
    // Try special case: change first character to original
    if (n >= 2 && s[1] == s[2]) {
        // Recreate transformation
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
        }
        
        // Force c[1] to be s[1] (no transformation on first char)
        c[1] = s[1];
        int changes = 1; // One change already made
        
        // Fix consecutive duplicates from position 2 onwards
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