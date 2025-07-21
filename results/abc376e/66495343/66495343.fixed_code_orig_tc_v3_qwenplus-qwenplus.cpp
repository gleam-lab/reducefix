#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define ar array<int, 3>

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<PII> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].fi;
        for (int i = 0; i < n; ++i) cin >> v[i].se;

        // Sort by A[i]
        sort(v.begin(), v.end());

        // Min-heap for maintaining top K smallest B[i] values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        int res = numeric_limits<int>::max();

        // First pass: build initial sum of first K-1 B[i]
        for (int i = 0; i < k - 1; ++i) {
            sum_b += v[i].se;
            pq.push(v[i].se);
        }

        // Slide through the rest
        for (int i = k - 1; i < n; ++i) {
            sum_b += v[i].se;
            pq.push(v[i].se);

            // Maintain only K elements
            if (pq.size() > k) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Compute current cost
            res = min(res, v[i].fi * sum_b);
        }

        cout << res << '\n';
    }
}