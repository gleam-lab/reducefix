#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Initialize the counter for wins
    int wins = 0;
    
    // First pass: choose the optimal move for each position
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Check for consecutive same moves and adjust
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            // Change the current move to the original move to prevent loss
            c[i] = s[i];
        }
    }
    
    // Count the number of wins
    for (int i = 1; i <= n; ++i) {
        if ((s[i] == 'P' && c[i] == 'S') ||
            (s[i] == 'R' && c[i] == 'P') ||
            (s[i] == 'S' && c[i] == 'R')) {
            wins++;
        }
    }
    
    printf("%d\n", wins);
    return 0;
}