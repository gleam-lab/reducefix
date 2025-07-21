#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
        
        vector<pair<int, int>> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].first;
        }

        // Sort A by increasing A_i
        sort(A.begin(), A.end());
        
        // Create corresponding B array in the same order as sorted A
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second].first;
        }

        // Min-heap to maintain top K smallest B values
        priority_queue<int> pq;
        int sum = 0;
        int res = INF;

        // Initialize with first K elements
        for (int i = 0; i < K; ++i) {
            sum += sorted_B[i];
            pq.push(sorted_B[i]);
        }
        if (K > 0)
            res = sum * A[K - 1].first;

        // Sliding window
        for (int i = K; i < N; ++i) {
            // Remove largest element in current window (to keep K smallest)
            if (!pq.empty() && sorted_B[i] < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += sorted_B[i];
                pq.push(sorted_B[i]);
            }
            res = min(res, sum * A[i].first);
        }

        cout << res << "\n";
    }

    return 0;
}