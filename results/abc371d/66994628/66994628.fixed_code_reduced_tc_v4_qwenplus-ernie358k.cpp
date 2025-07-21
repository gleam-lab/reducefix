#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1); // Use long long to handle large numbers
    vector<long long> sum(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    
    while (q--) {
        long long l, r;
        cin >> l >> r;
        
        // Find the position in the sorted x array using binary search
        auto it_l = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        auto it_r = upper_bound(x.begin() + 1, x.end(), r) - x.begin();
        
        // Since the prefix sums are calculated for p array which corresponds to the indices of sorted x,
        // we need to adjust the indices accordingly to get the correct range sum in p array.
        cout << sum[it_r - 1] - sum[it_l - 1] << endl;
    }
    
    return 0;
}