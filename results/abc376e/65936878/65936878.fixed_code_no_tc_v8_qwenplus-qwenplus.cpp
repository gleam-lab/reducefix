#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) cin >> items[i].f;
        for (int i = 0; i < n; ++i) cin >> items[i].s;

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        // Max-heap to maintain the K-1 smallest B_i values
        priority_queue<int> max_heap;
        int sum_b = 0;

        // Initialize with first k-1 elements
        for (int i = 0; i < k - 1; ++i) {
            sum_b += items[i].s;
            max_heap.push(items[i].s);
        }

        int ans = LLONG_MAX;

        // Try including each item from position k-1 onward as the max A_i
        for (int i = k - 1; i < n; ++i) {
            // Current candidate: A[i] is the max, and we pick k items in total
            // Include current B[i] in the sum, and choose the k-1 smallest among previous ones
            ans = min(ans, (sum_b + items[i].s) * items[i].f);

            // Prepare for next iteration
            if (i < n - 1) {
                if (max_heap.empty() || items[i].s < max_heap.top()) {
                    // Replace the largest in heap with current smaller one
                    if (!max_heap.empty()) {
                        sum_b -= max_heap.top();
                        max_heap.pop();
                    }
                    sum_b += items[i].s;
                    max_heap.push(items[i].s);
                }
                // Else, discard current B[i]
            }
        }

        cout << ans << '\n';
    }

    return 0;
}