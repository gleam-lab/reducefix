#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].first;
    for (int i = 0; i < n; ++i) cin >> ab[i].second;

    // Sort based on A_i in ascending order
    sort(ab.begin(), ab.end());

    // If K == 1, just find the minimum of A_i * B_i
    if (k == 1) {
        ll ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, ab[i].first * ab[i].second);
        }
        cout << ans << '\n';
        return;
    }

    // Max heap to store B values of first (k-1) elements
    priority_queue<ll> max_heap;
    ll sum_b = 0;
    for (int i = 0; i < k - 1; ++i) {
        max_heap.push(ab[i].second);
        sum_b += ab[i].second;
    }

    ll result = INF;
    // Try each element from (k-1) to (n-1) as the max A_i in the subset
    for (int i = k - 1; i < n; ++i) {
        auto [a, b] = ab[i];
        // Current value: current A * (sum of k-1 smallest B's + current B)
        result = min(result, a * (sum_b + b));

        // If this b is smaller than the max in heap, we include it and remove the larger one
        if (!max_heap.empty() && b < max_heap.top()) {
            sum_b += b - max_heap.top();
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