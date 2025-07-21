#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1); // Use long long to handle large numbers
    map<long long, long long> prefixSum; // Use map to store prefix sums efficiently
    prefixSum[0] = 0; // Initialize prefix sum for index 0 to 0
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefixSum[x[i]] += p[i]; // Accumulate prefix sums based on x values
    }
    
    // Since we are using a map, prefix sums are automatically sorted by x values
    // No need to sort x array or use lower_bound/upper_bound on it
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        // Use auto to iterate over the map and find the correct prefix sums
        auto itL = prefixSum.lower_bound(L); // Find the first element >= L
        if (itL == prefixSum.begin() && itL->first > L) {
            // If L is smaller than the smallest key in the map, use prefix sum of 0
            cout << prefixSum[R] << endl;
        } else if (itL->first > R) {
            // If there's no element in the range [L, R], output 0
            cout << 0 << endl;
        } else {
            // Correct the iterator if it points inside but past the end of range [L, R]
            if (itL->first > L) {
                --itL; // Move to the largest key <= L
            }
            auto itR = prefixSum.upper_bound(R); // Find the first element > R
            --itR; // Move to the largest key <= R (since upper_bound gives the first element > R)
            cout << (itR->second - itL->second) << endl;
        }
    }
    
    return 0;
}