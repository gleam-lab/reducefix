#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<ll, ll> PII;
const int mod = 1e9 + 7;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 10);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    map<ll, ll> mp;
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll rem = s[i] % M;
        if (rem < 0) rem += M; // Ensure non-negative remainder
        ans += mp[rem];
        mp[rem]++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}