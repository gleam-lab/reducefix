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
        vector<int> A(N);
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort A with indices
        vector<pair<int, int>> indexed_A(N);
        for (int i = 0; i < N; ++i) {
            indexed_A[i] = {A[i], i};
        }
        sort(indexed_A.begin(), indexed_A.end());

        // Priority queue to keep track of the sum of B over the last K elements
        priority_queue<int> max_heap;
        long long current_sum = 0;
        long long min_value = LLONG_MAX;

        for (int i = 0; i < N; ++i) {
            // Update the heap with the new element
            current_sum += B[indexed_A[i].second];
            if (max_heap.size() == K) {
                current_sum -= B[max_heap.top().second];
            }
            max_heap.push({current_sum, indexed_A[i].second});

            // If we have more than K elements, remove the oldest one
            if (max_heap.size() > K) {
                current_sum -= B[max_heap.top().second];
                max_heap.pop();
            }

            // Update the minimum value if necessary
            if (max_heap.size() == K) {
                min_value = min(min_value, (indexed_A[i].first) * max_heap.top().first);
            }
        }

        cout << min_value << endl;
    }
    return 0;
}