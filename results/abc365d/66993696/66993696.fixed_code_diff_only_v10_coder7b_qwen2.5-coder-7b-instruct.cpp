#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s(n + 1), t(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf(" %c", &s[i]);
        if (s[i] == 'P') t[i] = 'S';
        else if (s[i] == 'R') t[i] = 'P';
        else t[i] = 'R';
    }
    
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (t[i] == t[i - 1]) {
            t[i] = s[i];
            --ans;
        }
    }
    
    if (s[1] == s[2]) {
        t[1] = s[1];
        --ans;
        for (int i = 3; i <= n; ++i) {
            if (t[i] == t[i - 1]) {
                t[i] = s[i];
                --ans;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}