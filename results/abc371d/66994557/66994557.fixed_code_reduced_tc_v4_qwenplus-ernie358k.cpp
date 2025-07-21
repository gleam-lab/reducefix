#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1); // Use vector for better memory management and avoid out-of-bounds issues
    vector<long long> prefixSum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefixSum[i] = prefixSum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        // Use lower_bound and upper_bound to find the correct indices in the sorted array x
        auto itL = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto itR = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Since we are using 1-based indexing for x, no need to adjust itL and itR for prefixSum array which is also 1-based due to initialization
        cout << prefixSum[itR - 1] - prefixSum[itL - 1] << endl;
    }
    
    return 0;
}