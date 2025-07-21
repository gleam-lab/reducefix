#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
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
    cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}