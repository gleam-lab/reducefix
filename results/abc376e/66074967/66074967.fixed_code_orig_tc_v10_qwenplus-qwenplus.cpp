#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> A[i].second;
        }

        // Sort by A in increasing order
        sort(A.begin(), A.end());

        priority_queue<int> pq;
        int sum_b = 0;
        int result = 1e18;

        for (int i = 0; i < N; ++i) {
            sum_b += A[i].second;
            pq.push(A[i].second);

            // Keep only K smallest B values
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Once we have at least K elements, compute the cost
            if (i >= K - 1) {
                result = min(result, A[i].first * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}