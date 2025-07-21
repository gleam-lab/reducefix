#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    // Initialize c to be the optimal response
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Remove consecutive duplicates while maximizing wins
    int wins = 0;
    for(int i = 1; i <= n; i++) {
        if(i > 1 && c[i] == c[i-1]) {
            // Need to change this response to something different from neighbors
            // Choose a response that might still win if possible
            if(s[i] == 'P' && c[i-1] != 'S') c[i] = 'S';
            else if(s[i] == 'R' && c[i-1] != 'P') c[i] = 'P';
            else if(s[i] == 'S' && c[i-1] != 'R') c[i] = 'R';
            else {
                // If we can't win, choose any different response
                if(c[i-1] != 'P') c[i] = 'P';
                else if(c[i-1] != 'R') c[i] = 'R';
                else c[i] = 'S';
            }
        }
        if(c[i] == 'P' && s[i] == 'R') wins++;
        else if(c[i] == 'R' && s[i] == 'S') wins++;
        else if(c[i] == 'S' && s[i] == 'P') wins++;
    }
    
    printf("%d", wins);
    return 0;
}