#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // First pass: transform each character to the one that beats it
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Second pass: left to right to handle consecutive duplicates
    for(int i = 2; i <= n; ++i) {
        if(c[i] == c[i-1]) {
            // Need to change c[i] to something else that doesn't match c[i-1] and possibly loses to s[i]
            // Choose a character that doesn't win against s[i] to minimize loss
            if(s[i] == 'P') {
                if(c[i-1] != 'R') c[i] = 'R';
                else c[i] = 'P';
            } else if(s[i] == 'R') {
                if(c[i-1] != 'S') c[i] = 'S';
                else c[i] = 'R';
            } else {
                if(c[i-1] != 'P') c[i] = 'P';
                else c[i] = 'S';
            }
        }
    }
    
    // Third pass: right to left to handle any remaining consecutive duplicates
    for(int i = n-1; i >= 1; --i) {
        if(c[i] == c[i+1]) {
            if(s[i] == 'P') {
                if(c[i+1] != 'R') c[i] = 'R';
                else c[i] = 'P';
            } else if(s[i] == 'R') {
                if(c[i+1] != 'S') c[i] = 'S';
                else c[i] = 'R';
            } else {
                if(c[i+1] != 'P') c[i] = 'P';
                else c[i] = 'S';
            }
        }
    }
    
    // Count the number of wins
    int wins = 0;
    for(int i = 1; i <= n; ++i) {
        if((c[i] == 'S' && s[i] == 'P') ||
           (c[i] == 'P' && s[i] == 'R') ||
           (c[i] == 'R' && s[i] == 'S')) {
            wins++;
        }
    }
    
    printf("%d\n", wins);
    return 0;
}