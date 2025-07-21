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
        for (int i = 0; i < N; ++i) {
            cin >> A[i].second;
        }
        
        // Sort items by A_i in increasing order
        sort(A.begin(), A.end());
        
        // Max-heap to keep track of top K B_i values
        priority_queue<int> max_heap;
        
        int sum_B = 0;
        int min_result = 1e18; // Large enough initial value
        
        // We'll use a separate array to store the K smallest elements
        vector<int> k_smallest;
        int sum_k_smallest = 0;
        
        // First, collect K elements
        for (int i = 0; i < K - 1; ++i) {
            sum_B += A[i].second;
            max_heap.push(A[i].second);
        }
        
        // Now process rest
        for (int i = K - 1; i < N; ++i) {
            sum_B += A[i].second;
            max_heap.push(A[i].second);
            
            // Maintain only K elements
            if (max_heap.size() > K) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }
            
            min_result = min(min_result, A[i].first * sum_B);
        }
        
        cout << min_result << "\n";
    }
    
    return 0;
}