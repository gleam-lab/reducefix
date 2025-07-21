#include<bits/stdc++.h>
using namespace std;
char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // First pass: transform based on initial conditions
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Second pass: compress consecutive identical characters
    int sum = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            sum--;
            c[i] = s[i]; // Set to original character to preserve the count
        }
    }

    // Reset characters to determine if we can further compress
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Third pass: check if first two characters are the same
    if (s[1] == s[2]) {
        c[1] = s[1]; // Set first character to original to preserve the count
        sum--;
        for (int i = 3; i <= n; i++) {
            if (c[i] == c[i - 1]) {
                sum--;
                c[i] = s[i]; // Set to original character to preserve the count
            }
        }
    }

    // Output the maximum compressed length
    printf("%d", sum);
    return 0;
}