#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s+1);
    
    char c[n+1];
    int wins = 0;
    
    // First pass: choose optimal moves to maximize wins
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
        wins += (c[i] != s[i]);
    }
    
    // Second pass: adjust for consecutive same moves to avoid breaking rules
    for(int i = 2; i <= n; i++) {
        if(c[i] == c[i-1]) {
            // Find a different move that still beats s[i] if possible
            char original = c[i];
            if(s[i] == 'P') c[i] = 'S';
            else if(s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
            
            // If the new move is the same as previous, try another option
            if(c[i] == c[i-1]) {
                if(s[i] == 'P') c[i] = 'R';
                else if(s[i] == 'R') c[i] = 'S';
                else c[i] = 'P';
            }
            
            // Recalculate wins
            wins = 0;
            for(int j = 1; j <= n; j++) {
                if(c[j] != s[j]) wins++;
            }
        }
    }
    
    printf("%d", wins);
    return 0;
}