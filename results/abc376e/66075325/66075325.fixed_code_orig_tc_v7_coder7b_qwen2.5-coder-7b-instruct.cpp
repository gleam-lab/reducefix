#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define int long long

int n, k, t, ans;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> A(n), B(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        // Sort arrays
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        // Priority queue for A (max heap)
        priority_queue<int> pq_A;
        // Queue for B (min heap)
        queue<int> q_B;
        
        // Initial window calculation
        for (int i = 0; i < k; ++i) {
            pq_A.push(A[i]);
            q_B.push(B[i]);
        }
        
        // Calculate initial product
        int sum_B = accumulate(q_B.begin(), q_B.end(), 0LL);
        ans = pq_A.top() * sum_B;
        
        // Sliding window
        for (int i = k; i < n; ++i) {
            pq_A.push(A[i]);
            q_B.push(B[i]);
            
            // Remove the oldest elements from the window
            pq_A.pop();
            sum_B -= q_B.front();
            q_B.pop();
            
            // Update the answer with the new product
            ans = min(ans, pq_A.top() * (sum_B + q_B.front()));
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}