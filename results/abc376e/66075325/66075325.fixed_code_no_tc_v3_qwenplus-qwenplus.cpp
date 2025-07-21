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
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        // Pair up A[i] and B[i], then sort by A[i]
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            items[i] = {A[i], B[i]};
        }
        sort(items.begin(), items.end());

        // Min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, less<>> max_heap;
        int sum_b = 0;
        int res = INF;

        for (int i = 0; i < N; ++i) {
            int a_i = items[i].first;
            int b_i = items[i].second;

            // Keep the K largest B values among first i+1 elements
            max_heap.push(b_i);
            sum_b += b_i;

            // If we have more than K elements, remove the one with largest B
            if (max_heap.size() > K) {
                sum_b -= max_heap.top();
                max_heap.pop();
            }

            // Once we have at least K elements, compute candidate answer
            if (max_heap.size() == K) {
                res = min(res, a_i * sum_b);
            }
        }

        cout << res << "\n";
    }

    return 0;
}