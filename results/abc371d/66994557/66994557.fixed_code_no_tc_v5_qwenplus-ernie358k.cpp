#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1), sum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the positions of L and R in the sorted array of x
        auto itL = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto itR = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Since we are using 1-based indexing for input, and 0-based for internal arrays,
        // we need to adjust the indices accordingly when accessing sum array.
        // Also, ensure that we don't go out of bounds by using max(0, ...)
        cout << sum[min(n, itR - 1)] - sum[max(0, itL - 1)] << endl;
    }
    
    return 0;
}