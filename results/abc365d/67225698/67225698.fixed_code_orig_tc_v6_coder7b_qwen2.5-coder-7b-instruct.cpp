#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            cnt = 1;
        } else {
            ++cnt;
        }
        
        if (cnt >= 3) {
            ans += cnt / 2;
            cnt %= 2;
        }
    }
    
    ans += (cnt + 1) / 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}