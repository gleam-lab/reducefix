#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int calculate_max(int n) {
    int sum = n;
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
    scanf("%s", s+1);

    // First scenario: transform all
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    int ans = calculate_max(n);

    // Second scenario: keep the first character the same, transform the rest
    c[1] = s[1];
    for (int i = 2; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    ans = max(ans, calculate_max(n));

    printf("%d\n", ans);
    return 0;
}