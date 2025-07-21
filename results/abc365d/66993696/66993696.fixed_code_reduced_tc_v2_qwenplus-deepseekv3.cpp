#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Initial assignment: choose the counter that beats s[i]
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int sum = n;
    // Adjust to avoid consecutive duplicates
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            // Try to change c[i] to another counter that still beats s[i]
            if (s[i] == 'P' && c[i] != 'R') c[i] = 'R';
            else if (s[i] == 'R' && c[i] != 'S') c[i] = 'S';
            else if (s[i] == 'S' && c[i] != 'P') c[i] = 'P';
            else {
                // If no other option, change to s[i] (losing this round)
                c[i] = s[i];
                sum--;
            }
        }
    }
    
    printf("%d\n", sum);
    return 0;
}