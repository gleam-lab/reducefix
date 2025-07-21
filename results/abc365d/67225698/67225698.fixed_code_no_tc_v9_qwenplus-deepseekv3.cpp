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
    ll ans = 0;
    ll cnt = 1;
    vector<ll> v;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            v.push_back(cnt);
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2;
    v.push_back(cnt);
    // Adjust for overlapping groups
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == 1 && v[i - 1] % 2 == 1) {
            ans--;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}