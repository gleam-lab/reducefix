#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first >> A[i].second;
        }

        // Sort by A in descending order
        sort(A.begin(), A.end(), greater<pair<int, int>>());

        // Priority queue to store the top K B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_B = 0;
        long long ans = LLONG_MAX;

        // Add first K-1 B values and calculate sum_B
        for (int i = 0; i < K - 1; ++i) {
            pq.push(A[i].second);
            sum_B += A[i].second;
        }

        // Add the K-th B value and compute the result
        pq.push(A[K - 1].second);
        sum_B += A[K - 1].second;
        ans = (long long)A[K - 1].first * sum_B;

        // Process the rest of the elements
        for (int i = K; i < N; ++i) {
            sum_B -= pq.top();
            pq.pop();
            pq.push(A[i].second);
            sum_B += A[i].second;
            ans = min(ans, (long long)A[i].first * sum_B);
        }

        cout << ans << endl;
    }
    return 0;
}