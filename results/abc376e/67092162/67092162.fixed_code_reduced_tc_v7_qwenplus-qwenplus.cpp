#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N); // Stores pairs (A_i, B_i)

        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        // Max-heap to maintain the K smallest B_i values among the first K elements
        priority_queue<int> pq;
        long long sum_b = 0;

        for (int i = 0; i < K; ++i) {
            sum_b += items[i].second;
            pq.push(items[i].second);
        }

        long long result = 1LL * items[K - 1].first * sum_b;

        // Try to improve result by swapping larger A with smaller B
        for (int i = K; i < N; ++i) {
            if (pq.empty() || items[i].second < pq.top()) {
                if (!pq.empty()) {
                    sum_b -= pq.top();
                    pq.pop();
                }
                sum_b += items[i].second;
                pq.push(items[i].second);
                result = min(result, 1LL * items[i].first * sum_b);
            }
        }

        cout << result << '\n';
    }

    return 0;
}