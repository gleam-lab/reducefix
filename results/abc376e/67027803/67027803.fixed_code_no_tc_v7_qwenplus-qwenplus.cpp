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

    if (k == 1) {
        ll ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, items[i].first * items[i].second);
        }
        cout << ans << '\n';
        return;
    }

    // Max heap to keep track of top (k-1) B_i values
    priority_queue<ll> max_heap;
    ll sum_b = 0;

    // Initialize with first k-1 elements
    for (int i = 0; i < k - 1; ++i) {
        max_heap.push(items[i].second);
        sum_b += items[i].second;
    }

    ll result = INF;

    // Try each element from position k-1 as the max A_i in subset
    for (int i = k - 1; i < n; ++i) {
        ll current_a = items[i].first;
        ll current_b = items[i].second;

        // Current subset: k-1 smallest A's + this one
        result = min(result, (sum_b + current_b) * current_a);

        // Prepare for next iteration: maintain top k-1 smallest B's
        if (!max_heap.empty() && max_heap.top() > current_b) {
            sum_b -= max_heap.top();
            max_heap.pop();
            sum_b += current_b;
            max_heap.push(current_b);
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
    return 0;
}