#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve()
{
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<ll> s(n + 10); // Use ll to avoid overflow
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    map<ll, ll> mp;
    ll ans = 0;
    ll L = s[n];

    // We want s[j] ≡ s[i] - L mod M
    // So we look for s[j] ≡ (s[i] - L) mod M
    // Store counts of prefix sums mod M in map

    // First insert the 0 prefix sum (sum of 0 elements)
    mp[0] = 1;

    for (int i = 1; i <= n; i++) {
        ll curr_mod = s[i] % M;
        ll target_mod = (curr_mod - L % M + M) % M; // (s[i] - L) % M
        ans += mp[target_mod];
        mp[curr_mod]++;
    }

    cout << ans << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}