#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n) {
    // Create the transformed sequence: P->S, R->P, S->R
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int changes = 0;
    // Count consecutive duplicates and resolve by changing current to original
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
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
    
    int ans = solve(n);
    
    // Try an alternative: force first char to stay as original
    if (n >= 2 && s[1] == s[2]) {
        // Reset c array
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
        }
        
        // Keep first char as original
        c[1] = s[1];
        int changes = 1;
        
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