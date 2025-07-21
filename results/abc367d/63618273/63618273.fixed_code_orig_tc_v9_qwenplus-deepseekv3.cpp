#include<bits/stdc++.h>

using namespace std;
using ll=long long;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + a[i];
    }

    map<int, int> mod_counts;
    mod_counts[0] = 1;
    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        int mod = (prefix[i] % M + M) % M;
        ans += mod_counts[mod];
        mod_counts[mod]++;
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