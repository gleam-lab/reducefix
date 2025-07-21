#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1); // Using vector for dynamic size and to avoid off-by-one errors
    vector<long long> sum(n + 1, 0); // Prefix sum array
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Calculate prefix sums
    }
    
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        
        auto it_l = lower_bound(x.begin() + 1, x.end(), l) - x.begin(); // Find the lower bound index
        auto it_r = upper_bound(x.begin() + 1, x.end(), r) - x.begin(); // Find the upper bound index
        
        // Since it_r is the first position greater than r, we subtract 1 to get the last valid index <= r
        if (it_r <= n && x[it_r] == r) {
            // If r is present in x, include it in the range
            --it_r; // upper_bound gives the next position, decrement to include r itself
            // However, since we are using sum array, we don't need this decrement if we are using sum[it_r] - sum[it_l - 1]
        } else {
            --it_r; // Otherwise, decrement to get the last valid index
        }
        
        // Ensure indices are within bounds
        if (it_l > 0 && it_r <= n) {
            cout << sum[it_r] - sum[it_l - 1] << endl;
        } else {
            cout << 0 << endl; // Or handle the error appropriately
        }
    }
    
    return 0;
}