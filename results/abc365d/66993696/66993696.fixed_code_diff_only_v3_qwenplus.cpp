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

int solve(int n, int start) {
    // start: 0 means no change at beginning, 1 means change first character
    for (int i = 1; i <= n; i++) {
        c[i] = beat(s[i]);
    }
    
    if (start == 1) {
        c[1] = s[1];
    }
    
    int cnt = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // change to original to break the tie
            cnt--;
        }
    }
    
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    int ans = max(solve(n, 0), solve(n, 1));
    printf("%d\n", ans);
    
    return 0;
}