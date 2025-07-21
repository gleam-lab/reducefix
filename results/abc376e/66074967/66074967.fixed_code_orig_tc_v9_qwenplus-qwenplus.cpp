#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int32_t main() {
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
            B[i].second = i;
        }

        // Sort A by value to process increasing max(A_i)
        sort(A.begin(), A.end());

        // Create mapping from original index to B_i
        vector<int> b(N);
        for (int i = 0; i < N; ++i) {
            b[A[i].second] = B[i].first;
        }

        multiset<int> smallest_k;
        int sum = 0;
        int res = INF;

        // We maintain a multiset of the K smallest B values seen so far
        for (int i = 0; i < N; ++i) {
            // Add current B value to the set
            if (smallest_k.size() < K) {
                sum += b[A[i].second];
                smallest_k.insert(b[A[i].second]);
                
                // If we have exactly K elements, compute cost
                if (smallest_k.size() == K) {
                    res = min(res, sum * A[i].first);
                }
            } else {
                // Compare with largest in set
                if (b[A[i].second] < *prev(smallest_k.end())) {
                    sum -= *prev(smallest_k.end());
                    sum += b[A[i].second];
                    smallest_k.erase(prev(smallest_k.end()));
                    smallest_k.insert(b[A[i].second]);
                }
                res = min(res, sum * A[i].first);
            }
        }

        cout << res << '\n';
    }

    return 0;
}