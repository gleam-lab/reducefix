#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<PII> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort items by A_i ascending
        sort(items.begin(), items.end());

        int sum_B = 0;
        priority_queue<int> max_heap; // To maintain the K smallest B_i values

        // Initialize with first K-1 elements
        for (int i = 0; i < K - 1; ++i) {
            sum_B += items[i].second;
            max_heap.push(items[i].second);
        }

        int result = INF;

        // Process remaining elements starting from index K-1
        for (int i = K - 1; i < N; ++i) {
            // Add current item's B value
            sum_B += items[i].second;
            max_heap.push(items[i].second);

            // If heap size exceeds K, remove the largest B
            if (max_heap.size() > K) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }

            // Calculate the current maximum A (which is items[i].first since sorted)
            // and multiply with sum of selected B's
            result = min(result, items[i].first * sum_B);
        }

        cout << result << '\n';
    }

    return 0;
}