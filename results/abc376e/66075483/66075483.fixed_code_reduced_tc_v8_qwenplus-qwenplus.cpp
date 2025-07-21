#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

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
            A[i].second = i;
        }

        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort elements by A value
        sort(A.begin(), A.end());

        int sum_B = 0;
        priority_queue<int> max_heap; // to keep track of smallest K B's

        // Initialize with first K-1 elements
        for (int i = 0; i < K - 1; ++i) {
            sum_B += B[A[i].second];
            max_heap.push(B[A[i].second]);
        }

        int result = 1LL << 60; // infinity

        // Process remaining elements
        for (int i = K - 1; i < N; ++i) {
            sum_B += B[A[i].second];
            max_heap.push(B[A[i].second]);

            // Maintain only K smallest Bs
            if (max_heap.size() > K) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }

            result = min(result, A[i].first * sum_B);
        }

        cout << result << "\n";
    }

    return 0;
}