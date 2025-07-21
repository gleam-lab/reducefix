#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    while (Q--) {
        long long B, k;
        cin >> B >> k;

        // Priority queue to store the k smallest distances
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        for (int i = 0; i < N; ++i) {
            // Calculate the distance
            long long dist = abs(long long)(A[i] - B);

            // Only add to the priority queue if we have less than k elements
            if (pq.size() < k) {
                pq.push({dist, i});
            } else if (dist < pq.top().first) {
                // If the distance is smaller than the k-th smallest, replace it
                pq.pop();
                pq.push({dist, i});
            }
        }

        // The k-th smallest distance is now the top of the priority queue
        cout << pq.top().first << endl;
    }

    return 0;
}