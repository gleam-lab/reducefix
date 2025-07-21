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
        
        vector<pair<int, int>> A(N), B(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        
        for (int i = 0; i < N; ++i) {
            cin >> B[i].first;
        }
        
        // Sort A by increasing A_i, since we want to consider smaller max(A_i) first
        sort(A.begin(), A.end());
        
        // Create array of B values indexed by sorted A positions
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second].first;
        }
        
        // Min-heap to keep track of top K smallest B values seen so far
        priority_queue<int, vector<int>, greater<>> pq;
        
        int sum = 0;
        int result = 1e18;  // Large initial value
        
        // Initialize with first K-1 elements
        for (int i = 0; i < K - 1; ++i) {
            pq.push(sorted_B[i]);
            sum += sorted_B[i];
        }
        
        // Try all possible maximum A_i in the subset
        for (int i = K - 1; i < N; ++i) {
            // Add current B value
            pq.push(sorted_B[i]);
            sum += sorted_B[i];
            
            // If heap size exceeds K, remove the smallest element
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            
            // Calculate the product: A[i] * sum
            result = min(result, A[i].first * sum);
        }
        
        cout << result << "\n";
    }
    
    return 0;
}