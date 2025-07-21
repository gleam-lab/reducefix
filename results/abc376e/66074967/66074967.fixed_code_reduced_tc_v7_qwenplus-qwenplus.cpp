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
        
        // Sort elements by A value
        sort(A.begin(), A.end());
        
        // Use min-heap to keep track of smallest K B values
        priority_queue<int, vector<int>, greater<>> pq;
        int sumB = 0;
        int result = 1e18;  // Large initial value
        
        // Try each element as the max A in subset
        for (int i = 0; i < N; ++i) {
            int currentA = A[i].first;
            int idx = A[i].second;
            
            pq.push(B[idx]);
            sumB += B[idx];
            
            // If we have more than K elements, remove the smallest one
            if (pq.size() > K) {
                sumB -= pq.top();
                pq.pop();
            }
            
            // Once we have exactly K elements, compute the product
            if (pq.size() == K) {
                result = min(result, currentA * sumB);
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}