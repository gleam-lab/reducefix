#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].first;
        }

        // Sort elements by A_i in increasing order
        sort(A.begin(), A.end());

        // Reorder B according to sorted A indices
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second].first;
        }

        // Max-heap to maintain the K largest B values seen so far
        priority_queue<int> max_heap;
        int sum = 0;
        int res = 1e18;

        // We will use a min-heap to simulate removal of largest elements
        // when we have more than K elements
        priority_queue<int, vector<int>, greater<>> min_heap;

        // First, take the first K-1 smallest A's and collect their B's
        for (int i = 0; i < K - 1; ++i) {
            sum += sorted_B[i];
            min_heap.push(sorted_B[i]);
        }

        // Now iterate from K-1 to N-1
        for (int i = K - 1; i < N; ++i) {
            // Add current B to heap
            sum += sorted_B[i];
            min_heap.push(sorted_B[i]);

            // Maintain only K largest B's
            if (min_heap.size() > K) {
                sum -= min_heap.top();
                min_heap.pop();
            }

            // Compute the current cost
            res = min(res, A[i].first * sum);
        }

        cout << res << "\n";
    }

    return 0;
}