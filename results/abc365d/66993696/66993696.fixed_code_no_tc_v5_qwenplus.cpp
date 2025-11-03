#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Function to calculate score for a given starting choice
    auto calculate = [&](char first) {
        c[1] = first;
        int sum = (c[1] != s[1]) ? 1 : 0; // Count if our move beats the opponent's
        
        for (int i = 2; i <= n; i++) {
            // Choose move that beats opponent
            char preferred;
            if (s[i] == 'P') preferred = 'S';
            else if (s[i] == 'R') preferred = 'P';
            else preferred = 'R';
            
            // If same as previous, we must use opponent's move (can't have consecutive same)
            if (preferred == c[i-1]) {
                c[i] = s[i]; // Use opponent's move as fallback
            } else {
                c[i] = preferred;
            }
            
            // Count if our move beats opponent's
            if (c[i] != s[i]) sum++;
        }
        return sum;
    };
    
    int ans = 0;
    // Try all possible first moves
    ans = max(ans, calculate('R'));
    ans = max(ans, calculate('P'));
    ans = max(ans, calculate('S'));
    
    printf("%d\n", ans);
    return 0;
}