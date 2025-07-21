#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1); // Using vector for dynamic array handling and to avoid off-by-one errors
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    // Create a prefix sum array for p
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Use lower_bound and upper_bound on the x array
        auto itL = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto itR = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Since itL and itR are zero-indexed and sum array is one-indexed, adjust accordingly
        if (itL <= n && itR <= n) {
            cout << sum[itR - 1] - sum[itL - 1] << endl;
        } else {
            // Handle edge case where no valid indices are found
            cout << 0 << endl;
        }
    }
    
    return 0;
}