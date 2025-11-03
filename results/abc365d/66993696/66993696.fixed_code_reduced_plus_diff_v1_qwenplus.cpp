#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Helper function to get the winning move
    auto win = [](char ch) {
        if (ch == 'P') return 'S';
        if (ch == 'R') return 'P';
        if (ch == 'S') return 'R';
        return ch;
    };
    
    // Try both possibilities: either start with transformed or original at position 1
    int ans = 0;
    
    // Case 1: Start with transformation on first element
    for (int i = 1; i <= n; i++) {
        c[i] = win(s[i]);
    }
    int sum = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // Use original instead
            sum--;
        }
    }
    ans = max(ans, sum);
    
    // Case 2: Keep first character as original
    if (n >= 2 && s[1] == s[2]) {
        for (int i = 1; i <= n; i++) {
            c[i] = win(s[i]);
        }
        c[1] = s[1];
        sum = n - 1;
        for (int i = 2; i <= n; i++) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];
                sum--;
            }
        }
        ans = max(ans, sum);
    }
    
    // Case 3: Try keeping second character as original if it helps avoid conflict
    for (int i = 1; i <= n; i++) {
        c[i] = win(s[i]);
    }
    if (n >= 2 && c[1] == c[2]) {
        c[2] = s[2];
        sum = n - 1;
        for (int i = 3; i <= n; i++) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];
                sum--;
            }
        }
        ans = max(ans, sum);
    }
    
    printf("%d\n", ans);
    return 0;
}