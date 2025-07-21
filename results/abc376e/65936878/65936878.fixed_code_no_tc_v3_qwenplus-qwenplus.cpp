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
        for (int i = 0; i < n; ++i) cin >> items[i].f;
        for (int i = 0; i < n; ++i) cin >> items[i].s;

        // Sort items by A_i in ascending order
        sort(items.begin(), items.end());

        // Min-heap to keep track of the K largest B_i values
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;

        // Initialize with the first K-1 elements
        for (int i = 0; i < k - 1; ++i) {
            sum_b += items[i].s;
            pq.push(items[i].s);
        }

        int ans = LLONG_MAX;

        // Try each possible max A_i from position k-1 to n-1
        for (int i = k - 1; i < n; ++i) {
            // Current maximum A is items[i].f
            // Consider adding items[i] and removing one with smallest B
            if (pq.size() < k - 1) {
                sum_b += items[i].s;
                pq.push(items[i].s);
            } else if (pq.empty() || items[i].s > pq.top()) {
                sum_b += items[i].s - pq.top();
                pq.pop();
                pq.push(items[i].s);
            }

            ans = min(ans, items[i].f * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}