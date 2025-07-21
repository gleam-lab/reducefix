#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1), sum(n + 1, 0);
    
    // Input array x, using 1-based index for simplicity in logic
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    // Input array p and compute prefix sum array sum
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the positions of L and R in the sorted x array using binary search
        auto itL = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto itR = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Since we used 1-based indexing for x, no need to adjust indices for sum array
        // sum[itR - 1] gives the sum up to the largest index <= R
        // sum[itL - 1] gives the sum up to the largest index < L
        // Therefore, the range sum is sum[itR - 1] - sum[itL - 1]
        cout << sum[itR - 1] - sum[itL - 1] << endl;
    }
    
    return 0;
}