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

        vector<pair<int, int>> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }

        for (int i = 0; i < N; ++i) {
            cin >> B[i].first;
        }

        // Sort A by increasing A[i]
        sort(A.begin(), A.end());

        // Map original indices to B values after sorting A
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second].first;
        }

        priority_queue<int, vector<int>, greater<>> min_heap;
        int sum_b = 0;
        int res = 1e18; // Start with a large number

        for (int i = 0; i < N; ++i) {
            if (i >= K - 1) {
                // We can form a subset of size K with A[i] as max A
                res = min(res, A[i].first * sum_b);
            }
            // Add current B to heap
            min_heap.push(sorted_B[i]);
            sum_b += sorted_B[i];

            // If heap has more than K-1 elements, remove the smallest one
            if (min_heap.size() > K - 1) {
                sum_b -= min_heap.top();
                min_heap.pop();
            }
        }

        cout << res << "\n";
    }

    return 0;
}