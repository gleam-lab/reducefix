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
        vector<int> B(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }

        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort by A values
        sort(A.begin(), A.end());

        // Reorder B according to sorted A
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second];
        }

        priority_queue<int> max_heap; // To store K largest B values
        int sum_b = 0;
        int res = 1e18; // Start with a very large number

        for (int i = 0; i < N; ++i) {
            int b_val = sorted_B[i];
            sum_b += b_val;
            max_heap.push(b_val);

            if (max_heap.size() > K) {
                sum_b -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == K) {
                res = min(res, A[i].first * sum_b);
            }
        }

        cout << res << "\n";
    }

    return 0;
}