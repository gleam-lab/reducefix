#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 2);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    map<ll, ll> cnt;
    ll ans = 0;
    cnt[0] = 1; // Handle the case when the subarray starts from index 0

    for (int i = 1; i <= n; ++i) {
        ll rem = ((prefix_sum[i] % M) + M) % M;
        ans += cnt[rem];
        cnt[rem]++;
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}