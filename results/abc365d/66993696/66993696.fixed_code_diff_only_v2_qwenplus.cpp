#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n, int start_char) {
    // Create the transformed string based on rule
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Start from position start_char with original character
    c[start_char] = s[start_char];
    int changes = 1;
    
    // Propagate forward
    for (int i = start_char + 1; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            changes++;
        }
    }
    
    // Propagate backward
    for (int i = start_char - 1; i >= 1; i--) {
        if (c[i] == c[i+1]) {
            c[i] = s[i];
            changes++;
        }
    }
    
    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    if (n == 1) {
        printf("1");
        return 0;
    }
    
    int ans = 0;
    
    // Try changing each position to its original character
    for (int i = 1; i <= n; i++) {
        ans = max(ans, solve(n, i));
    }
    
    printf("%d", ans);
    return 0;
}