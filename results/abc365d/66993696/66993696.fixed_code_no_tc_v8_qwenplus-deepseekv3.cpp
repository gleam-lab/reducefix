#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    // Initialize counter moves
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int max_wins = 0;
    // Try two different approaches to maximize wins
    for(int approach = 0; approach < 2; approach++) {
        int wins = 0;
        char prev = '\0';
        
        for(int i = 1; i <= n; i++) {
            // For even positions in first approach, odd in second
            if((approach == 0 && i % 2 == 1) || (approach == 1 && i % 2 == 0)) {
                if(c[i] != prev) {
                    wins++;
                    prev = c[i];
                } else {
                    // Can't use this move, use original instead
                    prev = s[i];
                }
            } else {
                // Use original move
                prev = s[i];
            }
        }
        max_wins = max(max_wins, wins);
    }
    
    printf("%d", max_wins);
    return 0;
}