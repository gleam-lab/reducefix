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

        vector<pair<int, int>> A(N);  // pairs of (A_i, index)
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

        // Maintain the minimal sum of B values over any subset of size K with max A value fixed
        priority_queue<int> pq;
        int sumB = 0;
        int res = 1e18;  // large initial value

        // We iterate from the largest A to smallest, maintaining top K smallest B values
        for (int i = N - 1; i >= 0; --i) {
            int ai = A[i].first;
            int bi = B[A[i].second];

            pq.push(-bi);  // use min-heap via max-heap with negated values
            sumB += bi;

            if (pq.size() > K) {
                int removed = -pq.top();
                pq.pop();
                sumB -= removed;
            }

            if (pq.size() == K) {
                res = min(res, ai * sumB);
            }
        }

        cout << res << '\n';
    }

    return 0;
}