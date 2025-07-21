#include <bits/stdc++.h>
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

        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            AB[i] = {A[i], B[i]};
        }

        // Sort by A[i] ascending
        sort(AB.begin(), AB.end());

        // Min-heap to store B values of selected K elements
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        int res = numeric_limits<int>::max();

        for (int i = 0; i < N; ++i) {
            if (pq.size() >= K) {
                // Remove the smallest B value to make room
                sum_b -= pq.top();
                pq.pop();
            }

            pq.push(AB[i].second);
            sum_b += AB[i].second;

            if (pq.size() == K) {
                // The current A is the largest in the window due to sorting
                res = min(res, AB[i].first * sum_b);
            }
        }

        cout << res << "\n";
    }

    return 0;
}