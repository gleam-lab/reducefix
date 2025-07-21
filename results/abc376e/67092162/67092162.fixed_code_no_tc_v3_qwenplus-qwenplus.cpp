#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Pair A and B values
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {a[i], b[i]};
        }

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        // Max heap to maintain the K smallest B's in current window
        priority_queue<int> pq;
        long long sum_b = 0;
        long long result = 1e18; // Initialize with large number

        // First window of K elements
        for (int i = 0; i < k; ++i) {
            pq.push(items[i].second);
            sum_b += items[i].second;
        }
        result = 1LL * items[k - 1].first * sum_b;

        // Sliding window
        for (int i = k; i < n; ++i) {
            if (items[i].second < pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].second);
                sum_b += items[i].second;
            }
            result = min(result, 1LL * items[i].first * sum_b);
        }

        cout << result << "\n";
    }

    return 0;
}