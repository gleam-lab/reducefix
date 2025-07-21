#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) cin >> v[i].first;
        for(int i = 0; i < n; i++) cin >> v[i].second;
        
        // Sort pairs by A_i values
        sort(v.begin(), v.end());
        
        // Priority queue to keep track of the sum of B_i values in the current window
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        
        // Initialize the first window of size k
        for(int i = 0; i < k; i++) {
            pq.push(v[i].second);
            sum_b += v[i].second;
        }
        
        // Initialize the result with the product of max_A and sum_B for the initial window
        int ans = v[k-1].first * sum_b;
        
        // Slide the window across the array
        for(int i = k; i < n; i++) {
            // Add the new element to the window
            pq.push(v[i].second);
            sum_b += v[i].second;
            
            // Remove the oldest element from the window
            sum_b -= pq.top();
            pq.pop();
            
            // Update the result with the new product
            ans = min(ans, v[i].first * sum_b);
        }
        
        cout << ans << '\n';
    }
    return 0;
}