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
            A[i].second = i;
        }
        
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        
        // Sort items by A value
        sort(A.begin(), A.end());
        
        // Min-heap to keep track of top K smallest B values
        priority_queue<int, vector<int>, greater<>> pq;
        int sumB = 0;
        int result = 1e18; // Large initial value
        
        // Initialize with first K-1 elements
        for (int i = 0; i < K - 1; ++i) {
            pq.push(B[A[i].second]);
            sumB += B[A[i].second];
        }
        
        // Try each possible maximum A value from position K-1 onward
        for (int i = K - 1; i < N; ++i) {
            // Add current B value
            pq.push(B[A[i].second]);
            sumB += B[A[i].second];
            
            // Maintain only K smallest B values
            if (pq.size() > K) {
                sumB -= pq.top();
                pq.pop();
            }
            
            // Calculate the expression value
            result = min(result, A[i].first * sumB);
        }
        
        cout << result << "\n";
    }
    
    return 0;
}