#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // First pass: choose winning moves
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Count wins and handle consecutive same moves
    int sum = n;
    for(int i = 2; i <= n; i++) {
        if(c[i] == c[i-1]) {
            // Find a different winning move if possible
            if(s[i] == 'P' && c[i-1] != 'R') c[i] = 'R';
            else if(s[i] == 'R' && c[i-1] != 'S') c[i] = 'S';
            else if(s[i] == 'S' && c[i-1] != 'P') c[i] = 'P';
            else c[i] = s[i];  // if no winning option, choose same as input
            sum--;
        }
    }
    int ans = sum;
    
    // Second pass: try different starting point
    sum = n;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    // Handle first two moves differently
    if(n >= 2 && c[1] == c[2]) {
        // Change the second move
        if(s[2] == 'P' && c[1] != 'R') c[2] = 'R';
        else if(s[2] == 'R' && c[1] != 'S') c[2] = 'S';
        else if(s[2] == 'S' && c[1] != 'P') c[2] = 'P';
        else c[2] = s[2];
        sum--;
    }
    for(int i = 3; i <= n; i++) {
        if(c[i] == c[i-1]) {
            if(s[i] == 'P' && c[i-1] != 'R') c[i] = 'R';
            else if(s[i] == 'R' && c[i-1] != 'S') c[i] = 'S';
            else if(s[i] == 'S' && c[i-1] != 'P') c[i] = 'P';
            else c[i] = s[i];
            sum--;
        }
    }
    ans = max(ans, sum);
    
    printf("%d", ans);
    return 0;
}