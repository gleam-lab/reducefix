#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i)
            cin >> items[i].first;

        for (int i = 0; i < N; ++i)
            cin >> items[i].second;

        // Sort items by A[i]
        sort(items.begin(), items.end());

        // Min-heap to store B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        int result = 1e18; // Large initial value

        // Precompute prefix sums of B values
        vector<int> prefix_sum(N + 1, 0);

        for (int i = 0; i < N; ++i) {
            if (i < K - 1) {
                pq.push(items[i].second);
                sum_b += items[i].second;
                prefix_sum[i + 1] = sum_b;
            } else {
                // Store prefix sum up to i
                pq.push(items[i].second);
                sum_b += items[i].second;
                prefix_sum[i + 1] = sum_b;

                // Maintain heap size K
                if (pq.size() > K) {
                    sum_b -= pq.top();
                    pq.pop();
                }

                // Now we can form a subset of K elements ending at i
                int current_max_A = items[i].first;
                int current_sum_B = sum_b;
                result = min(result, current_max_A * current_sum_B);
            }
        }

        cout << result << "\n";
    }

    return 0;
}