#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    // Initial transformation to winning moves
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    // First pass to eliminate adjacent duplicates
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            // Try to change c[i] to something different from both neighbors
            for (char candidate : {'R', 'P', 'S'}) {
                if (candidate != c[i - 1] && (i == n || candidate != c[i + 1])) {
                    c[i] = candidate;
                    break;
                }
            }
        }
    }
    
    // Count the number of positions where c[i] != c[i-1]
    int sum = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            sum--;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}