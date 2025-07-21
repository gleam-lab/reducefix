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

        // Max heap to keep the smallest B_i values among top K
        priority_queue<int> max_heap;
        int sum_b = 0;
        for (int i = 0; i < k - 1; ++i) {
            sum_b += items[i].s;
            max_heap.push(items[i].s);
        }

        int ans = LLONG_MAX;

        for (int i = k - 1; i < n; ++i) {
            // Try selecting current item as the max A_i
            int current_score = (sum_b + items[i].s) * items[i].f;
            ans = min(ans, current_score);

            // Prepare for next iteration
            if (i < n - 1) {
                if (!max_heap.empty() && items[i].s < max_heap.top()) {
                    // Replace the largest B in heap with smaller one
                    sum_b -= max_heap.top();
                    sum_b += items[i].s;
                    max_heap.pop();
                    max_heap.push(items[i].s);
                } else if (max_heap.size() < k - 1) {
                    // If heap not full, add current B_i
                    sum_b += items[i].s;
                    max_heap.push(items[i].s);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}