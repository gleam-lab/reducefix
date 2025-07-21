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

        vector<pair<int, int>> items(N);  // Pair: (A_i, B_i)
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        // Max heap to maintain the top K smallest B_i values
        priority_queue<int> pq;
        long long sum_b = 0;

        // Take first K elements by B_i
        for (int i = 0; i < K; ++i) {
            sum_b += items[i].second;
            pq.push(items[i].second);
        }

        // Initial cost
        long long result = 1LL * items[K - 1].first * sum_b;

        // Try to improve by swapping larger A with smaller B
        for (int i = K; i < N; ++i) {
            if (!pq.empty() && items[i].second < pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                sum_b += items[i].second;
                pq.push(items[i].second);
                result = min(result, 1LL * items[i].first * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}