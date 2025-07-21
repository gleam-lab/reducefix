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

        vector<pair<int, int>> items(N); // A[i], B[i]
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort by A_i in increasing order
        sort(items.begin(), items.end());

        // Min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, greater<>> maxHeap;
        int sumB = 0;
        int res = INF;

        // First, fill the heap with last K - 1 elements
        for (int i = N - 1; i >= 0; --i) {
            if (maxHeap.size() < K - 1) {
                maxHeap.push(items[i].second);
                sumB += items[i].second;
            } else {
                // We have K - 1 elements in heap
                // Consider current item as the K-th element (with max A_i)
                res = min(res, (sumB + items[i].second) * items[i].first);
                
                // Try to replace if current B is smaller than max in heap
                if (!maxHeap.empty() && items[i].second < maxHeap.top()) {
                    sumB -= maxHeap.top();
                    maxHeap.pop();
                    sumB += items[i].second;
                    maxHeap.push(items[i].second);
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}