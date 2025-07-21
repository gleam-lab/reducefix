#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1), sorted_x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        sorted_x[i] = x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    // Calculate prefix sums for p
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }
    
    // Sort the x array for binary search
    sort(sorted_x.begin(), sorted_x.end());
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Use binary search to find the correct indices in sorted_x
        auto it_l = lower_bound(sorted_x.begin(), sorted_x.end(), l);
        auto it_r = upper_bound(sorted_x.begin(), sorted_x.end(), r);
        
        int index_l = it_l - sorted_x.begin() + 1; // Convert to 1-based index
        int index_r = it_r - sorted_x.begin();     // Convert to 0-based index for upper_bound result
        
        // Output the result using prefix sums
        if (index_r > index_l) {
            cout << sum[index_r] - sum[index_l - 1] << endl;
        } else {
            cout << 0 << endl; // No valid range found
        }
    }
    
    return 0;
}