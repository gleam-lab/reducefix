#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> x(n), p(n);
    
    // Read input values into vectors
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    
    // Compute prefix sums of p[]
    vector<long long> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        a[i + 1] = a[i] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Binary search to find the first index greater than or equal to l
        auto it_l = lower_bound(x.begin(), x.end(), l);
        int idx_l = distance(x.begin(), it_l);
        
        // Binary search to find the first index greater than r
        auto it_r = upper_bound(x.begin(), x.end(), r);
        int idx_r = distance(x.begin(), it_r);
        
        // Calculate the result using prefix sums
        long long result = a[idx_r] - a[idx_l];
        cout << result << endl;
    }
    
    return 0;
}