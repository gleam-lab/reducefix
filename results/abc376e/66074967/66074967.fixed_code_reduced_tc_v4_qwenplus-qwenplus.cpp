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
        
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
        }
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Pair A[i] with B[i] and sort by A[i]
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            items[i] = {A[i].first, B[i]};
        }
        sort(items.begin(), items.end());

        // Min-heap to keep track of the K smallest B values among the largest A values
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_B = 0;
        int min_result = 1e18;  // Large initial value

        // Start from the end (largest A values)
        for (int i = N - 1; i >= 0; --i) {
            pq.push(items[i].second);
            sum_B += items[i].second;

            if (pq.size() > K) {
                sum_B -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                min_result = min(min_result, items[i].first * sum_B);
            }
        }

        cout << min_result << "\n";
    }

    return 0;
}