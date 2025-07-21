#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].f;
        for (int i = 0; i < n; ++i) cin >> v[i].s;

        // Sort by A_i ascending
        sort(v.begin(), v.end());

        priority_queue<int> pq;
        int sum_b = 0;
        // Initialize the first K-1 elements based on max A_i among them
        for (int i = 0; i < k - 1; ++i) {
            sum_b += v[i].s;
            pq.push(v[i].s);
        }

        int res = LLONG_MAX;
        // Try each candidate as the max A_i in the subset
        for (int i = k - 1; i < n; ++i) {
            pq.push(v[i].s);
            sum_b += v[i].s;

            // Maintain a heap of size k
            while ((int)pq.size() > k) {
                sum_b -= pq.top();
                pq.pop();
            }

            res = min(res, v[i].f * sum_b);
        }
        cout << res << '\n';
    }
}