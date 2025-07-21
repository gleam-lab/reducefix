#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

        // Sort items by A_i in ascending order
        sort(A.begin(), A.end());

        // Min-heap to keep track of top K B_i values
        priority_queue<int, vector<int>, greater<>> min_heap;
        int sum_b = 0;
        int res = INF;

        for (int i = 0; i < N; ++i) {
            int a = A[i].first;
            int b = A[i].second;

            min_heap.push(b);
            sum_b += b;

            if (min_heap.size() > K) {
                sum_b -= min_heap.top();
                min_heap.pop();
            }

            if (min_heap.size() == K) {
                res = min(res, a * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}