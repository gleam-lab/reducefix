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
        
        // Sort items by A value
        sort(A.begin(), A.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
            return B[x.second].first < B[y.second].first;
        });
        
        // Build initial sum of B values
        priority_queue<int> pq;
        int sum_B = 0;
        for (int i = 0; i < K - 1; ++i) {
            sum_B += B[A[i].second].first;
            pq.push(B[A[i].second].first);
        }
        
        int min_result = 1e18;
        
        // Try each element from K-1 to N-1 as the max A_i
        for (int i = K - 1; i < N; ++i) {
            int current_A = A[i].first;
            
            // Add current B to our selection
            sum_B += B[A[i].second].first;
            pq.push(B[A[i].second].first);
            
            // Maintain only K elements in our selection
            if (pq.size() > K) {
                sum_B -= pq.top();
                pq.pop();
            }
            
            min_result = min(min_result, current_A * sum_B);
        }
        
        cout << min_result << "\n";
    }
    
    return 0;
}