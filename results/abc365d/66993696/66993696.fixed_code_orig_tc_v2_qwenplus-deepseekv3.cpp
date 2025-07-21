#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // First pass: choose optimal moves to win
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // Second pass: adjust consecutive same moves to maximize wins
    int sum = n;
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i-1]) {
            // Find the best move that differs from both neighbors
            char prev = c[i-1];
            char next = (i < n) ? c[i+1] : '\0';
            char current = s[i];
            // Possible options are moves that beat s[i] and are not prev or next
            char opt1, opt2;
            if (current == 'P') {
                opt1 = 'S';
                opt2 = 'R';
            } else if (current == 'R') {
                opt1 = 'P';
                opt2 = 'S';
            } else {
                opt1 = 'R';
                opt2 = 'P';
            }
            if (opt1 != prev && (i == n || opt1 != next)) {
                c[i] = opt1;
            } else if (opt2 != prev && (i == n || opt2 != next)) {
                c[i] = opt2;
            } else {
                // If both options conflict, choose the one that beats s[i]
                c[i] = (opt1 == prev) ? opt2 : opt1;
                sum--;
            }
        }
    }
    
    // Third pass: handle the first element if it's the same as the second
    if (n > 1 && c[1] == c[2]) {
        char current = s[1];
        char next = c[2];
        char opt1, opt2;
        if (current == 'P') {
            opt1 = 'S';
            opt2 = 'R';
        } else if (current == 'R') {
            opt1 = 'P';
            opt2 = 'S';
        } else {
            opt1 = 'R';
            opt2 = 'P';
        }
        if (opt1 != next) {
            c[1] = opt1;
        } else {
            c[1] = opt2;
            sum--;
        }
    }
    
    // Count the number of wins
    int wins = 0;
    for (int i = 1; i <= n; ++i) {
        if ((c[i] == 'P' && s[i] == 'R') ||
            (c[i] == 'R' && s[i] == 'S') ||
            (c[i] == 'S' && s[i] == 'P')) {
            wins++;
        }
    }
    
    printf("%d\n", wins);
    return 0;
}