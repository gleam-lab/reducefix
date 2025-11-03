#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n, int start_change) {
    // Create the transformed string based on rules
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R'; // S -> R
    }
    
    int changes = 0;
    
    // If we are changing the first character, do it
    if (start_change == 1) {
        c[1] = s[1];
        changes++;
    }
    
    // Process from left to right, fixing adjacent duplicates
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // Change current to original
            changes++;
        }
    }
    
    return n - changes; // Return number of characters that remain as transformed
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Try both possibilities: don't change first char, or change first char
    int ans = max(solve(n, 0), solve(n, 1));
    
    printf("%d\n", ans);
    return 0;
}