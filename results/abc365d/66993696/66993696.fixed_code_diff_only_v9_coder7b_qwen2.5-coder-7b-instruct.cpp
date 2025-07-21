#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s(n, ' ');
    cin >> s;

    vector<char> c(n, ' ');
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int ans = 0, sum = n;
    for (int i = 1; i < n; ++i) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i];
            --sum;
        }
    }
    ans = max(ans, sum);

    // Reset c array to original rules
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    if (s[0] == s[1]) {
        c[0] = s[0];
        --sum;
        for (int i = 2; i < n; ++i) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i];
                --sum;
            }
        }
    }
    ans = max(ans, sum);

    printf("%d\n", ans);
    return 0;
}