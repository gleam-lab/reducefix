#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
        }
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Pair A with index to keep track of B values
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            items[i] = {A[i].first, i};
        }
        sort(items.begin(), items.end());

        // Maintain a max heap of size K-1
        priority_queue<int> pq;
        int sum = 0;
        int result = INF;

        for (int i = 0; i < N; ++i) {
            int currentA = items[i].first;
            int idx = items[i].second;
            int currentB = B[idx];

            // We will include this element as the max A in the subset
            // So we need to pick K-1 elements from previous ones with smallest B
            if (i >= K - 1) {
                result = min(result, currentA * (sum + currentB));
            }

            pq.push(currentB);
            sum += currentB;

            // Keep only K-1 smallest B's
            if (pq.size() >= K) {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << result << "\n";
    }

    return 0;
}