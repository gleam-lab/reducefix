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

        // Min-heap to keep the K largest B_i values among the current window
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;

        // Initialize with first K elements
        for (int i = 0; i < k; ++i) {
            sum_b += items[i].s;
            pq.push(items[i].s);
        }

        int ans = items[k - 1].f * sum_b;

        // Slide window over the rest
        for (int i = k; i < n; ++i) {
            // Current A[i] must be included, so possibly remove one of the previous B's
            if (items[i].s > pq.top()) {
                sum_b -= pq.top();
                sum_b += items[i].s;
                pq.pop();
                pq.push(items[i].s);
            }
            ans = min(ans, items[i].f * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}