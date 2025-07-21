#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n+1), p(n+1); // Use vector for dynamic size and safety
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    // Create a copy of x to sort and use for binary search
    vector<int> sorted_x(x.begin(), x.end());
    sort(sorted_x.begin(), sorted_x.end());
    
    // Calculate prefix sums for p array
    vector<long long> sum(n+1, 0); // Use long long to avoid overflow
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        auto it_l = lower_bound(sorted_x.begin(), sorted_x.end(), l);
        auto it_r = upper_bound(sorted_x.begin(), sorted_x.end(), r);
        
        int idx_l = it_l - sorted_x.begin() + 1; // Convert to 1-based index for x array
        int idx_r = it_r - sorted_x.begin(); // Upper bound gives the next position, so no +1
        
        // Since x and p are 1-based, we don't need to adjust for zero-based array here
        cout << sum[idx_r] - sum[idx_l-1] << endl;
    }
    
    return 0;
}