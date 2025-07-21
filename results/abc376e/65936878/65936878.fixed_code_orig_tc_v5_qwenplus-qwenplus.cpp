#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].f;
        for (int i = 0; i < n; ++i) cin >> v[i].s;

        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int sumB = 0;

        // Initialize with first k-1 elements' B values
        for (int i = 0; i < k - 1; ++i) {
            sumB += v[i].s;
            pq.push(v[i].s);
        }

        int ans = 1e18;

        for (int i = k - 1; i < n; ++i) {
            // Try to add current element and compute cost
            ans = min(ans, (sumB + v[i].s) * v[i].f);

            // Maintain the smallest k-1 B-values using a max heap (priority queue)
            if (pq.size() < k - 1) {
                sumB += v[i].s;
                pq.push(v[i].s);
            } else if (!pq.empty() && pq.top() > v[i].s) {
                sumB += v[i].s - pq.top();
                pq.pop();
                pq.push(v[i].s);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}