#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

char beat(char ch) {
    if (ch == 'P') return 'S';
    if (ch == 'R') return 'P';
    if (ch == 'S') return 'R';
    return ch;
}

int solve(int n) {
    // Try all possible starting characters for the first position
    int max_score = 0;
    
    // We'll try three strategies: keep original, or change first to one of the two other options
    for (char first : {'P', 'R', 'S'}) {
        c[1] = first;
        int score = 1; // First character is always counted
        
        for (int i = 2; i <= n; i++) {
            char desired = beat(s[i]);
            if (desired == c[i-1]) {
                // Can't use the winning move, so we have to use something else
                // Try to find an alternative that isn't equal to previous
                if (desired == 'P') {
                    c[i] = (c[i-1] != 'R') ? 'R' : 'S';
                } else if (desired == 'R') {
                    c[i] = (c[i-1] != 'S') ? 'S' : 'P';
                } else { // desired == 'S'
                    c[i] = (c[i-1] != 'P') ? 'P' : 'R';
                }
            } else {
                c[i] = desired;
                score++;
            }
        }
        
        max_score = max(max_score, score);
    }
    
    return max_score;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    printf("%d\n", solve(n));
    return 0;
}