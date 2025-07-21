#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN];
char c[MAXN];

int solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Apply the transformation: P->S, R->P, S->R
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'P') c[i] = 'S';
        else if(s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int ans = 0;
    int sum = n;

    // First pass: eliminate adjacent duplicates
    for(int i = 2; i <= n; ++i) {
        if(c[i] == c[i-1]) {
            sum--;
        }
    }
    ans = sum;

    // Second pass: try changing first character to match second (if same)
    if(n >= 2 && c[1] == c[2]) {
        sum = n - 1;  // changed first character, so one less
        for(int i = 3; i <= n; ++i) {
            if(c[i] == c[i-1]) {
                sum--;
            }
        }
        ans = max(ans, sum);
    }

    return ans;
}

int main() {
    printf("%d\n", solve());
    return 0;
}