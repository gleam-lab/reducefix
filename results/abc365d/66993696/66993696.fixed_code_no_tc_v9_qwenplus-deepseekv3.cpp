#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    // Initial optimal response without considering consecutive duplicates
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int max_wins = 0;
    int current_wins = 0;
    
    // Count initial wins
    for(int i = 1; i <= n; i++) {
        if((c[i] == 'R' && s[i] == 'S') || 
           (c[i] == 'S' && s[i] == 'P') || 
           (c[i] == 'P' && s[i] == 'R')) {
            current_wins++;
        }
    }
    max_wins = current_wins;
    
    // Try modifying when consecutive moves are the same
    for(int i = 2; i <= n; i++) {
        if(s[i] == s[i-1]) {
            // Try changing the previous move
            char original = c[i-1];
            if(s[i-1] == 'P') c[i-1] = 'S';
            else if(s[i-1] == 'R') c[i-1] = 'P';
            else c[i-1] = 'R';
            
            int temp_wins = 0;
            for(int j = 1; j <= n; j++) {
                if((c[j] == 'R' && s[j] == 'S') || 
                   (c[j] == 'S' && s[j] == 'P') || 
                   (c[j] == 'P' && s[j] == 'R')) {
                    temp_wins++;
                }
            }
            max_wins = max(max_wins, temp_wins);
            
            // Restore original move
            c[i-1] = original;
            
            // Try changing the current move
            if(s[i] == 'P') c[i] = 'S';
            else if(s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
            
            temp_wins = 0;
            for(int j = 1; j <= n; j++) {
                if((c[j] == 'R' && s[j] == 'S') || 
                   (c[j] == 'S' && s[j] == 'P') || 
                   (c[j] == 'P' && s[j] == 'R')) {
                    temp_wins++;
                }
            }
            max_wins = max(max_wins, temp_wins);
        }
    }
    
    printf("%d", max_wins);
    return 0;
}