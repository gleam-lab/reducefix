#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        // Pair A[i] with B[i], and sort by A[i] ascending
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) items[i] = {A[i], B[i]};
        sort(items.begin(), items.end());

        // Min-heap to keep track of the top K smallest B[i] values
        priority_queue<int, vector<int>, greater<>> pq;
        int sumB = 0;
        int res = INF;

        // First collect K-1 smallest B's
        for (int i = 0; i < K - 1; ++i) {
            pq.push(items[i].second);
            sumB += items[i].second;
        }

        // Now iterate through rest and consider current A[i] as max(A)
        for (int i = K - 1; i < N; ++i) {
            pq.push(items[i].second);
            sumB += items[i].second;

            if (pq.size() > K) {
                sumB -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                res = min(res, items[i].first * sumB);
            }
        }

        cout << res << "\n";
    }

    return 0;
}