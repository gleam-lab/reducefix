#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % M;
    }

    map<ll, ll> count;
    ll ans = 0;
    count[0] = 1; // To handle subarrays starting from index 0

    for (int i = 1; i <= n; ++i) {
        // For each prefix_sum[i], find how many times (prefix_sum[i] - M) and prefix_sum[i] appeared before
        ll target = (prefix_sum[i] - M + M) % M;
        ans += count[target];
        ans += count[prefix_sum[i]]++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}