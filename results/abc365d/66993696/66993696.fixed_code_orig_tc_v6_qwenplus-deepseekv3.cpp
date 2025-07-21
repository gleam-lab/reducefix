#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<char> c(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int sum = n;
    for (int i = 1; i < n; ++i) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            sum--;
        }
    }
    
    int ans = sum;
    sum = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    if (n > 1 && s[0] == s[1]) {
        c[0] = s[0];
        sum--;
        for (int i = 2; i < n; ++i) {
            if (c[i] == c[i-1]) {
                c[i] = s[i];
                sum--;
            }
        }
    }
    ans = max(ans, sum);
    
    cout << ans << '\n';
    return 0;
}