#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n, int first_change) {
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    if (first_change == 1) {
        c[1] = s[1];
    } else if (first_change == 2) {
        c[n] = s[n];
    }
    
    int sum = n;
    // Check consecutive duplicates from left to right
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            sum--;
        }
    }
    
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    if (n == 1) {
        printf("1");
        return 0;
    }
    
    int ans = 0;
    // Case 1: No initial change
    ans = max(ans, solve(n, 0));
    
    // Case 2: Change first character
    ans = max(ans, solve(n, 1));
    
    // Case 3: Change last character  
    ans = max(ans, solve(n, 2));
    
    printf("%d", ans);
    return 0;
}