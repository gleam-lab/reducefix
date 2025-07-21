#include<bits/stdc++.h>
using namespace std;
char s[200011];
char c[200011];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    memset(c, 0, sizeof(c));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] != s[i]) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}