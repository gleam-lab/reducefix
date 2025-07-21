#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        
        // Read input arrays
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        
        // Sort A in descending order
        sort(a.begin(), a.end(), greater<int>());
        
        // Sort B in ascending order
        sort(b.begin(), b.end());
        
        // Calculate the result
        int max_a = a[k-1];  // Get the Kth largest element in A
        int sum_b = 0;      // Sum of the K smallest elements in B
        
        for(int i = 0; i < k; ++i) sum_b += b[i];
        
        // Output the result
        cout << max_a * sum_b << '\n';
    }
    
    return 0;
}