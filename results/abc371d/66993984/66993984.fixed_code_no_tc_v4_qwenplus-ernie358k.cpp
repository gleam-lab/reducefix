#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1); // Use vectors for better memory management and bounds safety
    map<int, int> prefixSum; // Using map to handle sparse prefix sums
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefixSum[x[i]] += p[i]; // Directly update prefix sum based on x[i] values
    }
    
    // Since we are using a map, we don't need to precompute a contiguous prefix sum array
    // Instead, we will compute the prefix sum dynamically for any range [L, R] using the map
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the total sum for all values in range [L, R] using the map
        // We need to handle cases where L or R might not be exactly in the map keys
        auto itL = prefixSum.lower_bound(L);
        auto itR = prefixSum.upper_bound(R);
        
        // If itL points to a key greater than R, it means there are no elements in the range [L, R]
        // Thus, the result should be 0
        if (itL == prefixSum.end() || itL->first > R) {
            cout << 0 << endl;
        } else {
            int sumL = (itL == prefixSum.begin()) ? 0 : (--itL)->second; // If itL is at the beginning, sum is 0
            ++itL; // Move itL to the correct position after potential decrement for sumL
            int sumR = itR == prefixSum.end() ? 0 : itR->second - (itL == prefixSum.begin() ? 0 : (--itL)->second);
            // If itR is not end, we subtract the sum just before itL to get the range sum
            // Adjust for edge case where itL is at the start of the map
            cout << (itL->second - sumL) - (R < itR->first ? 0 : sumR) << endl;
        }
    }
    
    return 0;
}