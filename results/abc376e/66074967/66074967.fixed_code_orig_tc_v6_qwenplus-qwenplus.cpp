#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
        }

        for (int i = 0; i < N; ++i) {
            cin >> A[i].second;
        }

        // Sort by A[i]
        sort(A.begin(), A.end());

        // Min-heap for top K smallest B[i] values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        int res = 1e18;

        for (int i = 0; i < N; ++i) {
            pq.push(A[i].second);
            sum += A[i].second;

            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                res = min(res, A[i].first * sum);
            }
        }

        cout << res << "\n";
    }

    return 0;
}