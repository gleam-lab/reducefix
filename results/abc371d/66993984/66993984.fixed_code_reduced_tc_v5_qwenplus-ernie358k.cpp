#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<pair<int, int>> xp(n + 1); // xp[i] = {x[i], p[i]}, using 1-based index for simplicity
    for (int i = 1; i <= n; ++i) {
        cin >> xp[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> xp[i].second;
    }
    
    // Sort the pairs based on x values
    sort(xp.begin() + 1, xp.end());
    
    // Compute prefix sums for p values
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + xp[i].second;
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Use binary search to find the positions of L and R in the sorted x array
        auto itL = lower_bound(xp.begin() + 1, xp.end(), make_pair(L, 0));
        auto itR = upper_bound(xp.begin() + 1, xp.end(), make_pair(R, numeric_limits<int>::max()));
        
        // Convert iterators to indices (since we used 1-based index for xp)
        int idxL = itL - xp.begin();
        int idxR = itR - xp.begin();
        
        // Calculate the sum of p values in the range [L, R]
        long long result = prefixSum[idxR] - prefixSum[idxL];
        
        cout << result << endl;
    }
    
    return 0;
}