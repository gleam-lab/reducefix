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
            A[i].second = i;
        }

        // Sort elements by A value
        sort(A.begin(), A.end());

        // Create new array of B values sorted by corresponding A
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second];
        }

        // Min-heap to keep track of smallest K elements
        priority_queue<int> max_heap;
        int sum = 0;
        int min_result = numeric_limits<int>::max();

        // We process elements from right to left
        // For each i, we consider A[i] as the maximum A value in the subset
        for (int i = N - 1; i >= 0; --i) {
            max_heap.push(sorted_B[i]);
            sum += sorted_B[i];

            // If we have more than K elements, remove the largest one
            if (max_heap.size() > K) {
                sum -= max_heap.top();
                max_heap.pop();
            }

            // If we have exactly K elements, calculate the cost
            if (max_heap.size() == K) {
                min_result = min(min_result, A[i].first * sum);
            }
        }

        cout << min_result << "\n";
    }

    return 0;
}