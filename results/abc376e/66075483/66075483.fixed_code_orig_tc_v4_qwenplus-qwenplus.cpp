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
        
        pair<int, int> A[N];
        int B[N];

        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }

        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort A based on A_i values
        sort(A, A + N);

        // Priority queue to store the K largest B values seen so far
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        int res = numeric_limits<int>::max();

        for (int i = 0; i < N; ++i) {
            int idx = A[i].second;
            sum_b += B[idx];
            pq.push(B[idx]);

            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                res = min(res, A[i].first * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}