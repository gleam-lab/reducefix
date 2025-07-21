#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // First, transform each character to its winning move
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int sum = n;
    // First pass to break consecutive duplicates
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            // Try to change c[i] to something else that still beats s[i] and is different from c[i-1]
            if (s[i] == 'P') {
                if ('S' != c[i - 1]) c[i] = 'S';
                else c[i] = 'R'; // 'R' doesn't beat 'P', but we have to choose something
            } else if (s[i] == 'R') {
                if ('P' != c[i - 1]) c[i] = 'P';
                else c[i] = 'S'; // 'S' doesn't beat 'R'
            } else { // 'S'
                if ('R' != c[i - 1]) c[i] = 'R';
                else c[i] = 'P'; // 'P' doesn't beat 'S'
            }
            // If we changed to a move that doesn't beat s[i], it's invalid, so revert
            if ((s[i] == 'P' && c[i] != 'S') || 
                (s[i] == 'R' && c[i] != 'P') || 
                (s[i] == 'S' && c[i] != 'R')) {
                c[i] = s[i]; // revert to original, which forces a loss but breaks the sequence
            }
            sum--;
        }
    }
    
    // Check if we can improve by changing the first character differently
    int sum2 = n;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    // Change the first character to original to see if it helps
    if (n > 1 && c[1] == c[2]) {
        c[1] = s[1];
        sum2--;
        for (int i = 3; i <= n; ++i) {
            if (c[i] == c[i - 1]) {
                if (s[i] == 'P') {
                    if ('S' != c[i - 1]) c[i] = 'S';
                    else c[i] = 'R';
                } else if (s[i] == 'R') {
                    if ('P' != c[i - 1]) c[i] = 'P';
                    else c[i] = 'S';
                } else {
                    if ('R' != c[i - 1]) c[i] = 'R';
                    else c[i] = 'P';
                }
                if ((s[i] == 'P' && c[i] != 'S') || 
                    (s[i] == 'R' && c[i] != 'P') || 
                    (s[i] == 'S' && c[i] != 'R')) {
                    c[i] = s[i];
                }
                sum2--;
            }
        }
    }
    
    printf("%d\n", max(sum, sum2));
    return 0;
}