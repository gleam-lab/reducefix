#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) cin >> items[i].first;
        for (int i = 0; i < n; ++i) cin >> items[i].second;
        
        // Sort by A_i in ascending order
        sort(items.begin(), items.end());
        
        // Min-heap to keep track of the K largest B_i values
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        
        // Initialize with last K elements (those with largest A_i so far)
        for (int i = n - k; i < n; ++i) {
            pq.push(items[i].second);
            sum_b += items[i].second;
        }
        
        int result = items[n - k].first * sum_b;
        
        // Slide window to the left
        for (int i = n - k - 1; i >= 0; --i) {
            // Current A[i] is now potentially part of the max(A)
            // If current B[i] is larger than smallest in our current set, replace it
            if (items[i].second > pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].second);
                sum_b += items[i].second;
            }
            // Current A value (A[i]) is now the new max in the set
            result = min(result, items[i].first * sum_b);
        }
        
        cout << result << '\n';
    }
    
    return 0;
}