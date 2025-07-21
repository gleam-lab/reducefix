#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    for (int i = 0; i < n; ++i) cin >> ab[i].first;
    for (int i = 0; i < n; ++i) cin >> ab[i].second;

    // Sort by A in ascending order
    sort(ab.begin(), ab.end());

    priority_queue<ll> max_heap;
    ll b_sum = 0;
    ll res = INF;

    // Initialize heap with first K-1 elements' B values
    for (int i = 0; i < k - 1; ++i) {
        max_heap.push(ab[i].second);
        b_sum += ab[i].second;
    }

    // Try every element from index K-1 onward as the max A
    for (int i = k - 1; i < n; ++i) {
        auto [a, b] = ab[i];
        b_sum += b;
        max_heap.push(b);

        // Maintain only top K-1 B values
        while (max_heap.size() > k - 1) {
            b_sum -= max_heap.top();
            max_heap.pop();
        }

        // Calculate current cost
        res = min(res, a * b_sum);

        // Restore the heap for next iteration
        max_heap.push(b);
        b_sum -= b;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}