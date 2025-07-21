#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].first;
    for (int i = 0; i < n; ++i) cin >> ab[i].second;

    sort(ab.begin(), ab.end());

    if (k == 1) {
        ll ans = INF;
        for (auto [a, b] : ab)
            ans = min(ans, a * b);
        cout << ans << '\n';
        return;
    }

    priority_queue<ll> max_heap; // max-heap to keep track of the largest among the smallest K-1 B values
    ll sum_b = 0;
    for (int i = 0; i < k - 1; ++i) {
        sum_b += ab[i].second;
        max_heap.push(ab[i].second);
    }

    ll result = INF;
    for (int i = k - 1; i < n; ++i) {
        ll curr_a = ab[i].first;
        ll curr_b = ab[i].second;

        // Try forming a subset with current A[i] as the max A and selecting smallest K-1 B's
        result = min(result, (sum_b + curr_b) * curr_a);

        // Maintain only the K-1 smallest B's so far
        if (!max_heap.empty() && max_heap.top() > curr_b) {
            sum_b -= max_heap.top();
            sum_b += curr_b;
            max_heap.pop();
            max_heap.push(curr_b);
        }
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}