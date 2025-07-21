#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n + 1), p(n + 1); // Use vector for dynamic array handling and +1 for 1-based indexing convenience
    map<int, int> pos; // To store the position of each element in x for fast look-up
    vector<long long> prefixSum(n + 1, 0); // Use long long to avoid overflow
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        pos[x[i]] = i; // Store the position of x[i]
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefixSum[i] = prefixSum[i - 1] + p[i]; // Calculate prefix sums
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Find the first position >= L in x
        auto itL = pos.lower_bound(L);
        int start = (itL != pos.end()) ? itL->second : n + 1; // If not found, use n+1 (out of range)
        
        // Find the first position > R in x
        auto itR = pos.upper_bound(R);
        int end = (itR != pos.begin()) ? (--itR)->second : 0; // If not found, use 0 (start of range)
        
        // Output the sum of p values between these indices (exclusive of end)
        cout << (prefixSum[end] - prefixSum[start - 1]) << endl;
    }
    
    return 0;
}