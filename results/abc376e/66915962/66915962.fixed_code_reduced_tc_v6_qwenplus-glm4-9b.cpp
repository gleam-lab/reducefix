#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        
        // Sort A in decreasing order and B in increasing order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());
        
        priority_queue<int> maxB;
        int sumB = 0;
        
        // Calculate initial sum of B and maintain a max-heap of the first K elements of B
        for (int i = 0; i < k; i++) {
            sumB += B[i];
            maxB.push(B[i]);
        }
        
        long long ans = A[k-1] * sumB;
        
        // Now for the remaining elements in A, try to maximize the sum of B elements
        for (int i = k; i < n; i++) {
            // Remove the smallest element from B's heap, add the current element from A to B's sum
            sumB += A[i] - maxB.top();
            maxB.pop();
            maxB.push(A[i]);
            
            // Update the answer
            ans = min(ans, (long long)maxB.top() * sumB);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}