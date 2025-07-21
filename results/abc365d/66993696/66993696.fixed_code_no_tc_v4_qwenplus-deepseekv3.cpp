#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Initial greedy choice (beating previous move)
    int wins = 0;
    c[1] = (s[1] == 'P') ? 'S' : 
           (s[1] == 'R') ? 'P' : 'R';
    wins++;
    
    for (int i = 2; i <= n; i++) {
        char optimal = (s[i] == 'P') ? 'S' : 
                       (s[i] == 'R') ? 'P' : 'R';
        
        // If optimal choice is same as previous, choose differently to avoid consecutive same choices
        if (optimal == c[i-1]) {
            // Choose any other option that's not the same as previous
            if (s[i] == 'P') {
                c[i] = (c[i-1] != 'R') ? 'R' : 'P';
            } else if (s[i] == 'R') {
                c[i] = (c[i-1] != 'S') ? 'S' : 'P';
            } else { // Scissors
                c[i] = (c[i-1] != 'P') ? 'P' : 'R';
            }
        } else {
            c[i] = optimal;
        }
        
        // Count if we're beating current move
        if ((c[i] == 'P' && s[i] == 'R') ||
            (c[i] == 'R' && s[i] == 'S') ||
            (c[i] == 'S' && s[i] == 'P')) {
            wins++;
        }
    }
    
    printf("%d\n", wins);
    return 0;
}