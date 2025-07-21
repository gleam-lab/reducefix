#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1), prefixSum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefixSum[i] = prefixSum[i - 1] + p[i];
    }
    
    cin >> q;
    
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the correct indices in the sorted x array
        auto itL = lower_bound(x + 1, x + n + 1, L) - x;
        auto itR = upper_bound(x + 1, x + n + 1, R) - x - 1; // -1 because upper_bound gives the position just after the last element equal to R
        
        // Output the sum of p values for the range [L, R] in x
        cout << (itR >= itL ? prefixSum[itR] - prefixSum[itL - 1] : 0) << endl;
    }
    
    return 0;
}