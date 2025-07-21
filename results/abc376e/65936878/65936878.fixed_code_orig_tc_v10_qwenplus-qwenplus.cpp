#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first;
        for (int i = 0; i < n; ++i) cin >> v[i].second;
        sort(v.begin(), v.end());

        priority_queue<int> pq;
        int sum_b = 0;
        for (int i = 0; i < k - 1; ++i) {
            sum_b += v[i].second;
            pq.push(v[i].second);
        }

        int result = 1e18;
        for (int i = k - 1; i < n; ++i) {
            // Consider current A[i] as the max A in the subset
            int current_a = v[i].first;
            int current_b_sum = sum_b + v[i].second;
            result = min(result, current_a * current_b_sum);

            // Maintain the K-1 largest B's before i
            if (!pq.empty()) {
                // If current B is better than the worst in heap, replace it
                if (pq.empty() || v[i].second < pq.top()) {
                    sum_b -= pq.top();
                    pq.pop();
                    sum_b += v[i].second;
                    pq.push(v[i].second);
                }
            } else {
                sum_b += v[i].second;
                pq.push(v[i].second);
            }
        }
        cout << result << '\n';
    }
}