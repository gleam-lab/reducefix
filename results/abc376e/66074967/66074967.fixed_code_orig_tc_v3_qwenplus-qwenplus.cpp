#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first; // A[i]
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second; // B[i]
        }

        // Sort items by A[i] in ascending order
        sort(items.begin(), items.end());

        // Min-heap to keep track of top-K largest B values
        priority_queue<int, vector<int>, greater<>> pq;
        long long sum_b = 0;
        long long result = 1e18; // Start with large number

        for (int i = 0; i < N; ++i) {
            int a = items[i].first;
            int b = items[i].second;

            if (pq.size() < K) {
                pq.push(b);
                sum_b += b;
            } else {
                if (!pq.empty() && b > pq.top()) {
                    sum_b -= pq.top();
                    pq.pop();
                    pq.push(b);
                    sum_b += b;
                }
            }

            if (pq.size() == K) {
                result = min(result, a * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}