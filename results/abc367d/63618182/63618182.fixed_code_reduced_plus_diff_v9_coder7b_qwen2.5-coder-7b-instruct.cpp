#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10), s(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = (s[i - 1] + a[i]) % mod;
    }
    map<int, int> mp;
    ll ans = 0, L = s[n];
    for (int i = 1; i <= n; i++) {
        ans += mp[(s[i] - L * 1LL * i + mod) % mod];
        ans %= mod;
        ans += mp[s[i] % mod]++;
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}