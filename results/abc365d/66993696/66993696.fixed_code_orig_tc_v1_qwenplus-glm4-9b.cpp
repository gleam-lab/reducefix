#include<bits/stdc++.h>
using namespace std;
char s[200011];
char c[200011];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    int ans = 0;
    int sum = n;
    for (int i = 1; i < n; i++) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i];
            sum--;
        }
    }
    ans = max(ans, sum);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    if (n > 1 && s[0] == s[1]) {
        c[0] = s[0];
        c[1] = s[1];
        sum = n - 2;
        for (int i = 2; i < n; i++) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i];
                sum--;
            }
        }
        ans = max(ans, sum);
    }
    printf("%d", ans);
}