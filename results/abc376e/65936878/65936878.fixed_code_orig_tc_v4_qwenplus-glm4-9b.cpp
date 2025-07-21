#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<int>()); // Descending
    sort(B.begin(), B.end()); // Ascending
    
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    long long sumB = 0;
    
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            sumB += B[i]; // Add next k-th largest element from B
        }
        pq.push(B[i]); // Add to heap
        if (i >= k) {
            sumB -= pq.top(); // Remove the smallest element from heap
            pq.pop();
        }
        
        if (i >= k - 1) {
            // Calculate the current value of the expression
            long long current_val = (long long) A[i - k + 1] * sumB;
            if (current_val < (long long) res) {
                res = current_val;
            }
        }
    }
    
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while (t--) {
        res = LLONG_MAX;
        cout << solve() << '\n';
    }
    
    return 0;
}