#include <bits/stdc++.h>
using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}