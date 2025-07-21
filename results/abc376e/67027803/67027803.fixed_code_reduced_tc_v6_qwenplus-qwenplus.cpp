#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].first;
    for (int i = 0; i < n; ++i) cin >> ab[i].second;

    // Sort based on A_i in ascending order
    sort(ab.begin(), ab.end());

    if (k == 1) {
        ll ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }

    // Max heap to maintain the k-1 smallest B_i values
    priority_queue<pair<ll, ll>> max_heap;
    ll sum = 0;
    for (int i = 0; i < k - 1; ++i) {
        sum += ab[i].second;
        max_heap.emplace(ab[i].second, i);
    }

    ll ans = INF;
    for (int i = k - 1; i < n; ++i) {
        auto [a, b] = ab[i];
        // Current set includes this item and k-1 items from the previous ones
        ans = min(ans, (sum + b) * a);

        // Try to replace the maximum B in current selection with smaller one
        if (!max_heap.empty() && max_heap.top().first > b) {
            sum -= max_heap.top().first;
            sum += b;
            max_heap.pop();
            max_heap.emplace(b, i);
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