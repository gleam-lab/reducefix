#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    map<int, int> mp;
    mp[0] = 1; // Initialize with prefix sum 0 mod M
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int current_mod = (s[i] % M + M) % M;
        ans += mp[current_mod];
        mp[current_mod]++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}