#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first; // A_i
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second; // B_i
    }

    // Sort by A_i ascending
    sort(a.begin(), a.end());

    int sum_b = 0;
    priority_queue<int> pq; // max heap (we'll invert sign to simulate min-heap)
    int res = 1e18; // Large initial value

    for (int i = 0; i < n; ++i) {
        // Always include the current B_i as we're considering it as part of subset
        sum_b += a[i].second;
        pq.push(-a[i].second); // Min-heap simulation with negative

        // If more than K elements, remove the smallest B_i
        if (pq.size() > k) {
            sum_b += pq.top(); // Since stored as negative
            pq.pop();
        }

        // When we have exactly K elements, calculate the product
        if (pq.size() == k) {
            res = min(res, a[i].first * sum_b);
        }
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}