#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

const int INF = 1e18;

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

        // Sort A by value
        sort(A.begin(), A.end());

        // Reorder B according to the sorted indices of A
        vector<int> reordered_B(N);
        for (int i = 0; i < N; ++i) {
            reordered_B[i] = B[A[i].second].first;
        }

        priority_queue<int> max_heap;  // To maintain top K smallest B values
        int sum_b = 0;
        int res = INF;

        // Initialize with first K elements
        for (int i = 0; i < K - 1; ++i) {
            sum_b += reordered_B[i];
            max_heap.push(reordered_B[i]);
        }

        // Slide window
        for (int i = K - 1; i < N; ++i) {
            sum_b += reordered_B[i];
            max_heap.push(reordered_B[i]);

            if (max_heap.size() >= K) {
                int top = max_heap.top();
                sum_b -= top;
                max_heap.pop();
            }

            res = min(res, A[i].first * sum_b);
            // Restore current B[i] to heap and sum_b before next iteration
            max_heap.push(reordered_B[i]);
            sum_b += reordered_B[i];
        }

        cout << res << "\n";
    }

    return 0;
}