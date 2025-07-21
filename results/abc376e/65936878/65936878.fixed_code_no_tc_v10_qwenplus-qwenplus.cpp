#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) cin >> items[i].f;
        for (int i = 0; i < n; ++i) cin >> items[i].s;

        // Sort by A_i in ascending order
        sort(items.begin(), items.end());

        // Min-heap to maintain the K largest B_i values among the selected A_i's
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;

        // Initialize with first K elements
        for (int i = 0; i < k; ++i) {
            sum_b += items[i].s;
            pq.push(items[i].s);
        }

        int ans = items[k - 1].f * sum_b;

        // Try each possible maximum A_i from position k onward
        for (int i = k; i < n; ++i) {
            // Current A_i is larger than previous ones, so current item could be a max
            if (items[i].s > pq.top()) {
                sum_b += items[i].s - pq.top();
                pq.pop();
                pq.push(items[i].s);
                ans = min(ans, items[i].f * sum_b);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}