#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort items based on A[i]
        sort(items.begin(), items.end());

        // Max heap to store K smallest B values
        priority_queue<int> max_heap;
        long long sum_b = 0;

        // Initialize the first K elements
        for (int i = 0; i < K; ++i) {
            sum_b += items[i].second;
            max_heap.push(items[i].second);
        }

        long long result = 1LL * items[K - 1].first * sum_b;

        // Try including higher A[i] values while maintaining K elements
        for (int i = K; i < N; ++i) {
            if (!max_heap.empty() && items[i].second < max_heap.top()) {
                sum_b -= max_heap.top();
                max_heap.pop();

                sum_b += items[i].second;
                max_heap.push(items[i].second);
            }

            result = min(result, 1LL * items[i].first * sum_b);
        }

        cout << result << "\n";
    }

    return 0;
}