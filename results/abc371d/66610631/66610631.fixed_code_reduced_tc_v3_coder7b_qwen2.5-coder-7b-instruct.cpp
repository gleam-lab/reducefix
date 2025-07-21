#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 7;
long long prefix_sum[MAXN];

int main() {
    int n, q;
    cin >> n;
    
    // Read the positions of the villages
    vector<long long> positions(n);
    for(int i = 0; i < n; ++i) {
        cin >> positions[i];
    }
    
    // Read the population of each village
    vector<long long> populations(n);
    for(int i = 0; i < n; ++i) {
        cin >> populations[i];
    }
    
    // Calculate prefix sums to efficiently calculate the sum of populations in any range
    prefix_sum[0] = 0;
    for(int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + populations[i];
    }
    
    cin >> q;
    
    while(q--) {
        int left, right;
        cin >> left >> right;
        
        // Find the indices corresponding to the given positions using binary search
        auto it_left = lower_bound(positions.begin(), positions.end(), left);
        auto it_right = upper_bound(positions.begin(), positions.end(), right);
        
        int idx_left = it_left - positions.begin();
        int idx_right = it_right - positions.begin() - 1;
        
        // If the entire range lies within the valid indices, use the prefix sums directly
        if(idx_left >= 0 && idx_right < n) {
            cout << prefix_sum[idx_right + 1] - prefix_sum[idx_left] << endl;
        } else {
            // Handle edge cases where the range might be partially out of bounds
            long long result = 0;
            if(idx_left >= 0) result += prefix_sum[idx_left];
            if(idx_right < n) result += prefix_sum[n] - prefix_sum[idx_right + 1];
            cout << result << endl;
        }
    }
    
    return 0;
}