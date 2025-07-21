#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ab(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].second;
    }

    // Sort by A[i]
    sort(ab.begin(), ab.end());

    priority_queue<int> min_heap;
    int sum_b = 0;
    int res = 1e18;

    for (int i = 0; i < n; ++i) {
        int a_val = ab[i].first;
        int b_val = ab[i].second;

        // Add current B value
        if (min_heap.size() < k - 1) {
            sum_b += b_val;
            min_heap.push(-b_val); // Min-heap via negation
        } else {
            // Maintain only top (k-1) B values
            if (!min_heap.empty() && b_val > -min_heap.top()) {
                sum_b += b_val + min_heap.top();
                min_heap.pop();
                min_heap.push(-b_val);
            }
        }

        // Once we have at least (k-1) elements, we can consider current A as max
        if (min_heap.size() == k - 1) {
            res = min(res, (sum_b + b_val) * a_val);
        }
    }

    cout << res << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}