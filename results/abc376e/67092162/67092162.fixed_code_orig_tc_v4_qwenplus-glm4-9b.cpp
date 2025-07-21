#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
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
        sort(A.rbegin(), A.rend()); // Sort descending by A_i

        long long min_value = LLONG_MAX;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;

        // Initial sum and max A_i from the first K elements
        for (int i = 0; i < K; ++i) {
            sum += A[i].second;
            pq.push(A[i].second);
        }
        
        long long max_A = A[0].first;
        min_value = max_A * sum;

        // Try to include each remaining element
        for (int i = K; i < N; ++i) {
            sum += A[i].second;
            pq.push(A[i].second);
            
            // Check if current sum is better
            long long new_sum = sum;
            long long new_max_A = max_A;
            while (!pq.empty() && pq.top() > max_A * K / sum) {
                new_sum -= pq.top();
                pq.pop();
            }
            new_max_A = max(max_A, new_sum / K);

            min_value = min(min_value, new_max_A * new_sum);
        }

        cout << min_value << '\n';
    }
    return 0;
}