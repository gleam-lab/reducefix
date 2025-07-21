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
        vector<pair<int, int>> A(N); // A_i and index
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort elements by A_i in increasing order
        sort(A.begin(), A.end());

        // Create array of B values corresponding to sorted A
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second];
        }

        // Max-heap to store the K smallest B values among the largest A values
        priority_queue<int> max_heap;

        int sum_B = 0;
        int result = INF;

        // Start from the K-th element so we can always pick K items
        for (int i = N - 1; i >= 0; --i) {
            max_heap.push(sorted_B[i]);
            sum_B += sorted_B[i];

            if (max_heap.size() > K) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == K) {
                result = min(result, sum_B * A[i].first);
            }
        }

        cout << result << "\n";
    }

    return 0;
}