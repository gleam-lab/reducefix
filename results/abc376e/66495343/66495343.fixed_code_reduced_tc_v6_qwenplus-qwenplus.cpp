#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Create list of pairs and sort by A[i]
        vector<PII> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {a[i], b[i]};
        }
        sort(items.begin(), items.end());

        int res = INF;
        int sum_b = 0;
        priority_queue<int> min_heap;

        // We need to pick the first K elements with smallest A[i]
        // Then as we move forward, we can replace the max B[i] in our set
        for (int i = 0; i < n; ++i) {
            sum_b += items[i].second;
            min_heap.push(-items[i].second); // Use max heap as min heap with negation

            if (i >= k - 1) {
                // Maintain only K elements in our set
                while (min_heap.size() > k) {
                    sum_b += min_heap.top(); // Add back the removed value
                    min_heap.pop();
                }
                // Current max A[i] is items[i].first
                res = min(res, items[i].first * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}