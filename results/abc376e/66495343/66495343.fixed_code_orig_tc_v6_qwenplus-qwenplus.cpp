#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second;
        }

        // Sort by A[i]
        sort(AB.begin(), AB.end());

        // Min-heap to store B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        int res = numeric_limits<int>::max();

        for (int i = 0; i < N; ++i) {
            int a = AB[i].first;
            int b = AB[i].second;

            if (pq.size() < K) {
                sum_b += b;
                pq.push(b);
            } else {
                if (b > pq.top()) {
                    sum_b -= pq.top();
                    pq.pop();
                    sum_b += b;
                    pq.push(b);
                }
            }

            if (pq.size() == K) {
                res = min(res, a * sum_b);
            }
        }

        cout << res << "\n";
    }

    return 0;
}