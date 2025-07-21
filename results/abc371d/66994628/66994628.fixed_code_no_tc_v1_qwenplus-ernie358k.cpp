#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1), sum(n + 1, 0);
    
    // Input x array (0-indexed for easier handling with vectors and binary search)
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    // Input p array (cumulative weights)
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Convert to 0-indexed for binary search
        auto it_l = lower_bound(x.begin() + 1, x.end(), l);
        auto it_r = upper_bound(x.begin() + 1, x.end(), r);
        
        int idx_l = it_l - x.begin();
        int idx_r = it_r - x.begin();
        
        // Since we used 0-indexed for x but 1-indexed for sum, adjust indices accordingly
        cout << sum[idx_r - 1] - sum[idx_l - 1] << endl;
    }
    
    return 0;
}