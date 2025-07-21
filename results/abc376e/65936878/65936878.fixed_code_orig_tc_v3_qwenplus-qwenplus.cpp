#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> v[i].second;
        }

        // Sort by A[i]
        sort(v.begin(), v.end());

        // Min-heap to keep track of the smallest K B[i] values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;

        // Initialize with first K-1 elements' B[i]
        for (int i = 0; i < k - 1; ++i) {
            sum_b += v[i].second;
            pq.push(v[i].second);
        }

        int ans = 1e18;

        // Try to complete subset with i-th A[i] as max A
        for (int i = k - 1; i < n; ++i) {
            sum_b += v[i].second;
            pq.push(v[i].second);
            ans = min(ans, v[i].first * sum_b);

            if (pq.size() > k) {
                sum_b -= pq.top();
                pq.pop();
            }
        }

        cout << ans << '\n';
    }

    return 0;
}