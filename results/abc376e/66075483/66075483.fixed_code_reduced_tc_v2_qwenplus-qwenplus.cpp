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
        
        // Combine A and B for sorting
        for (int i = 0; i < N; ++i) {
            A[i].second = B[i];
        }
        
        // Sort by A values ascending
        sort(A.begin(), A.end());
        
        // Min-heap to keep track of top K smallest B values
        priority_queue<int> max_heap;
        int sum_B = 0;
        int result = 1e18; // Large enough initial value
        
        // Try including the i-th element as the maximum A
        for (int i = 0; i < N; ++i) {
            // Current A is A[i].first, add corresponding B
            max_heap.push(A[i].second);
            sum_B += A[i].second;
            
            // If we have more than K elements in our set, remove the one with largest B
            if (max_heap.size() > K) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }
            
            // If we have exactly K elements, compute the score
            if (max_heap.size() == K) {
                result = min(result, A[i].first * sum_B);
            }
        }
        
        cout << result << '\n';
    }

    return 0;
}