#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        // Pair up A and B, then sort by A
        vector<PII> items(N);
        for (int i = 0; i < N; ++i) {
            items[i] = {A[i], B[i]};
        }
        sort(items.begin(), items.end());

        // Min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sumB = 0;
        int res = INF;

        for (int i = 0; i < N; ++i) {
            int a = items[i].first, b = items[i].second;

            // Always include current item
            pq.push(b);
            sumB += b;

            // If heap size exceeds K, remove the smallest B
            if (pq.size() > K) {
                sumB -= pq.top();
                pq.pop();
            }

            // Once we have exactly K elements, start calculating
            if (pq.size() == K) {
                res = min(res, a * sumB);
            }
        }

        cout << res << '\n';
    }

    return 0;
}