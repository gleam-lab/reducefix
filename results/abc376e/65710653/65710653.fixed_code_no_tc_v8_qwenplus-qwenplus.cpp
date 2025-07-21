#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define fi first
#define se second
#define pb push_back

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pll> pairs(n);
    for (ll i = 0; i < n; ++i) cin >> pairs[i].fi;
    for (ll i = 0; i < n; ++i) cin >> pairs[i].se;

    // Sort by A_i ascending
    sort(pairs.begin(), pairs.end());

    // Min-heap to maintain the K largest B_i values
    multiset<ll> max_b;
    ll sum_b = 0;

    // Initialize with the first K elements
    for (ll i = 0; i < k; ++i) {
        max_b.insert(pairs[i].se);
        sum_b += pairs[i].se;
    }

    ll ans = sum_b * pairs[k - 1].fi;

    // Sliding window: add next element and remove one smallest B from set
    for (ll i = k; i < n; ++i) {
        // Add current B_i
        max_b.insert(pairs[i].se);
        sum_b += pairs[i].se;

        // Remove smallest B in the set
        sum_b -= *max_b.begin();
        max_b.erase(max_b.begin());

        // Update answer with current max A_i (pairs[i].fi)
        ans = min(ans, sum_b * pairs[i].fi);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
}