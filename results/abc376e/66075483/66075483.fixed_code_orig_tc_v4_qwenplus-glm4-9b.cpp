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
        vector<pair<int, int>> A(N); // Pair of A_i and its index
        vector<int> B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first;
            cin >> B[i];
        }

        // Sort A by A_i in descending order
        sort(A.rbegin(), A.rend());

        // Calculate sum of B_i for indices in the sorted A
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += B[A[i].second - 1]; // B is 1-indexed
        }

        // Priority queue to maintain the sum of a sliding window of size K
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(sum);

        // Iterate over all possible windows of size K
        for (int i = K; i <= N; i++) {
            sum -= B[A[i - K - 1].second - 1]; // Remove the element that's sliding out of the window
            sum += B[A[i - 1].second - 1]; // Add the element that's sliding into the window
            pq.push(sum);
        }

        // The minimum value is the minimum of the sums in the priority queue
        cout << pq.top() << endl;
    }
    return 0;
}