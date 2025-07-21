#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<PII> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> items[i].second;
        }

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        int sum_b = 0;
        priority_queue<int> max_heap; // To keep the smallest K B_i's

        // Initially fill with first K-1 elements
        for (int i = 0; i < k - 1; ++i) {
            sum_b += items[i].second;
            max_heap.push(items[i].second);
        }

        int res = INF;

        // Now process the rest
        for (int i = k - 1; i < n; ++i) {
            // Add current item's B value
            sum_b += items[i].second;
            max_heap.push(items[i].second);

            // If we have more than K elements, remove the largest B seen so far
            if (max_heap.size() > k) {
                sum_b -= max_heap.top();
                max_heap.pop();
            }

            // Compute the cost: A_i * sum_b
            res = min(res, items[i].first * sum_b);
        }

        cout << res << "\n";
    }

    return 0;
}