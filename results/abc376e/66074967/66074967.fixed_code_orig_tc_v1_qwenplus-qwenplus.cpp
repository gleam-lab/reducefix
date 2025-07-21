#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
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

        // Sort by A value
        sort(A.begin(), A.end());

        // Min heap to store B values of size up to K
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum_b = 0;
        long long result = 1e18; // Large initial value

        // Initialize with first K-1 B values (we will add one more at each step)
        for (int i = 0; i < K - 1; ++i) {
            sum_b += A[i].second;
            pq.push(A[i].second);
        }

        // Now iterate from index K-1 to N-1
        for (int i = K - 1; i < N; ++i) {
            sum_b += A[i].second;
            pq.push(A[i].second);

            // If heap size exceeds K, remove the smallest element
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Only calculate when we have exactly K elements
            if (pq.size() == K) {
                result = min(result, 1LL * A[i].first * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}