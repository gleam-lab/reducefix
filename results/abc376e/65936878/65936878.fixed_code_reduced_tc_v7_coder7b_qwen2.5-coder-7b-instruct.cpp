#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        
        // Read A and B into pairs and sort by A
        for(int i = 0; i < n; ++i) {
            cin >> v[i].f;
        }
        for(int i = 0; i < n; ++i) {
            cin >> v[i].s;
        }
        
        // Sort by A values while keeping track of original indices
        sort(v.begin(), v.end());
        
        // Calculate prefix sums of B
        vector<int> prefix_b(n + 1);
        for(int i = 0; i < n; ++i) {
            prefix_b[i + 1] = prefix_b[i] + v[i].s;
        }
        
        // Initialize variables to store the minimum result
        int min_result = LLONG_MAX;
        
        // Sliding window to find the minimum value of (max_A * sum_B)
        for(int i = 0; i <= n - k; ++i) {
            int max_a = v[i + k - 1].f; // Maximum A in the current window
            int sum_b = prefix_b[i + k] - prefix_b[i]; // Sum B in the current window
            int current_result = max_a * sum_b;
            min_result = min(min_result, current_result);
        }
        
        cout << min_result << '\n';
    }
    
    return 0;
}