#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // First pass: create optimal counter moves
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Second pass: fix consecutive same moves
    int sum = n;
    for(int i = 2; i <= n; i++) {
        if(c[i] == c[i-1]) {
            // Find a different move that still beats s[i]
            char original = s[i];
            if(original == 'P') {
                if(c[i-1] != 'S') c[i] = 'S';
                else c[i] = 'R';  // doesn't win, but breaks sequence
            } else if(original == 'R') {
                if(c[i-1] != 'P') c[i] = 'P';
                else c[i] = 'S';
            } else {
                if(c[i-1] != 'R') c[i] = 'R';
                else c[i] = 'P';
            }
            
            if(c[i] != original) {  // only count if it still wins
                sum--;
            } else {
                sum--;  // lost a win
            }
        }
    }
    
    printf("%d", sum);
    return 0;
}