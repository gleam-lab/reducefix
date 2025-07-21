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

    // Sort by A_i in ascending order
    sort(pairs.begin(), pairs.end());

    // Min-heap to keep track of smallest K B_i values
    priority_queue<ll, vector<ll>, greater<ll>> min_heap;
    ll sum_b = 0;

    // Initialize with first K elements
    for (ll i = 0; i < k; ++i) {
        sum_b += pairs[i].se;
        min_heap.push(pairs[i].se);
    }
    ll ans = sum_b * pairs[k - 1].fi;

    // Slide window over the rest
    for (ll i = k; i < n; ++i) {
        if (pairs[i].se > min_heap.top()) {
            sum_b -= min_heap.top();
            min_heap.pop();
            sum_b += pairs[i].se;
            min_heap.push(pairs[i].se);
        }
        ans = min(ans, sum_b * pairs[i].fi);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
}