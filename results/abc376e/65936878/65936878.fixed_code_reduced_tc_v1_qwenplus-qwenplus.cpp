#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].f; // A_i
        }
        for (int i = 0; i < n; ++i) {
            cin >> items[i].s; // B_i
        }

        // Sort items by A_i ascending
        sort(items.begin(), items.end());

        // Max-heap to maintain the K smallest B_i values seen so far
        priority_queue<int> max_heap;
        int sum_b = 0;
        // First fill with first k elements
        for (int i = 0; i < k; ++i) {
            sum_b += items[i].s;
            max_heap.push(items[i].s);
        }

        int ans = items[k - 1].f * sum_b;

        // Try including better candidates
        for (int i = k; i < n; ++i) {
            // If current B_i is smaller than largest in our set, replace it
            if (items[i].s < max_heap.top()) {
                sum_b -= max_heap.top();
                max_heap.pop();
                sum_b += items[i].s;
                max_heap.push(items[i].s);
                ans = min(ans, items[i].f * sum_b);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}