#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 0) {
        cout << "0\n";
        return;
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    ll ans = 0;
    ll cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += cnt / 2;
            cnt = 1;
        }
    }
    ans += cnt / 2;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}