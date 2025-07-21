#include <bits/stdc++.h>
using namespace std;

int n, q;
long long x[200005], p[200005];
vector<long long> sorted_x;
long long prefix_sum[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sorted_x.push_back(x[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(sorted_x.begin(), sorted_x.end());
    
    // Compute prefix sums for array p
    prefix_sum[0] = p[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        // Use binary search to find the correct indices in sorted_x
        auto it_L = lower_bound(sorted_x.begin(), sorted_x.end(), L);
        auto it_R = upper_bound(sorted_x.begin(), sorted_x.end(), R);
        
        int idx_L = it_L - sorted_x.begin();
        int idx_R = it_R - sorted_x.begin();
        
        // Handle edge case where upper_bound goes out of bounds
        if (idx_R == n) idx_R = n - 1;
        
        // Output the sum of p from idx_L to idx_R-1 (0-based indexing)
        cout << prefix_sum[idx_R - 1] - (idx_L == 0 ? 0 : prefix_sum[idx_L - 1]) << endl;
    }
    
    return 0;
}