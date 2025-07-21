#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> b[i].second;
            a[i].second = i;
        }
        
        // Sort by values of A in descending order
        sort(a.rbegin(), a.rend());
        
        // Use a sliding window or deque to calculate prefix sums efficiently
        vector<int> prefixSum(k + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i % k] += b[a[i].second].second;
        }
        
        // Initial minimum value is set to a large number
        long long minVal = LLONG_MAX;
        
        // Calculate the expression for each subset of size K
        for (int i = 0; i <= n - k; ++i) {
            minVal = min(minVal, (long long)a[i].first * prefixSum[i]);
        }
        
        cout << minVal << endl;
    }
    
    return 0;
}