#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // First pass: generate the optimal moves
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int sum = n;
    // Check for consecutive same moves and adjust
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            // Try to find a different move that still beats s[i] if possible
            // but for simplicity, replace with s[i] to break the sequence
            c[i] = s[i];
            sum--;
        }
    }
    
    // Check if the first and last are the same and adjust if necessary
    if (n > 1 && c[1] == c[n]) {
        // Try to change either the first or last to a different move that beats s[i]
        // Here, we change the first one to s[1]
        char original = c[1];
        c[1] = s[1];
        sum--;
        
        // Now, check if this change affects the second element
        if (c[1] == c[2]) {
            // Revert the first change and try changing the last instead
            c[1] = original;
            sum++;
            c[n] = s[n];
            sum--;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}