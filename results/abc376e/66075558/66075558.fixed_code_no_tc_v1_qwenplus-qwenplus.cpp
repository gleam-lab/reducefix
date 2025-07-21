#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Pair up A[i] and B[i], then sort by A[i]
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            items[i] = {A[i], B[i]};
        }
        sort(items.begin(), items.end());

        // Min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, less<>> maxHeap;
        int sumB = 0;
        int res = 1e18; // large initial value

        for (int i = 0; i < N; ++i) {
            int a = items[i].first;
            int b = items[i].second;

            sumB += b;
            maxHeap.push(b);

            // If more than K elements, remove the largest B so far
            if (maxHeap.size() > K) {
                sumB -= maxHeap.top();
                maxHeap.pop();
            }

            // Once we have at least K elements, compute candidate answer
            if (maxHeap.size() == K) {
                res = min(res, a * sumB);
            }
        }

        cout << res << '\n';
    }

    return 0;
}