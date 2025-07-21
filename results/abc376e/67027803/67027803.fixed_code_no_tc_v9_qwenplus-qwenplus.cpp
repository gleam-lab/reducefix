#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> items(n);
    for (int i = 0; i < n; ++i) cin >> items[i].first;
    for (int i = 0; i < n; ++i) cin >> items[i].second;

    // Sort items by A_i in ascending order
    sort(items.begin(), items.end());

    // If K == 1, simply find the minimum A_i * B_i
    if (k == 1) {
        ll ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, items[i].first * items[i].second);
        }
        cout << ans << '\n';
        return;
    }

    // Max-heap to store B_i values of the smallest K-1 A_i's
    priority_queue<ll> max_heap;
    ll sum_b = 0;

    // Initialize with first K-1 elements
    for (int i = 0; i < k - 1; ++i) {
        sum_b += items[i].second;
        max_heap.push(items[i].second);
    }

    ll result = INF;

    // Try each candidate for the maximum A_i in subset
    for (int i = k - 1; i < n; ++i) {
        auto [a, b] = items[i];
        // Current subset: previous k-1 items + this item
        ll current_score = (sum_b + b) * a;
        result = min(result, current_score);

        // Try to replace the largest B_i in subset with smaller ones later
        if (b < max_heap.top()) {
            sum_b -= max_heap.top();
            sum_b += b;
            max_heap.pop();
            max_heap.push(b);
        }
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}