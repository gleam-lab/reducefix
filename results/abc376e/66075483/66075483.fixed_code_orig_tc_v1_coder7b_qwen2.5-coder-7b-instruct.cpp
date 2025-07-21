#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        // Sort A in descending order
        sort(A.begin(), A.end(), greater<ll>());
        // Sort B in ascending order
        sort(B.begin(), B.end());
        
        // Priority queue to store the sums of subsets
        priority_queue<ll> pq;
        
        // Initialize the priority queue with the sum of the first K elements of B
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += B[i];
        }
        pq.push(sum);
        
        // Iterate through the remaining elements in B
        for (int i = k; i < n; ++i) {
            // Remove the smallest sum from the heap
            sum = pq.top();
            pq.pop();
            // Add the current element to the sum
            sum += B[i];
            // Push the new sum back into the heap
            pq.push(sum);
        }
        
        // The minimum product is the maximum sum in the heap multiplied by the maximum element in A
        ll ans = pq.top() * A[0];
        
        cout << ans << '\n';
    }
    
    return 0;
}