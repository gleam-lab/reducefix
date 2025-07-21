#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Generate initial counter moves
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Adjust for consecutive duplicates
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i-1]) {
            // Try to find a move that is different from both neighbors and still wins
            // We can choose to lose this round by setting c[i] = s[i]
            // Or find another move that is different and possibly wins
            // Here, we prioritize not losing wins, so we look for an alternative that wins
            // If no alternative, we set to lose
            if (i < n && c[i+1] != c[i-1]) {
                char alt;
                if (s[i] == 'P') alt = 'S';
                else if (s[i] == 'R') alt = 'P';
                else alt = 'R';
                if (alt != c[i-1] && alt != c[i+1]) {
                    c[i] = alt;
                } else {
                    c[i] = s[i];
                }
            } else {
                c[i] = s[i];
            }
        }
    }
    
    // Count the number of wins
    int wins = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[i] == 'P' && s[i] == 'R') ++wins;
        else if (c[i] == 'R' && s[i] == 'S') ++wins;
        else if (c[i] == 'S' && s[i] == 'P') ++wins;
    }
    
    printf("%d\n", wins);
    return 0;
}