#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    // Initial strategy: always choose the winning move
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // First pass: count without considering consecutive same moves
    int ans = n;
    
    // Second strategy: adjust for consecutive moves
    for(int i = 2; i <= n; i++) {
        if(c[i] == c[i-1]) {
            // Choose to either copy previous opponent's move or current opponent's move
            // to break the sequence, whichever gives more wins
            char opt1 = s[i];  // copy current opponent's move
            char opt2 = s[i-1]; // copy previous opponent's move
            
            int wins1 = (opt1 == 'P' && s[i] == 'R') || 
                       (opt1 == 'R' && s[i] == 'S') || 
                       (opt1 == 'S' && s[i] == 'P');
            
            int wins2 = (opt2 == 'P' && s[i] == 'R') || 
                       (opt2 == 'R' && s[i] == 'S') || 
                       (opt2 == 'S' && s[i] == 'P');
            
            if(wins1 >= wins2) {
                c[i] = opt1;
                ans -= (wins1 == 0);
            } else {
                c[i] = opt2;
                ans -= (wins2 == 0);
            }
        }
    }
    
    printf("%d", ans);
    return 0;
}