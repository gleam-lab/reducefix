#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n, int start) {
    // Create transformed string
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int changes = 0;
    
    // Handle circular condition by starting at different position
    if (start == 2) {
        // Try changing first element to original
        c[1] = s[1];
        changes++;
    }
    
    // Process the sequence to avoid adjacent duplicates
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            changes++;
        }
    }
    
    // Check circular condition: last and first element
    if (c[n] == c[1] && n > 1) {
        // We need to change either first or last
        // If we haven't changed first yet, we can change it
        if (start != 2) {
            c[1] = s[1];
            changes++;
        } else {
            // If we already changed first, change last instead
            c[n] = s[n];
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
    
    // Try two strategies:
    // 1. Normal transformation
    // 2. Change first element to original
    
    // Strategy 1: Normal transformation
    int changes = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            changes++;
        }
    }
    
    // Check circular condition
    if (c[n] == c[1]) {
        changes++;
    }
    
    ans = max(ans, n - changes);
    
    // Strategy 2: Start by keeping first character same as original
    changes = 1; // We're changing first character
    c[1] = s[1];
    
    for (int i = 2; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            changes++;
        }
    }
    
    // Check circular condition - with first already changed
    if (c[n] == c[1]) {
        c[n] = s[n];
        changes++;
    }
    
    ans = max(ans, n - changes);
    
    printf("%d", ans);
    return 0;
}