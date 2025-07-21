#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> items(n);
    for (int i = 0; i < n; ++i) cin >> items[i].first;
    for (int i = 0; i < n; ++i) cin >> items[i].second;

    // Sort by A_i in ascending order
    sort(items.begin(), items.end());

    if (k == 1) {
        ll ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, items[i].first * items[i].second);
        }
        cout << ans << '\n';
        return;
    }

    // Maintain a max-heap of B values for the smallest k-1 elements
    priority_queue<pair<ll, ll>> pq; // Max-heap (we'll push negative to simulate min-heap)
    ll sum = 0;
    for (int i = 0; i < k - 1; ++i) {
        pq.push({items[i].second, i});
        sum += items[i].second;
    }

    ll ans = INF;
    for (int i = k - 1; i < n; ++i) {
        ll currentA = items[i].first;
        ll currentB = items[i].second;

        // Current set includes this item and the best k-1 from before
        ans = min(ans, (sum + currentB) * currentA);

        // Try to replace the max B in our set with smaller B from the rest
        if (i < n - 1 && !pq.empty() && pq.top().first > currentB) {
            sum -= pq.top().first;
            sum += currentB;
            pq.pop();
            pq.push({currentB, i});
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}