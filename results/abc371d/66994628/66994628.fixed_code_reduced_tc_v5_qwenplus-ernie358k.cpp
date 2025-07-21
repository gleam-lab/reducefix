#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1); // Using vector for better memory management and to avoid out-of-bounds issues
    vector<long long> sum(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Calculate prefix sums
    }
    
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        
        // Binary search to find the correct indices in the sorted x array
        auto it_l = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        auto it_r = upper_bound(x.begin() + 1, x.end(), r) - x.begin();
        
        // Since it_l and it_r are 0-based indices and sum array is 1-based for effective range, adjust accordingly
        // We need to subtract 1 from it_r to get the exclusive upper bound index for sum array (0-based prefix sums)
        cout << sum[it_r - 1] - sum[it_l - 1] << endl;
    }
    
    return 0;
}